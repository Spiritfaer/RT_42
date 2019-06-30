/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 12:11:30 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/09 12:13:09 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		ft_print_plane(const void *data)
{
	const t_plane *temp;

	temp = data;
	printf("\n---PLANE INFO---\n");
	print_v3d(&temp->world_centr, "world_centr");
	print_v3d(&temp->world_normal, "world_normal");
	ft_print_color(&temp->color);
	printf("reflect = %6.2f\n", temp->reflection);
	printf("------------------\n");
}

void		ft_print_sphere(const void *data)
{
	const t_sphere *temp;

	temp = data;
	printf("\n---SPHERE INFO---\n");
	print_v3d(&temp->world_centr, "world_centr");
	ft_print_color(&temp->color);
	printf("Radius = %6.2f;\n", temp->radius);
	printf("reflect = %6.2f\n", temp->reflection);
	printf("------------------\n");
}

void		ft_print_box(const void *data)
{
	const t_box *temp;

	temp = data;
	printf("\n----BOX INFO----\n");
	print_v3d(&temp->min, "min");
	print_v3d(&temp->max, "min");
	ft_print_color(&temp->color);
	printf("reflect = %6.2f\n", temp->reflection);
	printf("------------------\n");
}

void		ft_print_cone(const void *data)
{
	const t_cone *temp;

	temp = data;
	printf("\n---CONE INFO---\n");
	print_v3d(&temp->world_start, "world_start");
	print_v3d(&temp->world_end, "world_end");
	print_v3d(&temp->world_normal, "world_normal");
	ft_print_color(&temp->color);
	printf("Radius = %6.2f;\n", temp->radius);
	printf("------------------\n");
}
