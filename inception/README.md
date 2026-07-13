*This project has been created as part of the 42 curriculum by dkhalfao.*

## Description
Inception is a system administration project at 42 School that introduces Docker and Docker Compose. The goal of this project is to broaden your knowledge of system administration by deploying multiple Docker containers representing a complete web infrastructure. We are tasked with setting up a small infrastructure composed of different services (Nginx, WordPress + php-fpm, and MariaDB) under specific rules, with each service running in a dedicated container built from a specific base system (Alpine or Debian).

## Project description
This project focuses on using Docker to virtualize a complete web infrastructure. It involves creating custom Docker images without relying on pre-built alternatives (except Alpine/Debian as base images). The infrastructure requires configuring Nginx for TLS, setting up WordPress for the frontend, and MariaDB for the database, all orchestrated via Docker Compose.

### Docker Usage & Main Design Choices
The project relies on Docker for process isolation. Each service runs in its own container to ensure a modular and secure architecture. We use Docker Compose to manage the multi-container application, defining specific networks and volumes to handle communication and data persistence safely. 

### Virtual Machines vs Docker
- **Virtual Machines**: Virtualize the entire hardware stack, running a complete guest operating system on top of a hypervisor. They provide strong isolation but are heavy, consume more resources, and have slower boot times.
- **Docker**: Containerization virtualizes the OS kernel. Containers share the host machine's kernel but have isolated filesystems and processes. They are lightweight, start almost instantly, and use fewer resources than VMs.

### Secrets vs Environment Variables
- **Secrets**: Provide a secure mechanism to manage sensitive data (like passwords or API keys). They are typically mounted as in-memory files within containers (e.g., using Docker Swarm or Kubernetes), minimizing the risk of exposure.
- **Environment Variables**: Useful for configuration, but can be less secure for sensitive data because they can be exposed through logs, process lists, or the `docker inspect` command. In this project, environment variables are often used via a `.env` file for simplicity, but in production environments, secrets are preferred for sensitive information.

### Docker Network vs Host Network
- **Docker Network**: Creates an isolated network for containers (like a bridge network). Containers can communicate with each other using internal IP addresses or DNS names, while remaining isolated from the external host network. This enhances security and prevents port conflicts.
- **Host Network**: The container shares the host's networking namespace. It does not get an isolated IP address, and its ports are directly mapped to the host's ports. This removes network isolation, which is less secure but offers slightly better network performance.

### Docker Volumes vs Bind Mounts
- **Docker Volumes**: Managed entirely by Docker. They are stored in a part of the host filesystem that is managed by Docker (e.g., `/var/lib/docker/volumes/`). They are the preferred way to persist data, are easier to back up, and abstract away the host OS filesystem details.
- **Bind Mounts**: Depend on the directory structure of the host machine. You map a specific path on the host to a path in the container. They can be useful for development (e.g., sharing source code) but are less portable and can pose security risks if sensitive host directories are mounted.

## Instructions
To run this project, you need to have Docker and Docker Compose installed on your system.

1. **Clone the repository**:
   ```bash
   git clone <repository_url>
   cd inception
   ```

2. **Configuration**:
   - Ensure the required `.env` file is present in the `srcs` directory with the necessary database and WordPress credentials.
   - Map the local domain to your local IP in your host's `/etc/hosts` file (or `C:\Windows\System32\drivers\etc\hosts` on Windows):
     ```text
     127.0.0.1 dkhalfao.42.fr
     ```

3. **Build and start the infrastructure**:
   to run use 
   ```bash
   make
   ```
   or Navigate to the `srcs` directory where the `docker-compose.yml` is located and run:
   ```bash
   cd srcs
   docker compose up -d --build
   ```

4. **Access the application**:
   Open a web browser and go to `https://drix.42.fr`.

5. **Stop the infrastructure**:
   ```bash
   cd srcs
   docker compose down
   ```

## Resources
- [Docker Documentation](https://docs.docker.com/)
- [Docker Compose Documentation](https://docs.docker.com/compose/)
- [Nginx Official Documentation](https://nginx.org/en/docs/)
- [MariaDB Knowledge Base](https://mariadb.com/kb/en/)
- [WordPress Developer Resources](https://developer.wordpress.org/)

**Use of AI**:
AI was used in this project to assist with generating the initial structure of this README file, summarizing the comparisons (e.g., VMs vs Docker, Volumes vs Bind Mounts), and drafting explanations of technical design choices to ensure clarity and conciseness.
