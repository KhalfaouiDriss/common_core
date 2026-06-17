# Variables
COMPOSE_FILE	= srcs/docker-compose.yml
DATA_PATH		= $(HOME)

all: up

up:
	echo "Creating data directories..."
	@mkdir -p $(DATA_PATH)/data/mariadb
	@mkdir -p $(DATA_PATH)/data/wordpress
	@echo "Building and starting containers..."
	@docker compose -f $(COMPOSE_FILE) up --build -d

down:
	echo "Stopping containers..."
	@docker compose -f $(COMPOSE_FILE) down

re: down up

clean: down
	echo "Removing volumes and data..."
	@docker compose -f $(COMPOSE_FILE) down -v
	@sudo rm -rf $(DATA_PATH)/data/mariadb/*
	@sudo rm -rf $(DATA_PATH)/data/wordpress/*

fclean: clean
	echo "Removing all Docker images and system cache..."
	@docker system prune -af

logs:
	@docker compose -f $(COMPOSE_FILE) logs -f

ps:
	@docker compose -f $(COMPOSE_FILE) ps

.PHONY: all up down re clean fclean logs ps