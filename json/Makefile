#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/28 18:19:07 by istalevs          #+#    #+#              #
#    Updated: 2019/06/28 18:19:09 by istalevs         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= libjson.a
HEADER	= parson.h
SOURCE	= parson.c
OBJECT	= parson.o

all: $(NAME)

$(NAME):
	@gcc -c $(SOURCE)
	@ar crs $(NAME) $(OBJECT)
	@printf "RT:  %-25s$(C_GREEN)[done]$(C_NONE)\n" "$(NAME)"
	@rm -Rf *.o

clean:
	@rm -Rf *.o
fclean: clean
	@rm -Rf *.a

re: fclean all
