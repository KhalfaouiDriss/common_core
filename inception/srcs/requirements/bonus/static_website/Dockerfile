FROM debian:bookworm-slim

RUN apt update && apt install -y php \
    && rm -rf /var/lib/apt/lists/* \
    && mkdir -p /www/html

COPY app/ /www/html/

EXPOSE 9999

ENTRYPOINT [ "php", "-S", "0.0.0.0:9999", "-t", "/www/html/" ]
