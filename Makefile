# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arigonza <arigonza@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 13:36:46 by arigonza          #+#    #+#              #
#    Updated: 2023/10/03 11:58:26 by arigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

BONUS_NAME := so_long_bonus

CC := gcc

CFLAGS := -Wall -Wextra -Werror -fsanitize=address -g3 -O3

LIBFT = lib/libft/libft.a

MLX42 = ./lib/MLX42/build/libmlx42.a

HEADERS := -I ./lib/libft/includes -I ./lib/MLX42/include

EXTRA = -I include -ldl -lX11 -lXext -lglfw -pthread -lm 

SRC = src/main.c

BONUS_SRC =

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT) $(MLX42)
	@echo "$(GREEN)Compiling so_long...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX42) $(EXTRA)
	@echo "$(GREEN)so_long ready$(DEF_COLOR)"

$(LIBFT) :
	@echo "$(GREEN)Compiling libft...$(DEF_COLOR)"
	@make -s -C lib/libft
	@echo "$(GREEN)Libft compiled$(DEF_COLOR)"

$(MLX42) : 
	@echo "$(GREEN)Compiling MLX42...$(DEF_COLOR)"
	@make -s -C lib/MLX42/build
	@echo "$(GREEN)MLX42 compiled$(DEF_COLOR)"

clean :
	@make -s clean -C lib/libft
	@make -s clean -C lib/MLX42/build
	@rm -rf $(OBJ) $(BONUS_OBJ)
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

