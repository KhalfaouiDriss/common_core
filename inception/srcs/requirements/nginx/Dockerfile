FROM debian:bullseye

RUN apt-get update && apt-get install -y nginx openssl && \
    rm -rf /var/lib/apt/lists/*

# Generate a self-signed TLS certificate
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/ssl/private/nginx.key \
    -out /etc/ssl/certs/nginx.crt \
    -subj "/C=MA/ST=Rabat/L=Sale/O=42/CN=youlogin.42.fr"

COPY conf/nginx.conf /etc/nginx/sites-available/default

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]