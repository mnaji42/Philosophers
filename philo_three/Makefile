# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: najimehdi <najimehdi@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/11 13:11:57 by mnaji             #+#    #+#              #
#    Updated: 2020/02/16 00:19:56 by najimehdi        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef VERBOSE
.SILENT:
endif

NAME = philo_three

FLAGS = -Wall -Wextra -Werror

SRC_DIR = ./srcs/
OBJ_DIR = ./objs/
INC_DIR = ./includes/

SRC_FILES = main.c utils.c philo.c init_semaphore.c fct.c fct2.c
OBJ_FILES = $(SRC_FILES:.c=.o)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: $(OBJ) $(NAME)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir $(OBJ_DIR) 2> /dev/null || true
	@gcc $(FLAGS) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ)
	@gcc $(OBJ) -o $(NAME)
	@echo "\033[32m$(NAME) generated!\033[0m"

clean:
	@rm -Rf $(OBJ_DIR)
	@echo "\033[31mObjects deleted !\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31m$(NAME) deleted !\033[0m"

re: fclean all

.PHONY: all clean fclean re obj
