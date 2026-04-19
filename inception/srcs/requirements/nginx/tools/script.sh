#!/bin/bash

mkdir -p /etc/nginx/ssl

chmod 700 /etc/nginx/ssl

openssl req -x509 -newkey rsa:4096 -nodes -sha256 -days 42 \
	-keyout /etc/nginx/ssl/key-out.key \
	-out /etc/nginx/ssl/cert-out.crt \
	-subj "/C=MO/ST=RB/L=RB/O=42/OU=42/CN=$DOMAIN_NAME"

exec nginx -g 'daemon off;'
