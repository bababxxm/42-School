# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/05 15:11:14 by sklaokli          #+#    #+#              #
#    Updated: 2026/09/05 15:52:51 by sklaokli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Defaults
BRANCH      ?= master
MAIN_BRANCH ?= main
REMOTE      ?= origin
DIR         ?=

# ANSI Colors
CYAN   := \033[36m
GREEN  := \033[32m
YELLOW := \033[33m
RED    := \033[31m
RESET  := \033[0m
BOLD   := \033[1m

.PHONY: all help push pull status remotes backup subpush subpull \
        push-libft push-printf push-gnl push-minitalk push-pipex \
        push-pushswap push-solong push-minishell push-philo push-minirt \
        push-webserv clean-all fclean-all norm

all: help

help:
	@echo "$(BOLD)$(CYAN)=== 42-School Monorepo Management Console ===$(RESET)"
	@echo ""
	@echo "$(BOLD)Monorepo Git Operations:$(RESET)"
	@echo "  $(GREEN)make push$(RESET)                   Push entire monorepo to GitHub ($(REMOTE)/$(MAIN_BRANCH))"
	@echo "  $(GREEN)make pull$(RESET)                   Pull latest changes for monorepo"
	@echo "  $(GREEN)make status$(RESET) (or $(GREEN)make st$(RESET))    Show repository working status"
	@echo "  $(GREEN)make remotes$(RESET)                List all configured remotes with URLs"
	@echo "  $(GREEN)make backup$(RESET)                 Create a timestamped backup of the .git directory"
	@echo ""
	@echo "$(BOLD)Subtree Operations (Push/Pull Single Project):$(RESET)"
	@echo "  $(GREEN)make subpush DIR=<path> REMOTE=<remote> [BRANCH=master]$(RESET)"
	@echo "      Push a single project folder to an external repository"
	@echo "      $(YELLOW)Example:$(RESET) make subpush DIR=r02/so_long REMOTE=vogsphere-solong"
	@echo "  $(GREEN)make subpull DIR=<path> REMOTE=<remote> [BRANCH=master]$(RESET)"
	@echo "      Pull updates for a single project folder from an external repository"
	@echo "      $(YELLOW)Example:$(RESET) make subpull DIR=r02/so_long REMOTE=vogsphere-solong"
	@echo ""
	@echo "$(BOLD)Project Quick-Push Shortcuts:$(RESET)"
	@echo "  $(GREEN)make push-libft REMOTE=<remote>$(RESET)      Push r00/libft"
	@echo "  $(GREEN)make push-printf REMOTE=<remote>$(RESET)     Push r01/ft_printf"
	@echo "  $(GREEN)make push-gnl REMOTE=<remote>$(RESET)        Push r01/get_next_line"
	@echo "  $(GREEN)make push-minitalk REMOTE=<remote>$(RESET)   Push r02/minitalk"
	@echo "  $(GREEN)make push-pipex REMOTE=<remote>$(RESET)      Push r02/pipex"
	@echo "  $(GREEN)make push-pushswap REMOTE=<remote>$(RESET)   Push r02/push_swap"
	@echo "  $(GREEN)make push-solong REMOTE=<remote>$(RESET)     Push r02/so_long"
	@echo "  $(GREEN)make push-minishell REMOTE=<remote>$(RESET)  Push r03/minishell"
	@echo "  $(GREEN)make push-philo REMOTE=<remote>$(RESET)      Push r03/philosophers"
	@echo "  $(GREEN)make push-minirt REMOTE=<remote>$(RESET)     Push r04/miniRT"
	@echo "  $(GREEN)make push-webserv REMOTE=<remote>$(RESET)    Push r05/webserv"
	@echo ""
	@echo "$(BOLD)Workspace Maintenance:$(RESET)"
	@echo "  $(GREEN)make clean-all$(RESET)              Run clean in all subprojects"
	@echo "  $(GREEN)make fclean-all$(RESET)             Run fclean in all subprojects"
	@echo "  $(GREEN)make norm [DIR=...]$(RESET)          Run Norminette across projects"

# --- Monorepo Git Operations ---

push:
	@echo "$(YELLOW)Pushing monorepo to $(REMOTE)/$(MAIN_BRANCH)...$(RESET)"
	git push $(REMOTE) $(MAIN_BRANCH)

pull:
	@echo "$(YELLOW)Pulling latest changes from $(REMOTE)/$(MAIN_BRANCH)...$(RESET)"
	git pull $(REMOTE) $(MAIN_BRANCH)

status st:
	@git status

remotes:
	@echo "$(CYAN)Configured Git Remotes:$(RESET)"
	@git remote -v

backup:
	@mkdir -p backups
	@tar -czf backups/git_backup_$$(date +%Y%m%d_%H%M%S).tar.gz .git
	@echo "$(GREEN)Monorepo .git backup saved to backups/$(RESET)"

# --- Subtree Operations ---

subpush:
	@if [ -z "$(DIR)" ] || [ -z "$(REMOTE)" ]; then \
		echo "$(RED)Error: Please specify both DIR and REMOTE.$(RESET)"; \
		echo "Usage: make subpush DIR=r02/so_long REMOTE=<remote-name> [BRANCH=master]"; \
		exit 1; \
	fi
	@if [ ! -d "$(DIR)" ]; then \
		echo "$(RED)Error: Directory '$(DIR)' not found.$(RESET)"; \
		exit 1; \
	fi
	@echo "$(YELLOW)Pushing $(DIR) to $(REMOTE)/$(BRANCH)...$(RESET)"
	git subtree push --prefix=$(DIR) $(REMOTE) $(BRANCH)

subpull:
	@if [ -z "$(DIR)" ] || [ -z "$(REMOTE)" ]; then \
		echo "$(RED)Error: Please specify both DIR and REMOTE.$(RESET)"; \
		echo "Usage: make subpull DIR=r02/so_long REMOTE=<remote-name> [BRANCH=master]"; \
		exit 1; \
	fi
	@if [ ! -d "$(DIR)" ]; then \
		echo "$(RED)Error: Directory '$(DIR)' not found.$(RESET)"; \
		exit 1; \
	fi
	@echo "$(YELLOW)Pulling $(DIR) from $(REMOTE)/$(BRANCH)...$(RESET)"
	git subtree pull --prefix=$(DIR) $(REMOTE) $(BRANCH) --squash

# --- Subtree Project Shortcuts ---

push-libft:
	@$(MAKE) subpush DIR=r00/libft REMOTE=$(REMOTE) BRANCH=$(BRANCH)

push-printf:
	@$(MAKE) subpush DIR=r01/ft_printf REMOTE=$(REMOTE) BRANCH=$(BRANCH)

push-gnl:
	@$(MAKE) subpush DIR=r01/get_next_line REMOTE=$(REMOTE) BRANCH=$(BRANCH)

push-minitalk:
	@$(MAKE) subpush DIR=r02/minitalk REMOTE=$(REMOTE) BRANCH=$(BRANCH)

push-pipex:
	@$(MAKE) subpush DIR=r02/pipex REMOTE=$(REMOTE) BRANCH=$(BRANCH)

push-pushswap:
	@$(MAKE) subpush DIR=r02/push_swap REMOTE=$(REMOTE) BRANCH=$(BRANCH)

push-solong:
	@$(MAKE) subpush DIR=r02/so_long REMOTE=$(REMOTE) BRANCH=$(BRANCH)

push-minishell:
	@$(MAKE) subpush DIR=r03/minishell REMOTE=$(REMOTE) BRANCH=$(BRANCH)

push-philo:
	@$(MAKE) subpush DIR=r03/philosophers REMOTE=$(REMOTE) BRANCH=$(BRANCH)

push-minirt:
	@$(MAKE) subpush DIR=r04/miniRT REMOTE=$(REMOTE) BRANCH=$(BRANCH)

push-webserv:
	@$(MAKE) subpush DIR=r05/webserv REMOTE=$(REMOTE) BRANCH=$(BRANCH)

# --- Workspace Maintenance ---

clean-all:
	@echo "$(YELLOW)Cleaning object files across all subprojects...$(RESET)"
	@find r* -name "Makefile" -not -path "*/.*/*" | while read -r mf; do \
		dir=$$(dirname "$$mf"); \
		if grep -q "^clean:" "$$mf" 2>/dev/null; then \
			$(MAKE) -C "$$dir" clean --no-print-directory 2>/dev/null || true; \
		fi; \
	done
	@echo "$(GREEN)Done cleaning.$(RESET)"

fclean-all:
	@echo "$(YELLOW)Fully cleaning (fclean) across all subprojects...$(RESET)"
	@find r* -name "Makefile" -not -path "*/.*/*" | while read -r mf; do \
		dir=$$(dirname "$$mf"); \
		if grep -q "^fclean:" "$$mf" 2>/dev/null; then \
			$(MAKE) -C "$$dir" fclean --no-print-directory 2>/dev/null || true; \
		elif grep -q "^clean:" "$$mf" 2>/dev/null; then \
			$(MAKE) -C "$$dir" clean --no-print-directory 2>/dev/null || true; \
		fi; \
	done
	@echo "$(GREEN)Done fcleaning all build artifacts.$(RESET)"

norm norminette:
	@if [ -n "$(DIR)" ]; then \
		echo "$(YELLOW)Running norminette on $(DIR)...$(RESET)"; \
		norminette $(DIR); \
	else \
		echo "$(YELLOW)Running norminette on all C projects...$(RESET)"; \
		norminette r00/ r01/ r02/ r03/ r04/miniRT 2>/dev/null || norminette r00/; \
	fi
