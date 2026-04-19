FROM debian:bookworm-slim

RUN apt update && apt install -y curl \
    && rm -rf /var/lib/apt/lists/*

RUN curl -L https://github.com/mailhog/MailHog/releases/download/v1.0.1/MailHog_linux_amd64 -o /usr/local/bin/MailHog \
    && chmod +x /usr/local/bin/MailHog

EXPOSE 1025 8025

ENTRYPOINT ["MailHog"]
