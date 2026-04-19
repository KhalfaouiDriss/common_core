FROM debian:bookworm-slim

RUN apt update && apt install -y redis-server \
    && rm -rf /var/lib/apt/lists/*

COPY conf/redis.conf /etc/redis/redis.conf

EXPOSE 6379

ENTRYPOINT [ "redis-server", "--protected-mode", "no" ]
