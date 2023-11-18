# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 13:36:46 by arigonza          #+#    #+#              #
#    Updated: 2023/11/18 21:45:11 by arigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

BONUS_NAME := so_long_bonus

CC := gcc

CFLAGS := -Wall -Wextra -Werror

FSANITIZE := -fsanitize=address -g3 -O3

LIBFT = lib/libft/libft.a

MLX42 = ./lib/MLX42/build/libmlx42.a

EXTRA := -I include -ldl -lX11 -lXext -lglfw -pthread -lm

OBJDIR := obj

OBJDIR_BONUS := obj_bonus

SRC = src/main.c src/utils.c src/render.c src/map.c \
	src/map_utils.c src/ply_moves.c src/win.c

BONUS_SRC = 

OBJ = $(patsubst src/%.c,$(OBJDIR)/%.o, $(SRC))

BONUS_OBJ = $(patsubst src/%.c,$(OBJDIR_BONUS)/%.o,$(BONUS_SRC))

$(OBJDIR)/%.o : src/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR_BONUS)/%.o : src/%.c | $(OBJDIR_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT) $(MLX42)
	@echo "$(GREEN)Compiling so_long...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -o $@ $^ $(EXTRA) $(FSANITIZE)
	@echo "$(GREEN)so_long ready$(DEF_COLOR)"

$(LIBFT) :
	@echo "$(GREEN)Compiling libft...$(DEF_COLOR)"
	@make -s -C lib/libft
	@echo "$(GREEN)Libft compiled$(DEF_COLOR)"

$(MLX42) : 
	@echo "$(GREEN)Compiling MLX42...$(DEF_COLOR)"
	@make -s -C lib/MLX42/build
	@echo "$(GREEN)MLX42 compiled$(DEF_COLOR)"

$(BONUS_NAME) : $(BONUS_OBJ) $(LIBFT) $(MLX42)
	@echo "$(BLUE)Compiling so_long bonus...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -o $@ $^ $(EXTRA)
	@echo "$(BLUE)so_long bonus compiled$(DEF_COLOR)"

$(OBJDIR) :
	mkdir -p $(OBJDIR)

clean :
	@make -s clean -C lib/libft
	@make -s clean -C lib/MLX42/build
	@rm -rf $(OBJDIR)
	
	@echo "$(RED)Objects cleaned...$(DEF_COLOR)"

fclean : clean
	@make -s fclean -C lib/libft
	@make -s clean -C lib/MLX42/build
	@rm -rf $(NAME) $(BONUS_NAME)
	@echo "$(RED)so_long cleaned...$(DEF_COLOR)"

re : fclean all

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

