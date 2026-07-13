# Developer Documentation

This document provides technical instructions on how to set up, build, and manage the Inception architecture.

## Setting Up the Environment from Scratch

### Prerequisites
- Ensure **Docker** and **Docker Compose** are installed on the host machine.
- Verify that you have `make` installed.

### Configuration Files and Secrets
1. **Host Mapping**: The project requires the domain `login.42.fr` to point to localhost. Add the following line to your host's `/etc/hosts` file:
   ```text
   127.0.0.1 login.42.fr
   ```
2. **Environment Variables (.env)**: The project relies on a `.env` file located in the `srcs/` directory to manage secrets securely (such as database name, database user, passwords, and WordPress admin details).
   Create `srcs/.env` and populate it with the necessary variables (e.g., `MYSQL_DATABASE`, `MYSQL_USER`, `MYSQL_PASSWORD`, etc.).

## Building and Launching the Project

The root directory contains a `Makefile` that simplifies Docker operations.

- **Build and Start (Default)**:
  ```bash
  make
  ```
  This command points to the `docker-compose.yml` inside the `srcs/` directory and spins up the infrastructure (`nginx`, `wordpress`, `mariadb`) in detached mode.

- **Manual Docker Compose**:
  Alternatively, you can manually navigate to the `srcs/` directory and run Docker Compose:
  ```bash
  cd srcs
  docker compose up -d --build
  ```

## Managing Containers and Volumes

Here are the relevant commands for managing the infrastructure:

- **Stop Services**: `make down` (or `docker compose -f srcs/docker-compose.yml down`)
- **View Running Containers**: `docker ps`
- **View All Containers**: `docker ps -a`
- **Check Service Logs**: `docker logs <container_name>`
- **Access a Container's Shell**:
  ```bash
  docker exec -it <container_name> /bin/sh
  # or /bin/bash depending on the base OS
  ```
- **Clean Up (Full Reset)**: If your Makefile provides rules for deep cleaning (e.g., removing volumes, networks, and images), you might use `make clean` or `make fclean`. To do it manually using standard Docker commands:
  ```bash
  docker system prune -a --volumes
  ```

## Project Data Storage and Persistence

Data persistence is handled via **Docker Volumes**. According to the subject rules, data must be stored on the host machine using volumes mapped to specific directories.

- **Database Data**: MariaDB's data is stored in a volume named `mariadb`, which maps to `/home/dkhalfao/data/mariadb` on the host machine.
- **Website Data**: WordPress files are stored in a volume named `wordpress`, which maps to `/home/dkhalfao/data/wordpress` on the host machine.

*Note: Ensure the `/home/dkhalfao/data/` directories exist on the host machine with appropriate permissions prior to spinning up the containers, or configure your Makefile to create them automatically.*
