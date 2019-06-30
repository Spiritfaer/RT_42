/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 10:47:36 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/09 10:47:43 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_v3d		get_to_light_dir(t_hit *hit, t_light *light)
{
	t_v3d	dir_to_light;

	dir_to_light = vec_3sub(light->cam_pos, hit->point_hit);
	vec_3normalize(&dir_to_light);
	return (dir_to_light);
}

void		intens_light(t_light *light)
{
	light->intensity_light.x = ((double_t)light->light_color.r / 255)
			/ light->power_light;
	light->intensity_light.y = ((double_t)light->light_color.g / 255)
			/ light->power_light;
	light->intensity_light.z = ((double_t)light->light_color.b / 255)
			/ light->power_light;
}

t_light		*new_light(t_parser *var)
{
	static int8_t	count = 0;
	t_light			*l;

	if (!(l = (t_light*)malloc(sizeof(t_light))))
		return (l);
	l->transform = get_new_matrix(4);
	fill_vertical_matrix(l->transform);
	l->type = var->flag;
	l->pos = var->pa;
	l->power_light = var->size;
	l->color = var->color;
	l->light_color = colort_mult_f(l->color, l->power_light);
	intens_light(l);
	memset(&l->cam_pos, 0, sizeof(t_v3d));
	l->next = NULL;
	printf("light #%d added\n", ++count);
	return (l);
}
