#!/bin/bash

DB_PASSWORD=$(cat /run/secrets/db_password)
DB_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)

# Only initialize if data directory is empty
if [ ! -d /var/lib/mysql/mysql ]; then
    mysql_install_db --user=mysql --datadir=/var/lib/mysql
fi

# Start MariaDB temporarily in background for setup
mysqld_safe --skip-networking &
PID=$! # Capture the process ID of this background MariaDB
sleep 5

# Create DB and user
mysql -e "CREATE DATABASE IF NOT EXISTS ${DB_NAME};"
mysql -e "CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';"
mysql -e "GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${DB_USER}'@'%';"
mysql -e "FLUSH PRIVILEGES;"

# --- THE FIX: Shut down the temporary background server safely ---
mysqladmin -u root shutdown
wait $PID # Wait for it to fully close down and free up the files
sleep 2

# Start MariaDB cleanly in foreground as PID 1
exec mysqld --user=mysql --console --bind-address=0.0.0.0