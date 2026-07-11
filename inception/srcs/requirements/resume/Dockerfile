FROM debian:bullseye

RUN apt-get update && apt-get install -y nginx openssl && \
    rm -rf /var/lib/apt/lists/*

COPY conf/nginx.conf /etc/nginx/sites-available/default

COPY page/* /var/www/html/

EXPOSE 8080

CMD ["nginx", "-g", "daemon off;"]