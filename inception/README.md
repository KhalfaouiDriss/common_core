*This project has been created as part of the 42 curriculum by habdella.*

# Inception

<p align="center">
  <img src="https://img.shields.io/badge/Docker-2496ED?style=for-the-badge&logo=docker&logoColor=white" alt="Docker"/>
  <img src="https://img.shields.io/badge/Debian-A81D33?style=for-the-badge&logo=debian&logoColor=white" alt="Debian"/>
  <img src="https://img.shields.io/badge/NGINX-009639?style=for-the-badge&logo=nginx&logoColor=white" alt="NGINX"/>
  <img src="https://img.shields.io/badge/WordPress-21759B?style=for-the-badge&logo=wordpress&logoColor=white" alt="WordPress"/>
  <img src="https://img.shields.io/badge/MariaDB-003545?style=for-the-badge&logo=mariadb&logoColor=white" alt="MariaDB"/>
  <img src="https://img.shields.io/badge/Redis-DC382D?style=for-the-badge&logo=redis&logoColor=white" alt="Redis"/>
</p>

## Description

**Inception** is a system administration project that introduces the world of containerization using **Docker**. The goal is to set up a small infrastructure composed of different services running in isolated containers, all orchestrated using Docker Compose.

This project implements a complete **LEMP stack** (Linux, Nginx, MariaDB, PHP) to host a WordPress website, along with several bonus services for enhanced functionality.

---

## Architecture

```
                        ┌─────────────────────────────────────────────────────────────────┐
                        │                    Docker Network (inception)                   │
                        │                                                                 │
   ┌──────────┐         │  ┌─────────┐    ┌─────────────┐    ┌─────────┐    ┌─────────┐   │
   │  Client  │───443───┼─▶│  NGINX  │───▶│  WORDPRESS  │───▶│ MARIADB │◀───│ ADMINER │   │
   │ (Browser)│  HTTPS  │  │  (TLS)  │9000│  (PHP-FPM)  │3306│  (MySQL)│    │ (:8080) │   │
   └──────────┘         │  └─────────┘    └──────┬──────┘    └─────────┘    └─────────┘   │
                        │                        │                                        │
                        │                        ▼                                        │
                        │  ┌─────────┐    ┌─────────────┐    ┌─────────┐    ┌─────────┐   │
                        │  │  FTP    │───▶│  WordPress  │    │  REDIS  │    │ MAILHOG │   │
                        │  │ (:21)   │    │   Volume    │    │ (:6379) │    │ (:8025) │   │
                        │  └─────────┘    └─────────────┘    └─────────┘    └─────────┘   │
                        │                                                                 │
                        │                      ┌───────────────┐                          │
                        │                      │ STATIC WEBSITE│                          │
                        │                      │    (:9999)    │                          │
                        │                      └───────────────┘                          │
                        └─────────────────────────────────────────────────────────────────┘
```

---

## Services Overview

### Mandatory Services

| Service | Description | Port | Base Image |
|---------|-------------|------|------------|
| **NGINX** | Reverse proxy with TLSv1.2/TLSv1.3 | 443 | debian:bookworm-slim |
| **WordPress** | CMS with PHP-FPM 8.2 | 9000 (internal) | debian:bookworm-slim |
| **MariaDB** | MySQL-compatible database | 3306 (internal) | debian:bookworm-slim |

### Bonus Services

| Service | Description | Port | Base Image |
|---------|-------------|------|------------|
| **Redis** | In-memory cache for WordPress | 6379 | debian:bookworm-slim |
| **Adminer** | Lightweight database management UI | 8080 | debian:bookworm-slim |
| **FTP** | VSFTPD server for file transfers | 21, 20, 30000-30009 | debian:bookworm-slim |
| **MailHog** | Email testing tool (SMTP capture) | 8025 (UI), 1025 (SMTP) | debian:bookworm-slim |
| **Static Website** | Custom PHP-based portfolio site | 9999 | debian:bookworm-slim |

---

## Instructions

### Prerequisites
- Docker and Docker Compose installed
- `make` utility
- Root/sudo access (for modifying `/etc/hosts`)

### Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/FukaiKoda/INCEPTION.git
   cd INCEPTION
   ```

2. **Create the environment file:**
   ```bash
   cp srcs/.env.example srcs/.env
   # Edit srcs/.env with your credentials
   ```

   Required environment variables:
   ```env
   # Database
   DB_DATABASE=wordpress
   DB_USER=wp_user
   DB_PASSWORD=your_secure_password
   DB_ROOT_PASSWORD=your_root_password
   DB_HOST=mariadb

   # WordPress
   DOMAIN_NAME=habdella.42.fr
   WEBSITE_TITLE=Inception

   # Admin User
   ADMIN_USERNAME=admin
   ADMIN_PASSWORD=admin_password
   ADMIN_EMAIL=admin@example.com

   # Regular User
   USER_NAME=editor
   USER_EMAIL=editor@example.com
   USER_PASSWORD=editor_password
   ```

3. **Add the domain to your hosts file:**
   ```bash
   echo "127.0.0.1 habdella.42.fr" | sudo tee -a /etc/hosts
   ```

4. **Build and run the containers:**
   ```bash
   make
   ```

5. **Access the services:**

   | Service | URL |
   |---------|-----|
   | WordPress | https://habdella.42.fr |
   | Adminer | http://localhost:8080 |
   | MailHog | http://localhost:8025 |
   | Static Website | http://localhost:9999 |

   > ⚠️ The SSL certificate is self-signed. Accept the browser warning to proceed.

### Available Commands

| Command | Description |
|---------|-------------|
| `make` or `make all` | Build and start all containers |
| `make up` | Start existing containers |
| `make stop` | Stop containers without removing |
| `make down` | Stop and remove containers |
| `make clean` | Remove containers and Networks, Volumes preserved|
| `make fclean` | Full cleanup (containers, images, volumes, data) |
| `make re` | Rebuild everything from scratch |

---

## Project Description

### Docker Usage

This project uses Docker to containerize each service independently:

- **Custom Dockerfiles**: Each service has its own Dockerfile based on `debian:bookworm-slim`
- **Docker Compose**: Orchestrates all services, networks, and volumes
- **Entrypoint Scripts**: Each container has a startup script for initialization

### Design Choices

1. **Debian Bookworm Slim** - Minimal base image for smaller container sizes
2. **PHP-FPM** - Efficient PHP process management for WordPress
3. **WP-CLI** - Automated WordPress installation without manual setup
4. **Self-signed SSL** - Generated at container startup for HTTPS

---

## Technical Comparisons

### Virtual Machines vs Docker

| Aspect | Virtual Machines | Docker Containers |
|--------|------------------|-------------------|
| **Isolation** | Full OS isolation with hypervisor | Process-level isolation sharing host kernel |
| **Resource Usage** | Heavy (GB of RAM per VM) | Lightweight (MB of RAM per container) |
| **Startup Time** | Minutes | Seconds |
| **Portability** | Less portable, larger images | Highly portable, smaller images |
| **Use Case** | Running different OS, full isolation | Microservices, rapid deployment |

**Choice for Inception**: Docker was chosen for its lightweight nature, fast startup, and ease of orchestration with Docker Compose.

---

### Secrets vs Environment Variables

| Aspect | Secrets | Environment Variables |
|--------|---------|----------------------|
| **Security** | Encrypted at rest, limited access | Plain text, visible in process list |
| **Management** | Managed by orchestrator (Swarm/K8s) | Defined in `.env` files or compose |
| **Access** | Mounted as files in `/run/secrets/` | Available via `$VAR_NAME` |
| **Rotation** | Can be rotated without restart | Requires container restart |

**Choice for Inception**: Environment variables via `.env` file for simplicity. In production, Docker Secrets or external secret managers (Vault) should be used.

> ⚠️ **Security Note**: The `.env` file should never be committed to Git. Add it to `.gitignore`.

---

### Docker Network vs Host Network

| Aspect | Docker Network (Bridge) | Host Network |
|--------|------------------------|--------------|
| **Isolation** | Containers isolated from host | Containers share host's network |
| **Port Mapping** | Explicit port exposure required | Uses host ports directly |
| **Security** | Better isolation, controlled access | Less secure, potential port conflicts |
| **Performance** | Slight overhead | Native performance |
| **Service Discovery** | Container names as DNS | Must use localhost/IP |

**Choice for Inception**: Custom bridge network (`inception`) for:
- Service isolation from the host
- Container-to-container DNS resolution (e.g., `wordpress` can reach `mariadb` by name)
- Only port 443 exposed to the outside world

---

### Docker Volumes vs Bind Mounts

| Aspect | Docker Volumes | Bind Mounts |
|--------|---------------|-------------|
| **Management** | Managed by Docker | User-managed host paths |
| **Location** | `/var/lib/docker/volumes/` | Any host directory |
| **Portability** | More portable across systems | Depends on host structure |
| **Backup** | Via Docker commands | Direct file access |
| **Performance** | Optimized for Docker | Native file system |

**Choice for Inception**: Bind mounts with `driver_opts` pointing to `/home/${USER}/data/`:
- Easy access to data for debugging
- Simple backup and inspection
- Persistence across container rebuilds
- Required by 42 project specifications

---

## Resources

### Official Documentation

- [Docker Documentation](https://docs.docker.com/)
- [Docker Compose Documentation](https://docs.docker.com/compose/)
- [NGINX Documentation](https://nginx.org/en/docs/)
- [MariaDB Documentation](https://mariadb.com/kb/en/documentation/)
- [WordPress Developer Resources](https://developer.wordpress.org/)
- [WP-CLI Documentation](https://wp-cli.org/)
- [Redis Documentation](https://redis.io/documentation)
- [VSFTPD Manual](https://security.appspot.com/vsftpd.html)
- [MailHog GitHub](https://github.com/mailhog/MailHog)

### Tutorials & Articles

- [Docker for Beginners](https://docker-curriculum.com/)
- [Understanding Docker Networking](https://docs.docker.com/network/)
- [PHP-FPM Configuration](https://www.php.net/manual/en/install.fpm.configuration.php)
- [SSL/TLS Best Practices](https://ssl-config.mozilla.org/)

### AI Usage Disclosure

AI assistance (Claude / GPT-4) was used in this project for:

- **Documentation**: Generating README structure and content.
- **Debugging**: Troubleshooting services configuration issues.
- **Learning**: Understanding Docker concepts and best practices.
- **Code Review**: Identifying some issues in Dockerfiles and scripts.
- **Static Website**: Help creating the bonus static website design.

**AI** was used as a **learning tool**, not as a code generator.

---

## Project Structure

```
INCEPTION/
├── Makefile                          # Build automation
├── README.md                         # This file
└── srcs/
    ├── .env                          # Environment variables (not in git)
    ├── docker-compose.yml            # Service orchestration
    └── requirements/
        ├── mariadb/
        │   ├── Dockerfile            # MariaDB container
        │   └── tools/
        │       └── script.sh         # Database initialization
        ├── nginx/
        │   ├── Dockerfile            # NGINX container
        │   ├── conf/
        │   │   └── nginx.conf        # Server configuration
        │   └── tools/
        │       └── script.sh         # SSL generation & startup
        ├── wordpress/
        │   ├── Dockerfile            # WordPress container
        │   ├── conf/
        │   │   └── www.conf          # PHP-FPM pool config
        │   └── tools/
        │       └── script.sh         # WP installation script
        └── bonus/
            ├── adminer/
            │   └── Dockerfile        # Adminer DB management
            ├── ftp/
            │   ├── Dockerfile        # VSFTPD server
            │   └── tools/
            │       └── script.sh     # FTP setup script
            ├── mailhog/
            │   └── Dockerfile        # Email testing tool
            ├── redis/
            │   ├── Dockerfile        # Redis cache server
            │   └── conf/
            │       └── redis.conf    # Redis configuration
            └── static_website/
                ├── Dockerfile        # Static site server
                └── app/
                    ├── index.html    # Landing page
                    ├── global.css    # Styles
                    └── script.js     # Interactivity
```

---

## Bonus Services Details

### Redis Cache

Redis provides in-memory caching for WordPress, significantly improving page load times and reducing database queries.

**Configuration:**
- Protected mode disabled for container network access
- Persistent storage can be configured if needed

### Adminer

A lightweight, single-file PHP database management tool. Alternative to phpMyAdmin with a cleaner interface.

**Access:** `http://localhost:8080`
- Server: `mariadb`
- Username: From your `.env` file (DB_USER)
- Password: From your `.env` file (DB_PASSWORD)
- Database: `wordpress`

### FTP Server (VSFTPD)

Provides FTP access to the WordPress files for easy file management.

**Connection:**
- Host: `localhost`
- Port: `21`
- User/Pass: From your `.env` file (FTP_USER, FTP_PASS)
- Mode: Passive (ports 30000-30009)

### MailHog

Captures all outgoing emails from WordPress for testing purposes. No emails are actually sent externally.

**Access:**
- Web UI: `http://localhost:8025`
- SMTP: `localhost:1025`

### Static Website

A custom-built portfolio/landing page showcasing the Inception project with:
- Animated starfield background
- Interactive service dashboard
- Architecture visualization
- Responsive design

**Access:** `http://localhost:9999`

---

## Security Features

- ✅ **TLSv1.2/TLSv1.3 only** - Modern encryption protocols
- ✅ **Self-signed SSL certificates** - Generated at container startup
- ✅ **PHP upload restrictions** - Blocks PHP execution in uploads folder
- ✅ **Protected sensitive files** - Denies access to `.env`, `.git`, `wp-config.php`
- ✅ **Network isolation** - Services communicate only within Docker network

---

## Troubleshooting

### Common Issues

**403 Forbidden from NGINX**
- WordPress files might not be downloaded yet
- Check if WordPress container is waiting for MariaDB: `docker logs wordpress`
- Ensure MariaDB user has correct permissions

**SSL Certificate Errors**
- Check if the certificate was generated: `docker exec nginx ls -la /etc/nginx/ssl/`
- Verify openssl command in nginx script

**Database Connection Failed**
- Verify `.env` file has correct `DB_HOST=mariadb`
- Check if MariaDB is running: `docker ps`
- Test connection: `docker exec wordpress mariadb-admin ping -h mariadb`

**Container Keeps Restarting**
- Check logs: `docker logs <container_name>`
- Verify script permissions and syntax

---

## License

This project is part of the 42 School curriculum. Feel free to use it as a reference for learning purposes.

---

<p align="center">
  Made by <strong>habdella</strong> @ 1337
</p>
