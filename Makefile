# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marnaud <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 15:51:10 by marnaud           #+#    #+#              #
#    Updated: 2017/02/13 10:01:50 by marnaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract_ol

SRC = *.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):
	@(cd libft && $(MAKE))
	@(cd minilibx && $(MAKE))
	gcc -o $(NAME) $(SRC) libft/libft.a -lmlx -framework OpenGL -framework AppKit

clean:
	@(cd libft && $(MAKE) $@)
	@(cd minilibx && $(MAKE) $@)
	rm -f $(OBJ)

fclean: clean
	@(cd libft && $(MAKE) $@)
	rm -f $(NAME)

re: fclean all

.PHONY: $(NAME)
