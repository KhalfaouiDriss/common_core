#!/bin/bash

setup_database()
{
    mariadb -u root -p"${DB_ROOT_PASSWORD}" -e "CREATE DATABASE IF NOT EXISTS \`${DB_DATABASE}\`;"
    mariadb -u root -p"${DB_ROOT_PASSWORD}" -e "CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';"
    mariadb -u root -p"${DB_ROOT_PASSWORD}" -e "GRANT ALL PRIVILEGES ON \`${DB_DATABASE}\`.* TO '${DB_USER}'@'%';"
    mariadb -u root -p"${DB_ROOT_PASSWORD}" -e "FLUSH PRIVILEGES;"
}

if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "First boot: Initializing MariaDB..."

    mysql_install_db --user=mysql --datadir=/var/lib/mysql

    mysqld_safe --datadir='/var/lib/mysql' &
    sleep 5

    mariadb -u root -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';"

    setup_database

    mariadb-admin -u root -p"${DB_ROOT_PASSWORD}" shutdown
else
    echo "Database already initialized. Ensuring user exists..."

    mysqld_safe --datadir='/var/lib/mysql' &
    sleep 5

    setup_database

    mariadb-admin -u root -p"${DB_ROOT_PASSWORD}" shutdown
fi

exec mysqld_safe --port=3306 --bind-address=0.0.0.0 --datadir='/var/lib/mysql'
