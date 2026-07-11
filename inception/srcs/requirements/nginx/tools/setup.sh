#!/bin/bash

openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/nginx/ssl/key-out.key \
    -out /etc/nginx/ssl/cert-out.crt \
    -subj "/CN=dkhalfao.42.fr"


exec nginx -g "daemon off;"