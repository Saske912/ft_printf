# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/08 05:59:37 by pfile             #+#    #+#              #
#    Updated: 2020/07/08 17:36:14 by pfile            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_DIR = libft/
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
FILES = format_params.c ft_printf.c fills.c format_str.c params.c\
		format_int.c format_ui.c hexa.c save_pointer.c print_hh.c\

all: $(NAME)

$(NAME): header.h
	make bonus -C $(LIB_DIR)
	mv $(LIB_DIR)libft.a $(NAME)
	gcc $(FLAGS) -c $(FILES)
	ar -rcs $(NAME) *.o

clean:
	rm -f *.o $(LIB_DIR)*.o

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
