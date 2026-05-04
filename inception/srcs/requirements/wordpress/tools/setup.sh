#!/bin/bash

# Wait for MariaDB to be ready
echo "Waiting for MariaDB..."
while ! mysqladmin ping -h mariadb --silent 2>/dev/null; do
    sleep 2
done
echo "MariaDB is ready!"

cd /var/www/html

if [ ! -f wp-config.php ]; then
    wp core download --allow-root

    wp config create \
        --dbname=${DB_NAME} \
        --dbuser=${DB_USER} \
        --dbpass=${DB_PASSWORD} \
        --dbhost=mariadb:3306 \
        --allow-root

    wp core install \
        --url=${DOMAIN_NAME} \
        --title="Inception" \
        --admin_user=${WP_ADMIN} \
        --admin_password=${WP_ADMIN_PASSWORD} \
        --admin_email=${WP_ADMIN_EMAIL} \
        --allow-root

    wp user create ${WP_USER} ${WP_USER_EMAIL} \
        --role=author \
        --user_pass=${WP_USER_PASSWORD} \
        --allow-root
fi

exec php-fpm7.4 -F