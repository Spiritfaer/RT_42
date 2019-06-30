/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 12:16:32 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/09 12:16:38 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		obj_info(const t_obj *obj)
{
	while (obj)
	{
		if (obj->flag == plane || obj->flag == disk)
			ft_print_plane(obj->data);
		else if (obj->flag == sphere)
			ft_print_sphere(obj->data);
		else if (obj->flag == box)
			ft_print_box(obj->data);
		else if (obj->flag == cone)
			ft_print_cone(obj->data);
		else
			printf("ERROR PRINT INFO!"
				" UNEXPECTABLE FLAG!\nFLAG CODE = %d\n", obj->flag);
		obj = obj->next;
	}
}

void		print_matrix(double_t **matrix, int32_t n)
{
	t_v2i i;

	i.x = 0;
	while (i.x < n)
	{
		i.y = 0;
		while (i.y < n)
		{
			printf("%10.6f ", matrix[i.x][i.y]);
			i.y++;
		}
		printf("\n");
		i.x++;
	}
	printf("\n");
}
