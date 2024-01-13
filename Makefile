# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 13:36:46 by arigonza          #+#    #+#              #
#    Updated: 2024/01/13 13:51:02 by arigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

BONUS_NAME := so_long_bonus

CC := gcc

CFLAGS := -Wall -Wextra -Werror -g

FSANITIZE := -fsanitize=address -g3 -O3

LIBFT = lib/libft/libft.a

MLX42 = ./lib/MLX42/build/libmlx42.a

MLX42_INSTALL := mlx_install

MLX42_DIR := ./lib/MLX42

$(MLX42_INSTALL) :
	@echo $(YELLOW)INSTALLING MLX42...$(DEF_COLOR)
	@cd $(MLX42_DIR)
	@cmake -B build
	@cmake --build build -j4
	@echo $(GREEN)MLX42 INSTALLED.$(DEF_COLOR)

EXTRA := -I include -ldl -lX11 -lXext -lglfw -pthread -lm

EXTRA_MAC := -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/arigonza/.brew/opt/glfw/lib/"

OBJDIR := obj

OBJDIR_BONUS := obj_bonus

SRC = src/utils.c src/render.c src/map.c \
	src/map_utils.c src/ply_moves.c src/win.c

BONUS_SRC = bonus/src/ply_moves_bonus.c bonus/src/win_bonus.c \
	bonus/src/main_bonus.c bonus/src/utils_bonus.c \
	bonus/src/render_bonus.c \

OBJ = $(patsubst src/%.c,$(OBJDIR)/%.o, $(SRC))

BONUS_OBJ = $(patsubst bonus/src/%.c,$(OBJDIR_BONUS)/%.o, $(BONUS_SRC))

$(OBJDIR)/%.o : src/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR_BONUS)/%.o : bonus/src/%.c | $(OBJDIR_BONUS)
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT) $(MLX42)
	@echo "$(YELLOW)Compiling so_long...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -o $@ $^ src/main.c $(EXTRA_MAC) 
	@echo "$(GREEN)so_long ready.$(DEF_COLOR)"

$(LIBFT) :
	@echo "$(YELLOW)Compiling libft...$(DEF_COLOR)"
	@make -s -C lib/libft
	@echo "$(GREEN)Libft compiled.$(DEF_COLOR)"

$(MLX42) : 
	@echo "$(YELLOW)Compiling MLX42...$(DEF_COLOR)"
	@make -s -C lib/MLX42/build
	@echo "$(GREEN)MLX42 compiled.$(DEF_COLOR)"

$(BONUS_NAME) : $(LIBFT) $(MLX42) $(OBJ) $(BONUS_OBJ)
	@echo "$(YELLOW)Compiling so_long bonus...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -o $@ $^ -I bonus/includes $(EXTRA_MAC)
	@echo "$(GREEN)so_long bonus compiled.$(DEF_COLOR)"

$(OBJDIR) :
	@mkdir -p $(OBJDIR)

$(OBJDIR_BONUS) :
	@mkdir -p $(OBJDIR_BONUS)

clean :
	@make -s clean -C lib/libft
	@make -s clean -C lib/MLX42/build
	@rm -rf $(OBJDIR) $(OBJDIR_BONUS)
	@echo "$(RED)Objects cleaned...$(DEF_COLOR)"

fclean : clean
	@make -s fclean -C lib/libft
	@make -s clean -C lib/MLX42/build
	@rm -rf $(NAME) $(BONUS_NAME)
	@echo "$(RED)so_long cleaned...$(DEF_COLOR)"

re : fclean all

re_bonus : fclean $(BONUS_NAME)

norm :
	@echo "$(CYAN)Norminette src/$(GREEN)"
	@norminette src/
	@echo "$(CYAN)Norminette bonus/src$(GREEN)"
	@norminette bonus/src/
	@echo "$(CYAN)Norminette includes/ & bonus/includes/$(GREEN)"
	@norminette includes/
	@norminette bonus/includes/
	@echo "$(DEF_COLOR)"

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

