# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 18:24:12 by sbritani          #+#    #+#              #
#    Updated: 2023/01/11 01:44:12 by dhendzel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = pipex
CFLAGS = -Wall -Wextra -Werror 
RM = rm -f
LIBFT	:= ./libft
MAND_SRCS = main \
			paths \
			pipes \
			plumbs \
			utils

BONUS_SRCS = main \
			paths \
			pipes \
			plumbs \
			utils

MAND_OBJS = $(MAND_FIL:.c=.o)
BONUS_OBJS = $(BONUS_FIL:.c=.o)

MAND_FIL = $(addsuffix .c, $(addprefix mand/, $(MAND_SRCS))) \

BONUS_FIL = $(addsuffix _bonus.c, $(addprefix bonus/, $(MAND_SRCS))) \


all : libft $(NAME)

libft:
	@$(MAKE) -C $(LIBFT)
	
$(MAND_OBJS): %.o : %.c
	gcc $(CFLAGS) -c -o $@ $<


$(NAME) : $(MAND_OBJS)
	gcc $(CFLAGS)  $(LIBFT)/libft.a $^ -o $@

clean :
	$(RM) $(MAND_OBJS) $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT) clean

fclean : clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT) fclean

bonus: $(BONUS_OBJS)
	gcc $(CFLAGS) $(LIBFT)/libft.a $^ -o $(NAME)

re: fclean all

.PHONY: all clean fclean re norm libft bonus