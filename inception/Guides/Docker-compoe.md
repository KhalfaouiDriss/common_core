break down the `docker-compose.yml` **line by line**

---

## 📄 docker-compose.yml — Full Line by Line

### Line 1
```yaml
version: '3.8'
```
This tells Docker Compose **which syntax version** to use. Version `3.8` supports all modern features like named volumes, custom networks, and `depends_on`. Think of it as the "language version" of the file.

---

### The Networks Block
```yaml
networks:
  inception:
    driver: bridge
```
- `networks:` — declares all custom networks used in this project
- `inception:` — the name of our network (you choose the name)
- `driver: bridge` — creates an **isolated virtual network** on your machine. Containers inside it can talk to each other, but are isolated from outside. Bridge is the default and most common driver.

> 💡 **Evaluator question:** *"Why do you use a custom network instead of the default one?"*
> **Answer:** To have full control and isolation. Also, the subject **forbids** using `--link` or `network: host`, so a custom bridge network is the correct approach. It also enables Docker's **internal DNS**, so containers find each other by name.

---

### The Volumes Block
```yaml
volumes:
  db_data:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: /home/yourlogin/data/mariadb

  wp_data:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: /home/yourlogin/data/wordpress
```

- `volumes:` — declares all persistent storage used in the project
- `db_data:` and `wp_data:` — names you give to each volume
- `driver: local` — the volume is stored **on the local machine** (not remote)
- `driver_opts:` — extra options to customize how the volume works
- `type: none` — no special filesystem type, just a plain directory
- `o: bind` — this is a **bind mount**, meaning it links a real folder on your VM to the container
- `device: /home/yourlogin/data/mariadb` — the **actual folder on your VM** that the volume points to

> 💡 **Evaluator question:** *"Why do you need volumes?"*
> **Answer:** Without volumes, all data inside a container is **lost when it stops**. Volumes make the database and WordPress files **persist** even if containers are recreated.

> 💡 **Evaluator question:** *"What's the difference between a volume and a bind mount?"*
> **Answer:** A regular Docker volume is managed by Docker internally. A bind mount (what we use here with `o: bind`) links directly to a specific folder on the host machine, giving you more control over where data lives — which the 42 subject requires.

---

### The MariaDB Service
```yaml
services:

  mariadb:
    build: ./requirements/mariadb
    container_name: mariadb
    env_file: .env
    volumes:
      - db_data:/var/lib/mysql
    networks:
      - inception
    restart: always
```

- `services:` — where you define all your containers
- `mariadb:` — the service name (also becomes the **hostname** on the network)
- `build: ./requirements/mariadb` — tells Docker to **build the image** from the Dockerfile inside that folder (no pulling from Docker Hub)
- `container_name: mariadb` — forces the container to have exactly this name, which is also how other containers reach it (DNS)
- `env_file: .env` — loads all variables from `.env` file into the container's environment
- `volumes: - db_data:/var/lib/mysql` — mounts the `db_data` volume to `/var/lib/mysql`, which is where MariaDB **stores all database files**
- `networks: - inception` — connects this container to the `inception` network
- `restart: always` — if the container crashes or the VM reboots, Docker **automatically restarts** it

> 💡 **Evaluator question:** *"Why /var/lib/mysql specifically?"*
> **Answer:** That's the default directory where MariaDB stores all its data files. By mounting a volume there, we make sure the database survives container restarts.

---

### The WordPress Service
```yaml
  wordpress:
    build: ./requirements/wordpress
    container_name: wordpress
    env_file: .env
    volumes:
      - wp_data:/var/www/html
    networks:
      - inception
    depends_on:
      - mariadb
    restart: always
```

- `build: ./requirements/wordpress` — builds from your custom Dockerfile
- `volumes: - wp_data:/var/www/html` — mounts WordPress files to `/var/www/html`, which is the standard web root directory
- `depends_on: - mariadb` — tells Docker Compose to **start MariaDB before WordPress**. This avoids WordPress trying to connect to a DB that isn't ready yet.

> 💡 **Evaluator question:** *"Does depends_on guarantee MariaDB is fully ready?"*
> **Answer:** No! `depends_on` only waits for the container to **start**, not for MariaDB to be fully initialized. That's why in the WordPress entrypoint script we add a loop that waits for the DB to actually accept connections.

---

### The NGINX Service
```yaml
  nginx:
    build: ./requirements/nginx
    container_name: nginx
    ports:
      - "443:443"
    volumes:
      - wp_data:/var/www/html
    networks:
      - inception
    depends_on:
      - wordpress
    restart: always
```

- `ports: - "443:443"` — maps port `443` on your **VM** to port `443` inside the container. Format is `host:container`. This is the **only open port** in the whole project.
- `volumes: - wp_data:/var/www/html` — NGINX shares the **same volume** as WordPress so it can serve static files (images, CSS, JS) directly without going through php-fpm
- `depends_on: - wordpress` — starts after WordPress is up

> 💡 **Evaluator question:** *"Why does NGINX share the same volume as WordPress?"*
> **Answer:** NGINX serves static files directly (faster), and only forwards `.php` requests to WordPress via FastCGI. To serve those static files, it needs access to the WordPress files.

> 💡 **Evaluator question:** *"Why is 443 the only exposed port?"*
> **Answer:** The subject requires that the **only entry point** to the infrastructure is NGINX on port 443 with TLS. No other service exposes ports to the outside — MariaDB and WordPress are only reachable internally within the Docker network.

---

## 🧠 Quick Mental Model

```
docker-compose.yml is the BLUEPRINT of your infrastructure:
  - networks  → how containers find each other
  - volumes   → how data survives restarts
  - services  → what containers exist and how they behave
```

---