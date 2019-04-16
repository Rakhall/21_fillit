# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sstannis <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/22 19:40:56 by sstannis          #+#    #+#              #
#    Updated: 2019/02/15 20:38:11 by mroland-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = 	main.c \
	solve_map.c \
	tetrino.c 

FLAGS = -Wall -Wextra -Werror

INCLUDES = fillit.h

all: $(NAME)

$(NAME): $(SRC)
	make -C ./libft
	gcc $(FLAGS) $(SRCS) -I ./libft/ -L libft -lft -o $(NAME)

clean:
	make -C ./libft/ clean

fclean: clean
	make -C ./libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
