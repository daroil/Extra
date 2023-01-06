# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 18:24:12 by sbritani          #+#    #+#              #
#    Updated: 2023/01/06 16:46:22 by dhendzel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
OBJ_DIR	:= obj/

NAME	:= pipex

SRC		:=	main.c resplit.c

OBJ		:=	$(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(SRC)))

libft_path=libft/libft.a

all: $(NAME)

libft:
	make --directory=libft/

$(NAME): libft $(OBJ_DIR) $(OBJ) 
	$(CC) $(OBJ) $(libft_path) -o $(NAME) $(LDFLAGS)

$(OBJ_DIR)%.o: %.c 
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJ_DIR): 
	mkdir obj


clean:
	make clean --directory=libft/
	rm -f $(OBJ)
	rm -rf obj

fclean: clean
	make fclean --directory=libft/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
