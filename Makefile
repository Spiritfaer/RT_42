#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: istalevs <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/27 21:13:50 by istalevs          #+#    #+#              #
#    Updated: 2018/05/27 21:13:52 by istalevs         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= RT

SRC		= box.c \
          box_get.c \
          box_intersect.c \
          camera.c \
          color.c \
          color_2.c \
          color_get.c \
          color_get_2.c \
          cone.c \
          cone_get.c \
          cone_inter.c \
          cylinder.c \
          cylinder_get.c \
          event.c \
          info.c \
          info_2.c \
          info_light.c \
          info_obj.c \
          light.c \
          light_pixel.c \
          main.c \
          parser.c \
          parser_var.c \
          plane.c \
          plane_get.c \
          render.c \
          render_get.c \
          render_get_2.c \
          sf_sdl.c \
          sphere.c \
          sphere_get.c \
          temp.c \
          temp_2.c \
          temp_3.c \
          json_parse_help.c \
          json_parse_help2.c \
          json_parse_help3.c \
          json_parse_help4.c \
          json_parse_scene_objects.c \
          uv_map.c \
          menu.c

JSON	= parson.c
OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))
OBJJSON = $(addprefix $(JSONDIR), $(JSON:.c=.o))

SRCDIR	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/


CFLAGS	= -Wall -Wextra -Werror -pipe -flto -Ofast
#CFLAGS	= -Weverything
#CFLAGS	=
LFLAGS	= -lmlx -framework OpenGL -framework AppKit
CC		= gcc

#SDL frameworks
SD		= ./SDL
INCLUDES	=	-I $(SD)/SDL2.framework/Headers \
				-I $(SD)/SDL2_ttf.framework/Headers \
				-I $(SD)/SDL2_image.framework/Headers \
				-I $(SD)/SDL2_mixer.framework/Headers \
				-I json/jsom.h

FRAMEWORKS	=	-F $(SD) -rpath $(SD) \
				-framework OpenGL -framework AppKit -framework OpenCl \
				-framework SDL2 -framework SDL2_ttf -framework SDL2_image \
				-framework SDL2_mixer

# ft library
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft

# vmth library
VMTH		= ./vmthlib/
VMTH_LIB	= $(addprefix $(VMTH),libvmth.a)
VMTH_INC	= -I ./vmthlib/include/
VMTH_LNK	= -L ./vmthlib -l vmth

JSON		= ./json/
JSON_LIB	= $(addprefix $(JSON),libjson.a)
JSON_INC	= -I ./json/
JSON_LNK	= -L ./json/ -l json

all: obj $(FT_LIB) $(JSON_LIB) $(VMTH_LIB) $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(FT_LIB):
	@make -C $(FT)

$(VMTH_LIB):
	@make -C $(VMTH)

$(JSON_LIB):
	@make -C $(JSON)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDES) $(FT_INC) $(JSON_INC) $(VMTH_INC) -I $(INCDIR) -o $@ -c $<

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(INCLUDES) $(FRAMEWORKS) $(FT_LNK) $(JSON_LNK) $(VMTH_LNK) -o $(NAME)
	@printf "RT:  %-25s$(C_GREEN)[done]$(C_NONE)\n" "$(NAME)"

clean:
	@rm -rf $(OBJDIR)
	@make -C $(FT) clean
	@make -C $(VMTH) clean
	@make -C $(JSON) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(FT) fclean
	@make -C $(VMTH) fclean
	@make -C $(JSON) fclean

re: fclean all
