# Variables
COMPOSE_FILE	= srcs/docker-compose.yml
DATA_PATH		= $(HOME)/data

# Colors
GREEN			= \033[0;32m
YELLOW			= \033[0;33m
RED				= \033[0;31m
RESET			= \033[0m

all: up

up:
	@echo "$(GREEN)Creating data directories...$(RESET)"
	@mkdir -p $(DATA_PATH)/mariadb
	@mkdir -p $(DATA_PATH)/wordpress
	@echo "$(GREEN)Building and starting containers...$(RESET)"
	@docker compose -f $(COMPOSE_FILE) up --build -d

down:
	@echo "$(YELLOW)Stopping containers...$(RESET)"
	@docker compose -f $(COMPOSE_FILE) down

re: down up

clean: down
	@echo "$(RED)Removing volumes and data...$(RESET)"
	@docker compose -f $(COMPOSE_FILE) down -v
	@sudo rm -rf $(DATA_PATH)/mariadb/*
	@sudo rm -rf $(DATA_PATH)/wordpress/*

fclean: clean
	@echo "$(RED)Removing all Docker images and system cache...$(RESET)"
	@docker system prune -af

logs:
	@docker compose -f $(COMPOSE_FILE) logs -f

ps:
	@docker compose -f $(COMPOSE_FILE) ps

.PHONY: all up down re clean fclean logs ps