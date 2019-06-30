/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 12:13:51 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/09 12:15:11 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void		global_light_info(const t_light *light)
{
	if (!light)
		return ;
	printf("\n---GLOBAL LIGHT INFO---\n");
	ft_print_color(&light->light_color);
	printf("power = %6.2f\n", light->power_light);
	printf("------------------\n");
}

static void		point_light_info(const t_light *light)
{
	if (!light)
		return ;
	printf("\n---POINT LIGHT INFO---\n");
	ft_print_color(&light->light_color);
	printf("power = %6.2f\n", light->power_light);
	print_v3d(&light->pos, "world_centr");
	printf("------------------\n");
}

static void		paralel_light_info(const t_light *light)
{
	if (!light)
		return ;
	printf("\n---PARALEL LIGHT INFO---\n");
	ft_print_color(&light->light_color);
	printf("power = %6.2f\n", light->power_light);
	print_v3d(&light->dir, "world direction");
	printf("------------------\n");
}

void			light_info(const t_light *light_list)
{
	while (light_list)
	{
		if (light_list->type == global_light)
			global_light_info(light_list);
		if (light_list->type == point_light)
			point_light_info(light_list);
		if (light_list->type == paralel_light)
			paralel_light_info(light_list);
		light_list = light_list->next;
	}
}
