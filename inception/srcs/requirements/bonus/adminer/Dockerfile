FROM debian:bookworm-slim

RUN apt-get update \
    && apt-get install -y php php-mysqli curl \
    && rm -rf /var/lib/apt/lists/* \
    && mkdir -p /var/www/html

RUN curl -L https://github.com/vrana/adminer/releases/download/v5.0.2/adminer-5.0.2.php -o /var/www/html/index.php

WORKDIR /var/www/html

EXPOSE 8080

ENTRYPOINT ["php", "-S", "0.0.0.0:8080", "-t", "/var/www/html"]
