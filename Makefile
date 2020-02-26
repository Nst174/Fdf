# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcremin <jcremin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 18:43:04 by jcremin           #+#    #+#              #
#    Updated: 2019/08/19 19:43:39 by taegon-i         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBRARIES = -lmlx -lm -lft -L$(LIBFT_DIR) -L $(MLX_DIR) -framework OpenGL -framework AppKit
INCLUDES = -I$(HEAD_DIR) -I$(LIBFT_HEAD) -I$(MLX_HEAD)

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/
LIBFT_HEAD = $(LIB_DIR)

MLX = $(MLX_DIR)libmlx.a
#MLX_DIR = ./minilibx_macos/
MLX_DIR = ~/../../usr/local/lib/
MLX_HEAD = $(MLX_DIR)

HEAD_LIST = fdf.h
HEAD_DIR = ./includes/
HEAD = $(addprefix $(HEAD_DIR), $(HEAD_LIST))

SRC_DIR = ./srcs/
SRC_LIST = main.c\
	description.c\
	drawline.c\
	ft_ctdas.c\
	key_press.c\
	color.c\
	mouse_press.c\
	open_window.c\
	press_button.c\
	rotate.c\
	utils.c\
	xyz.c
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR = objects/
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ	= $(addprefix $(OBJ_DIR), $(OBJ_LIST))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ_DIR) $(OBJ)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJ) -o $(NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(NAME): $(GREEN)$(OBJ_DIR) was created$(RESET)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEAD)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIR)

$(MLX):
	@echo "$(NAME): $(GREEN)Creating $(MLX)...$(RESET)"
#	@$(MAKE) -sC $(MLX_DIR)

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
#	@$(MAKE) -sC $(MLX_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(NAME): $(RED)$(OBJ_DIR) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
#	@rm -f $(MLX)
#	@echo "$(NAME): $(RED)$(MLX) was deleted$(RESET)"
	@rm -f $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
