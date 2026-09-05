# Project variables
NAME          = dev-workstation
DOCKERFILE    = Dockerfile
CONTEXT       = ./root
PROJECT_PATH  = /home/sklaokli/42/common-core/r05/inception

# Colors for pretty printing
GREEN         = \033[0;32m
RED           = \033[0;31m
RESET         = \033[0m

# Default rule
all: build dev

# Build the workstation image
build:
	@echo "$(GREEN)Building the $(NAME) image...$(RESET)"
	docker build -t $(NAME) -f $(DOCKERFILE) $(CONTEXT)

# Run the workstation container
# -w sets the starting directory inside the container
dev:
	@echo "$(GREEN)Entering $(NAME)...$(RESET)"
	docker run -it --rm \
		-v $(PWD)/root:$(PROJECT_PATH) \
		-v /var/run/docker.sock:/var/run/docker.sock \
		-w $(PROJECT_PATH) \
		$(NAME)

# Stop and remove the workstation container
clean:
	@echo "$(RED)Stopping and removing containers...$(RESET)"
	@docker stop $$(docker ps -qa) 2>/dev/null || true
	@docker rm $$(docker ps -qa) 2>/dev/null || true

# Remove images and prune the system to save quota
fclean: clean
	@echo "$(RED)Deleting all images and pruning...$(RESET)"
	@docker rmi -f $$(docker images -qa) 2>/dev/null || true
	docker system prune -a --volumes -f

# Rebuild everything from scratch
re: fclean all

.PHONY: all build dev clean fclean re