#!/bin/bash

WP_PATH="/var/www/html"

while ! mariadb-admin ping -h"$DB_HOST" -u"$DB_USER" -p"$DB_PASSWORD" --silent; do
    sleep 1
done

if [ ! -f "$WP_PATH/wp-config.php" ]; then
    wp core download --allow-root

    wp config create --allow-root \
        --path=$WP_PATH \
        --dbname=$DB_DATABASE \
        --dbuser=$DB_USER \
        --dbpass=$DB_PASSWORD \
        --dbhost=$DB_HOST

    wp config set WP_REDIS_HOST redis --allow-root
    wp config set WP_REDIS_PORT 6379 --raw --allow-root

    wp core install --allow-root \
        --path=$WP_PATH \
        --url=$DOMAIN_NAME \
        --title=$WEBSITE_TITLE \
        --admin_user=$ADMIN_USERNAME \
        --admin_password=$ADMIN_PASSWORD \
        --admin_email=$ADMIN_EMAIL

    wp user create $USER_NAME $USER_EMAIL --allow-root \
        --user_pass=$USER_PASSWORD \
        --role=editor

    wp plugin install redis-cache --activate --allow-root
    wp redis enable --allow-root
fi

chmod -R u=rwx,g=rx,o=rx "$WP_PATH"
chown -R www-data:www-data "$WP_PATH"

/usr/sbin/php-fpm8.2 -F
