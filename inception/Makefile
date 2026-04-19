CMP_FILE=srcs/docker-compose.yml

DEF = \033[0m
MAGENTA = \033[0;35m
YELLOW = \033[1;33m


all: data_depend
	@echo "${YELLOW} Building and starting containers...${DEF}"
	@docker compose -f ${CMP_FILE} up --build -d

data_depend:
	@echo "${MAGENTA}Creating data directories...${DEF}"
	@mkdir -p /home/${USER}/data/mariadb
	@mkdir -p /home/${USER}/data/wordpress

up:
	@echo "${YELLOW}Containers Starting${DEF}"
	@docker compose -f ${CMP_FILE} up -d

stop:
	@docker compose -f ${CMP_FILE} stop
	@echo "${YELLOW}Containers Stopping${DEF}"

down:
	@docker compose -f ${CMP_FILE} down
	@echo "${YELLOW}Containers Down${DEF}"

clean:
	@docker compose -f ${CMP_FILE} down --remove-orphans
	@echo "${MAGENTA}Containers cleaned${DEF}"

fclean:
	@docker compose -f ${CMP_FILE} down --rmi all --volumes --remove-orphans
	@echo "${MAGENTA}Containers and data volumes cleaned${DEF}"

re: fclean all

status:
	@echo "${MAGENTA}Containers Status${DEF}"
	@docker compose -f ${CMP_FILE} ps -a --format "table {{.Name}}\t{{.Status}}\t{{.Ports}}"

.PHONY: all up down stop clean fclean re status data_depend
