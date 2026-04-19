# Developer Documentation

This document describes how to set up, build, and manage the Inception infrastructure as a developer.

---

## Table of Contents

1. [Environment Setup](#environment-setup)
2. [Building and Launching](#building-and-launching)
3. [Container and Volume Management](#container-and-volume-management)
4. [Data Storage and Persistence](#data-storage-and-persistence)

---

## Environment Setup

### Prerequisites

Ensure the following are installed on your system:

| Requirement | Version | Check Command |
|-------------|---------|---------------|
| Docker | 20.10+ | `docker --version` |
| Docker Compose | 2.0+ | `docker compose version` |
| Make | Any | `make --version` |
| Git | Any | `git --version` |

**Install on Debian/Ubuntu:**
```bash
sudo apt update
sudo apt install docker.io docker-compose-v2 make git
sudo usermod -aG docker $USER
# Log out and back in for group changes to take effect
```

### Clone the Repository

```bash
git clone https://github.com/FukaiKoda/INCEPTION.git
cd INCEPTION
```

### Configuration Files

#### Environment File (.env)

Create the environment file with your credentials:

```bash
cp srcs/.env.example srcs/.env   # If example exists
# OR create manually:
nano srcs/.env
```

**Required variables:**

```env
### WORDPRESS ENVIRONMENT VARIABLES ###
DOMAIN_NAME=habdella.42.fr
WEBSITE_TITLE=INCEPTION

ADMIN_USERNAME=your_admin_user
ADMIN_PASSWORD=your_secure_password
ADMIN_EMAIL=admin@example.com

USER_NAME=editor
USER_PASSWORD=editor_password
USER_EMAIL=editor@example.com

### DATABASE ENVIRONMENT VARIABLES ###
DB_DATABASE=wordpress
DB_HOST=mariadb
DB_USER=wp_user
DB_PASSWORD=your_db_password
DB_ROOT_PASSWORD=your_root_password

### FTP ENVIRONMENT VARIABLES ###
FTP_USER=ftpuser
FTP_PASS=ftp_password
```

> ⚠️ **Security:** Add `srcs/.env` to `.gitignore` to prevent committing secrets.

#### Hosts File

Add the domain to your local hosts file:

```bash
echo "127.0.0.1 habdella.42.fr" | sudo tee -a /etc/hosts
```

### Project Structure

```
INCEPTION/
├── Makefile                          # Build automation
├── README.md                         # Project overview
├── USER_DOC.md                       # User documentation
├── DEV_DOC.md                        # This file
└── srcs/
    ├── .env                          # Environment variables (create this)
    ├── docker-compose.yml            # Service orchestration
    └── requirements/
        ├── mariadb/                  # Database service
        │   ├── Dockerfile
        │   └── tools/script.sh
        ├── nginx/                    # Web server
        │   ├── Dockerfile
        │   ├── conf/nginx.conf
        │   └── tools/script.sh
        ├── wordpress/                # CMS
        │   ├── Dockerfile
        │   ├── conf/www.conf
        │   └── tools/script.sh
        └── bonus/
            ├── adminer/              # DB management UI
            ├── ftp/                  # FTP server
            ├── mailhog/              # Email testing
            ├── redis/                # Cache server
            └── static_website/       # Static page
```

---

## Building and Launching

### Makefile Commands

| Command | Description |
|---------|-------------|
| `make` or `make all` | Create data directories, build images, and start containers |
| `make up` | Start existing containers without rebuilding |
| `make stop` | Stop containers without removing them |
| `make down` | Stop and remove containers (preserves volumes) |
| `make clean` | Remove Containers, Networks, and orphans (preserves volumes) |
| `make fclean` | Full cleanup: containers, images, volumes, and data |
| `make re` | Full rebuild: `fclean` followed by `all` |

### Build Process

**Initial build:**
```bash
make
```

This executes:
1. `data_depend` - Creates `/home/$USER/data/mariadb` and `/home/$USER/data/wordpress`
2. `docker compose up --build -d` - Builds and starts all services

**Rebuild a specific service:**
```bash
docker compose -f srcs/docker-compose.yml build <service_name>
docker compose -f srcs/docker-compose.yml up -d <service_name>
```

**Example - rebuild WordPress:**
```bash
docker compose -f srcs/docker-compose.yml up --build -d wordpress
```

### Docker Compose Commands

**Direct compose commands (from project root):**

```bash
# Build all images
docker compose -f srcs/docker-compose.yml build

# Start all services
docker compose -f srcs/docker-compose.yml up -d

# View running services
docker compose -f srcs/docker-compose.yml ps

# View logs
docker compose -f srcs/docker-compose.yml logs -f

# Stop all services
docker compose -f srcs/docker-compose.yml down
```

---

## Container and Volume Management

### Container Commands

**List all containers:**
```bash
docker ps -a
```

**Execute command in container:**
```bash
docker exec -it <container_name> <command>

# Examples:
docker exec -it wordpress bash
docker exec -it mariadb mariadb -u root -p
docker exec -it redis redis-cli
```

**View container logs:**
```bash
docker logs <container_name>
docker logs -f <container_name>    # Follow mode
docker logs --tail 50 <container_name>  # Last 50 lines
```

**Restart a container:**
```bash
docker restart <container_name>
```

**Stop a container:**
```bash
docker stop <container_name>
```

**Remove a container:**
```bash
docker rm <container_name>
```

### Volume Commands

**List volumes:**
```bash
docker volume ls
```

**Inspect a volume:**
```bash
docker volume inspect <volume_name>
```

**Remove a volume:**
```bash
docker volume rm <volume_name>
```

> ⚠️ **Warning:** Removing volumes deletes all data stored in them.

### Network Commands

**List networks:**
```bash
docker network ls
```

**Inspect the inception network:**
```bash
docker network inspect srcs_inception
```

**View container IPs:**
```bash
docker network inspect srcs_inception --format='{{range .Containers}}{{.Name}}: {{.IPv4Address}}{{"\n"}}{{end}}'
```

### Image Management

**List images:**
```bash
docker images
```

**Remove an image:**
```bash
docker rmi <image_name>
```

**Remove all unused images:**
```bash
docker image prune -a
```

---

## Data Storage and Persistence

### Data Locations

| Data Type | Container Path | Host Path |
|-----------|----------------|-----------|
| WordPress files | `/var/www/html` | `/home/$USER/data/wordpress` |
| MariaDB database | `/var/lib/mysql` | `/home/$USER/data/mariadb` |

### Volume Configuration

Volumes are defined in `srcs/docker-compose.yml`:

```yaml
volumes:
  mariadb:
    name: mariadb
    driver: local
    driver_opts:
      type: "none"
      o: "bind"
      device: "/home/${USER}/data/mariadb"

  wordpress:
    name: wordpress
    driver: local
    driver_opts:
      type: "none"
      o: "bind"
      device: "/home/${USER}/data/wordpress"
```

These are **bind mounts** - the data is stored directly on the host filesystem.

### Accessing Persistent Data

**WordPress files:**
```bash
ls -la /home/$USER/data/wordpress/
```

**MariaDB data:**
```bash
ls -la /home/$USER/data/mariadb/
```

### Backup Procedures

**Backup WordPress files:**
```bash
tar -czvf wordpress_backup.tar.gz /home/$USER/data/wordpress/
```

**Backup database:**
```bash
docker exec mariadb mariadb-dump -u root -p"$DB_ROOT_PASSWORD" wordpress > wordpress_db_backup.sql
```

**Restore database:**
```bash
docker exec -i mariadb mariadb -u root -p"$DB_ROOT_PASSWORD" wordpress < wordpress_db_backup.sql
```

### Data Persistence Behavior

| Action | WordPress Files | Database |
|--------|-----------------|----------|
| `make stop` | ✅ Preserved | ✅ Preserved |
| `make down` | ✅ Preserved | ✅ Preserved |
| `make clean` | ❌ Deleted (volumes removed) | ❌ Deleted |
| `make fclean` | ❌ Deleted | ❌ Deleted |
| Container restart | ✅ Preserved | ✅ Preserved |

### Initialization Scripts

Each service has an initialization script that runs on first boot:

| Service | Script | Trigger |
|---------|--------|---------|
| MariaDB | `tools/script.sh` | Checks for `/var/lib/mysql/mysql` directory |
| WordPress | `tools/script.sh` | Checks for `/var/www/html/wp-config.php` file |
| NGINX | `tools/script.sh` | Generates SSL certificates on every start |
| FTP | `tools/script.sh` | Creates user and config on every start |

**To reinitialize a service:**
1. Stop containers: `make down`
2. Delete the relevant data directory
3. Restart: `make`

---

## Development Tips

### Debugging

**Check container health:**
```bash
docker inspect --format='{{.State.Health.Status}}' <container_name>
```

**View real-time resource usage:**
```bash
docker stats
```

**Enter a container shell:**
```bash
docker exec -it <container_name> /bin/bash
# or for Alpine-based images:
docker exec -it <container_name> /bin/sh
```

### Testing Changes

1. Modify Dockerfile or scripts
2. Rebuild specific service:
   ```bash
   docker compose -f srcs/docker-compose.yml up --build -d <service>
   ```
3. Check logs for errors:
   ```bash
   docker logs <service>
   ```

### Common Development Tasks

**Reset WordPress installation:**
```bash
sudo rm -rf /home/$USER/data/wordpress/*
docker restart wordpress
```

**Reset database:**
```bash
sudo rm -rf /home/$USER/data/mariadb/*
docker restart mariadb wordpress
```

**Test Redis connection:**
```bash
docker exec wordpress wp redis status --allow-root
```

**Check WordPress plugins:**
```bash
docker exec wordpress wp plugin list --allow-root
```

---

For user documentation, see [USER_DOC.md](USER_DOC.md).
