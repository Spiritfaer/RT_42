#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/28 18:36:22 by istalevs          #+#    #+#              #
#    Updated: 2019/06/28 18:36:23 by istalevs         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
HEADER = *.h
SOURCE = *.c
OBJECT = *.o
FLAG_G = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc $(FLAG_G) -c $(SOURCE)
	@ar crs $(NAME) $(OBJECT)
	@printf "RT:  %-25s$(C_GREEN)[done]$(C_NONE)\n" "$(NAME)"

clean:
	@rm -Rf *.o
fclean: clean
	@rm -Rf *.a

re: fclean all
