# User Documentation

This document explains how to use and manage the Inception infrastructure as an end user or administrator.

---

## Table of Contents

1. [Services Overview](#services-overview)
2. [Starting and Stopping the Project](#starting-and-stopping-the-project)
3. [Accessing the Website and Admin Panel](#accessing-the-website-and-admin-panel)
4. [Managing Credentials](#managing-credentials)
5. [Checking Service Status](#checking-service-status)

---

## Services Overview

The Inception stack provides the following services:

| Service | Description | Access URL/Port |
|---------|-------------|-----------------|
| **WordPress** | Content Management System (CMS) for creating and managing your website | `https://habdella.42.fr` |
| **MariaDB** | Database server storing all WordPress data | Internal (port 3306) |
| **NGINX** | Web server with SSL/TLS encryption | `https://habdella.42.fr` |
| **Redis** | Cache server for improved WordPress performance | Internal (port 6379) |
| **Adminer** | Web-based database management tool | `http://localhost:8080` |
| **FTP** | File transfer service for uploading/downloading files | Port 21 |
| **MailHog** | Email testing tool - captures all outgoing emails | `http://localhost:8025` |
| **Static Website** | Project showcase page | `http://localhost:9999` |

---

## Starting and Stopping the Project

### Starting the Project

To start all services, open a terminal in the project directory and run:

```bash
make
```

This will:
- Create necessary data directories
- Build all container images
- Start all services

### Stopping the Project

**Stop containers (keeps data):**
```bash
make stop
```

**Stop and remove containers (keeps data):**
```bash
make down
```

**Full cleanup (removes all data):**
```bash
make fclean
```

> ⚠️ **Warning:** `make fclean` will delete all your WordPress content, database, and uploaded files permanently.

### Restarting the Project

```bash
make re
```

This performs a full cleanup and rebuilds everything from scratch.

---

## Accessing the Website and Admin Panel

### Prerequisites

Before accessing the website, add the domain to your hosts file:

```bash
echo "127.0.0.1 habdella.42.fr" | sudo tee -a /etc/hosts
```

### WordPress Website

- **URL:** `https://habdella.42.fr`
- Accept the browser's SSL warning (the certificate is self-signed)

### WordPress Admin Panel

- **URL:** `https://habdella.42.fr/wp-admin`
- Log in with your admin credentials (see [Managing Credentials](#managing-credentials))

### Database Management (Adminer)

- **URL:** `http://localhost:8080`
- **System:** MySQL
- **Server:** `mariadb`
- **Username:** Your database user
- **Password:** Your database password
- **Database:** `wordpress`

### Email Testing (MailHog)

- **URL:** `http://localhost:8025`
- View all emails sent by WordPress (no login required)

### Project Showcase

- **URL:** `http://localhost:9999`
- View the static information page about the project

---

## Managing Credentials

### Credential Location

All credentials are stored in the environment file:

```
srcs/.env
```

> ⚠️ **Security:** Never share this file or commit it to a public repository.

### Available Credentials

| Service | Variable | Description |
|---------|----------|-------------|
| WordPress Admin | `ADMIN_USERNAME` | Admin login username |
| WordPress Admin | `ADMIN_PASSWORD` | Admin login password |
| WordPress Admin | `ADMIN_EMAIL` | Admin email address |
| WordPress User | `USER_NAME` | Editor username |
| WordPress User | `USER_PASSWORD` | Editor password |
| Database | `DB_USER` | Database username |
| Database | `DB_PASSWORD` | Database password |
| Database | `DB_ROOT_PASSWORD` | Database root password |
| FTP | `FTP_USER` | FTP username |
| FTP | `FTP_PASS` | FTP password |

### Changing Credentials

1. Stop the project: `make down`
2. Edit `srcs/.env` with new values
3. Clean and rebuild: `make fclean && make`

> **Note:** Changing credentials requires a full rebuild to take effect.

---

## Checking Service Status

### Quick Status Check

View all running containers:

```bash
docker ps
```

All containers should show `Up` status.

### Detailed Service Checks

**Check WordPress:**
```bash
docker exec wordpress wp core is-installed --allow-root
```

**Check Database:**
```bash
docker exec mariadb mariadb -u root -p"YOUR_ROOT_PASSWORD" -e "SHOW DATABASES;"
```

**Check Redis Cache:**
```bash
docker exec redis redis-cli ping
# Should return: PONG
```

**Check Redis WordPress Integration:**
```bash
docker exec wordpress wp redis status --allow-root
```

**Check NGINX SSL:**
```bash
docker exec nginx ls -la /etc/nginx/ssl/
```

### Viewing Logs

**View logs for a specific service:**
```bash
docker logs <container_name>
```

**Examples:**
```bash
docker logs wordpress
docker logs nginx
docker logs mariadb
```

**Follow logs in real-time:**
```bash
docker logs -f <container_name>
```

### Common Issues

| Problem | Solution |
|---------|----------|
| 403 Forbidden | WordPress files not ready. Wait a moment and refresh. |
| SSL Warning | Normal - click "Advanced" and proceed (self-signed certificate). |
| Can't connect to database | Check if MariaDB container is running: `docker ps` |
| Website not loading | Verify hosts file entry: `cat /etc/hosts \| grep habdella` |

---

## Quick Reference

| Action | Command |
|--------|---------|
| Start project | `make` |
| Stop project | `make stop` |
| View containers | `docker ps` |
| View logs | `docker logs <container>` |
| Full cleanup | `make fclean` |
| Rebuild | `make re` |

---

For developer documentation, see [DEV_DOC.md](DEV_DOC.md).
