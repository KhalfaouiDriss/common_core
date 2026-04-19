FROM debian:bookworm-slim

RUN apt update && apt install -y vsftpd ftp \
    && rm -rf /var/lib/apt/lists/*

COPY tools/script.sh /usr/local/bin/

RUN chmod 700 /usr/local/bin/script.sh

ENTRYPOINT ["/usr/local/bin/script.sh"]
