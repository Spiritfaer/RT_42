#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: istalevs <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/12 13:33:32 by istalevs          #+#    #+#              #
#    Updated: 2018/05/12 13:33:34 by istalevs         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: clean fclean re norm all

SRC_PATH	= ./src/
OBJ_PATH	= ./obj/
INC_PATH	= ./include/
BUILD_PATH	= ./build/

NAME		= libvmth.a
CC			= gcc
CFLAG		= -Wall -Wextra -Werror

SRC_NAME	= deg_to_rad.c vec_2dscale.c mat_change_symbol.c vec_2fmul.c \
				mat_discriminant.c vec_2i.c mat_fill_vertical_matrix.c \
				vec_2magnitude.c mat_free.c vec_2mul.c mat_get_colums_rows.c \
				vec_2norm.c mat_get_copy.c vec_2normalize.c mat_get_minor.c \
				vec_2sub.c mat_get_new.c vec_3add.c mat_get_rows.c vec_3d.c \
				mat_invert_matrix.c vec_3div.c mat_minors_matrix.c vec_3dot.c \
				mat_minus_matrix_buffer.c vec_3dreflect.c mat_mult_for_double_buffer.c \
				vec_3drot.c mat_mult_m_to_m.c vec_3drotate.c mat_mult_vect_matrix.c	\
				vec_3dscale.c mat_swap_for_rows.c vec_3fdiv.c mat_transposed_matrix.c \
				vec_3fmul.c vec_1back.c	vec_3i.c vec_1double.c vec_3invert_dir.c \
				vec_1right.c vec_3magnitude.c vec_1up.c vec_3mul.c vec_1zero.c \
				vec_3norm.c vec_2add.c vec_3normalize.c vec_2d.c vec_3sub.c \
				vec_2dot.c vec_inters.c vec_2drot.c vec_reflect.c vec_3dcross_product.c \
				inversesqrt.c ft_sing.c

OBJ_NAME	= $(SRC_NAME:.c=.o)

SRC			= $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ			= $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC			= $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "RT:  %-25s$(C_GREEN)[done]$(C_NONE)\n" "$(NAME)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAG) $(INC) -o $@ -c $<

norm:
	@norminette $(SRC) $(INC_PATH)vmth.h

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -Rf $(NAME)

re: fclean all
