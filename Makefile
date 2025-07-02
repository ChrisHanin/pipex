# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 14:02:31 by chanin            #+#    #+#              #
#    Updated: 2025/06/24 18:23:58 by chanin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAME_bonus = pipex_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRC = 	pipex_main.c pipex_command.c pipex_utils.c \
		pipex_open_close.c pipex_command_bis.c\


SRC_b  = pipex_main_bonus.c pipex_command_bonus.c pipex_utils_bonus.c \
		pipex_open_close_bonus.c pipex_command_bonus_bis.c\


OBJ_DIR = objects
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
OBJ_b = $(SRC_b:%.c=$(OBJ_DIR)/%.o)

LIBFT = libft/libft.a

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\n                    -------------------------\n                      YOU ARE THE LECHE !!!\n                    -------------------------\n"

$(NAME_bonus): $(OBJ_b) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_b) $(LIBFT) -o $(NAME_bonus)
	@echo "\n                    -------------------------\n                      YOU ARE THE LECHE !!!\n                    -------------------------\n"

$(LIBFT):
	@echo "Compilando libft..."
	@$(MAKE) -C libft bonus > /dev/null
	
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	
all: $(NAME)

bonus: $(NAME_bonus)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME) 
	rm -f $(NAME_bonus) 
	$(MAKE) -C libft fclean
	
re: fclean all

.PHONY: all clean fclean re bonus
