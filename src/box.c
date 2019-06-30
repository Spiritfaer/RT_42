/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 10:55:00 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/24 12:44:26 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		ft_box_var(t_ray *src, t_aabb_ray *dest, t_v3d *b, const void *d)
{
	dest->invdir.x = 1 / src->dir.x;
	dest->invdir.y = 1 / src->dir.y;
	dest->invdir.z = 1 / src->dir.z;
	dest->flag[0] = (dest->invdir.x < 0);
	dest->flag[1] = (dest->invdir.y < 0);
	dest->flag[2] = (dest->invdir.z < 0);
	b[0] = ((t_box*)d)->min;
	b[1] = ((t_box*)d)->max;
}

void		ft_del_box(t_obj **obj)
{
	free((*obj)->data);
	(*obj)->data = NULL;
	free(*obj);
	(*obj) = NULL;
}

int8_t		ft_set_box_mem(t_obj **obj, t_box **b)
{
	if (!((*obj) = (t_obj*)malloc(sizeof(t_obj))))
		return (error);
	if (!((*b) = (t_box*)malloc(sizeof(t_box))))
	{
		free((*obj));
		return (error);
	}
	ft_memset((*obj), 0, sizeof(t_obj));
	ft_memset((*b), 0, sizeof(t_box));
	(*obj)->get_color = ft_get_box_color;
	(*obj)->get_center = ft_get_box_centr;
	(*obj)->intersect = ft_box_intersect;
	(*obj)->get_n_hit = ft_box_intersect_n;
	(*obj)->get_reflection = ft_get_box_reflection;
	(*obj)->to_camera = NULL;
	(*obj)->get_albus = ft_get_box_albus;
	(*obj)->flag = box;
	(*obj)->data = (*b);
	(*obj)->next = NULL;
	return (true);
}

t_obj		*ft_new_box(t_parser *var)
{
	t_obj			*obj;
	t_box			*new_box;
	static int8_t	count = 0;

	if (ft_set_box_mem(&obj, &new_box) == error || var->size == 0.0)
		return (NULL);
	new_box->size = var->size;
	new_box->centr = var->pa;
	new_box->world_norm = var->rot;
	new_box->min.x = new_box->centr.x - new_box->size;
	new_box->min.y = new_box->centr.y - new_box->size;
	new_box->min.z = new_box->centr.z - new_box->size;
	new_box->max.x = new_box->centr.x + new_box->size;
	new_box->max.y = new_box->centr.y + new_box->size;
	new_box->max.z = new_box->centr.z + new_box->size;
	new_box->color = var->color;
	new_box->reflection = var->reflection;
	new_box->albus = var->albus;
	obj->data = new_box;
	printf("box #%d added\n", ++count);
	return (obj);
}
