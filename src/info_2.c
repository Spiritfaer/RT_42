/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 12:09:35 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/09 12:09:56 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		print_v3d(const t_v3d *src, char *str)
{
	printf("%s.x = %10.4f; %s.y = %10.4f; %s.z = %10.4f;\n",
			str, src->x, str, src->y, str, src->z);
}

void		print_v3i(const t_v3i *src, char *str)
{
	printf("%s.x = %10d; %s.y = %10d; %s.z = %10d;\n",
			str, src->x, str, src->y, str, src->z);
}

void		ft_print_color(const t_rgb *color)
{
	printf("Red = %5d; Green = %5d; Blue = %5d;\nINT COLOR = %9d;\n",
			color->r, color->g, color->b, color->color);
}

void		print_list(t_list *head)
{
	while (head)
	{
		write(1, head->content, head->content_size);
		write(1, "\n", 1);
		head = head->next;
	}
}

void		print_sdl(t_sdl *sdl)
{
	printf("\n---Point status---\n");
	printf("init flag = %d", sdl->init_flag);
	printf("window = %p\n", sdl->window);
	printf("renderer = %p\n", sdl->renderer);
	printf("cur_key = %p\n", (void*)sdl->cur_key);
	printf("---Other status---\n");
	printf("srceen_size width = %d, height = %d\n",
			sdl->screen_s.x, sdl->screen_s.y);
	printf("loop = %d\n", sdl->loop);
	printf("win_name = \"%s\"\n", sdl->win_name);
}
