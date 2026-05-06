#!/bin/bash

openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/nginx/ssl/key-out.key \
    -out /etc/nginx/ssl/cert-out.crt \
    -subj "/C=MA/L=Khouribga/O=1337/CN=dkhalfao.42.fr"

nginx -t

exec nginx -g "daemon off;"