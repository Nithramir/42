# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bandre <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 16:17:12 by bandre            #+#    #+#              #
#    Updated: 2017/01/16 11:21:28 by bandre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 

SRC_PATH = 

SRC = 

CC = gcc

LIB =  libft/libftprintf.a

FLAG = -Wall -Wextra -Werror

SRC_O = $(addprefix $(SRC_PATH)/,$(SRC))

all: EXEC $(NAME)

$(NAME):
	$(CC) -o $(NAME) $(SRC_O) $(LIB)

EXEC: 
	make -C libft

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f $(addprefix $(SRC_PATH)/,$(SRC))
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

flag: $(SRC)
	$(CC) $(NAME) $(LIB) -o $(NAME)

.PHONY: $(NAME) all %.o clean fclean re flag EXEC
