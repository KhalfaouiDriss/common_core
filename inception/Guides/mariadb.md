
## 📄 MariaDB — Full Line by Line

### The Dockerfile

```dockerfile
FROM debian:bullseye
```
- `FROM` — every Dockerfile must start with this. It defines the **base image** your container is built on top of.
- `debian:bullseye` — we use Debian Bullseye (version 11) as our OS base.

> ❌ **Without it:** The Dockerfile is invalid — Docker has no starting point to build from. Nothing works.

> 💡 **Evaluator question:** *"Why Debian and not Ubuntu or Alpine?"*
> **Answer:** The 42 subject recommends either `debian` or `alpine` as base images. Debian is more familiar and has a complete package manager (`apt`). Alpine is lighter but sometimes has compatibility issues with certain packages.

---

```dockerfile
RUN apt-get update && apt-get install -y mariadb-server && \
    rm -rf /var/lib/apt/lists/*
```
- `RUN` — executes a command **during the image build**, not at runtime
- `apt-get update` — refreshes the list of available packages from Debian repositories
- `&&` — chains commands so they run in the **same layer** (important for image size)
- `apt-get install -y mariadb-server` — installs MariaDB. The `-y` flag auto-confirms the installation without prompting
- `rm -rf /var/lib/apt/lists/*` — deletes the package cache after installation to **reduce image size**

> ❌ **Without `apt-get update`:** `apt-get install` would use an outdated package list and might fail to find `mariadb-server` or install an old broken version.

> ❌ **Without `rm -rf /var/lib/apt/lists/*`:** The image keeps unnecessary cache files, making it **bigger for no reason**. Not critical but bad practice — evaluators notice this.

---

```dockerfile
COPY conf/init.sql /docker-entrypoint-initdb.d/
COPY tools/entrypoint.sh /entrypoint.sh
```
- `COPY` — copies files from your **local machine** into the container image at build time
- `conf/init.sql` → copied into `/docker-entrypoint-initdb.d/` — a special folder MariaDB looks at on first startup to run SQL scripts automatically
- `tools/entrypoint.sh` → copied to `/entrypoint.sh` — our custom startup script

> ❌ **Without copying entrypoint.sh:** The container has no startup logic — it won't create the database, users, or configure anything. MariaDB starts but WordPress can never connect.

---

```dockerfile
RUN chmod +x /entrypoint.sh
```
- `chmod +x` — gives the script **execution permission**. Without this, the OS refuses to run it as a program.

> ❌ **Without it:** You get `Permission denied` when Docker tries to run the entrypoint. The container crashes immediately on startup.

---

```dockerfile
EXPOSE 3306
```
- `EXPOSE` — documents that this container **listens on port 3306** (MySQL/MariaDB default port)
- This is mostly **documentation** — it doesn't actually open the port to the outside world. The real connection happens through the Docker network.

> ❌ **Without it:** The container still works technically, but it's bad practice. It also helps Docker Compose understand service dependencies and port mappings.

---

```dockerfile
ENTRYPOINT ["/entrypoint.sh"]
```
- `ENTRYPOINT` — defines the **first command that runs** when the container starts
- Using array syntax `["..."]` (exec form) is preferred because it runs the script **directly** without a shell wrapper, so signals like `SIGTERM` are properly handled

> ❌ **Without it:** Docker has no idea what to run when the container starts — it would either crash or do nothing. Your entire setup script never executes.

> 💡 **Evaluator question:** *"What's the difference between ENTRYPOINT and CMD?"*
> **Answer:** `ENTRYPOINT` is the main process that always runs and cannot be overridden easily. `CMD` provides default arguments that can be overridden. For a service container like MariaDB, `ENTRYPOINT` is the right choice because we always want our setup script to run.

---

### The entrypoint.sh

```bash
#!/bin/bash
```
- Called a **shebang** — tells the OS which interpreter to use to run this script
- `/bin/bash` means use the Bash shell

> ❌ **Without it:** The OS doesn't know how to execute the file and throws an error like `exec format error`.

---

```bash
mysql_install_db --user=mysql --datadir=/var/lib/mysql
```
- `mysql_install_db` — initializes the MariaDB **data directory** with the system tables needed to run
- `--user=mysql` — runs the initialization as the `mysql` system user (not root), which is more secure
- `--datadir=/var/lib/mysql` — specifies where to create the database files (this is the path we mounted our volume to)

> ❌ **Without it:** MariaDB has no initialized data directory and **refuses to start** entirely. You'd see errors like `Fatal error: Can't open and lock privilege tables`.

---

```bash
mysqld_safe &
sleep 3
```
- `mysqld_safe` — starts MariaDB in a **safe wrapper** that restarts it if it crashes
- `&` — runs it in the **background** so the script can continue to the next lines
- `sleep 3` — waits 3 seconds to give MariaDB time to fully start before we run SQL commands against it

> ❌ **Without `&`:** The script pauses here forever waiting for MariaDB to stop — the setup SQL commands below never run.

> ❌ **Without `sleep 3`:** The SQL commands run before MariaDB is ready, fail with `Can't connect to server`, and your database is never initialized.

---

```bash
mysql -e "CREATE DATABASE IF NOT EXISTS ${DB_NAME};"
```
- `mysql -e` — runs a SQL command directly from the shell
- `CREATE DATABASE IF NOT EXISTS` — creates the WordPress database. The `IF NOT EXISTS` part prevents errors if the container restarts and the DB already exists
- `${DB_NAME}` — this variable comes from your `.env` file via Docker Compose

> ❌ **Without `IF NOT EXISTS`:** Every time the container restarts it tries to create an existing database and **throws an error**, breaking the initialization.

---

```bash
mysql -e "CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';"
```
- `CREATE USER` — creates a dedicated database user for WordPress (never use root!)
- `'${DB_USER}'@'%'` — the `%` means this user can connect **from any host/IP**, not just localhost. This is critical because WordPress is in a different container.
- `IDENTIFIED BY '${DB_PASSWORD}'` — sets the user's password

> ❌ **Without `'%'` (using `localhost` instead):** WordPress can't connect to MariaDB because it's coming from a different container IP. You'd get `Access denied` errors in WordPress.

---

```bash
mysql -e "GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${DB_USER}'@'%';"
mysql -e "FLUSH PRIVILEGES;"
```
- `GRANT ALL PRIVILEGES ON ${DB_NAME}.*` — gives the WordPress user **full access** to only the WordPress database (not all databases)
- `TO '${DB_USER}'@'%'` — for that user from any host
- `FLUSH PRIVILEGES` — forces MariaDB to **reload the permissions table** immediately so the grants take effect

> ❌ **Without GRANT:** The user exists but has no permissions — WordPress connects but immediately fails to read/write any data.

> ❌ **Without FLUSH PRIVILEGES:** The new permissions might not be recognized immediately, causing random connection failures.

---

```bash
mysqladmin shutdown
exec mysqld_safe
```
- `mysqladmin shutdown` — **stops the temporary background MariaDB** we started for setup
- `exec mysqld_safe` — starts MariaDB **again, in the foreground**, replacing the shell process
- `exec` is critical — it replaces the current shell with MariaDB, making MariaDB **PID 1** in the container

> ❌ **Without `exec`:** MariaDB runs as a child of the shell. When Docker sends a stop signal, the shell gets it but MariaDB doesn't — causing **ungraceful shutdowns** and potential data corruption.

> ❌ **Without shutting down first:** You'd have **two MariaDB instances** trying to run at the same time, which causes a port conflict and immediate crash.

---

## 🧠 MariaDB Mental Model

```
Build time (Dockerfile):
  Install MariaDB → Copy scripts → Set permissions

Runtime (entrypoint.sh):
  Init data dir → Start temporarily → Create DB + User + Permissions
       → Shutdown temp → Start permanently in foreground (PID 1)
```