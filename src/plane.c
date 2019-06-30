/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:16:08 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/27 23:30:58 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int8_t			ft_plane_intersect(t_ray *ray, const void *data, t_hit *hit)
{
	const t_plane	*pl;
	double_t		demon;
	t_v3d			p0l0;

	pl = data;
	demon = vec_3dot(ray->dir, pl->world_normal);
	if (demon > 1e-6 || demon < 1e-6)
	{
		p0l0 = vec_3sub(pl->world_centr, ray->orig);
		hit->t = vec_3dot(p0l0, pl->world_normal) / demon;
		return (hit->t >= 0);
	}
	return (false);
}

int8_t			ft_disk_intersect(t_ray *ray, const void *data, t_hit *hit)
{
	t_v3d		p;
	t_v3d		v;
	double_t	d2;
	t_plane		*pl;

	pl = (t_plane*)data;
	hit->t = 0;
	if (ft_plane_intersect(ray, data, hit))
	{
		p = vec_3add(ray->orig, vec_3fmul(ray->dir, hit->t));
		v = vec_3sub(p, pl->world_centr);
		d2 = vec_3dot(v, v);
		return (d2 <= pl->s2);
	}
	return (false);
}

void			if_plane_rot(t_plane *plane, t_parser *var)
{
	vec_3drotate(&plane->world_normal, var->rot);
	vec_3normalize(&plane->world_normal);
}

static int8_t	ft_set_pl_mem(t_obj **obj, t_plane **pl)
{
	if (!((*obj) = (t_obj*)malloc(sizeof(t_obj))))
		return (error);
	if (!((*pl) = (t_plane*)malloc(sizeof(t_plane))))
	{
		free((*obj));
		return (error);
	}
	ft_memset((*obj), 0, sizeof(t_obj));
	ft_memset((*pl), 0, sizeof(t_plane));
	(*obj)->get_n_hit = ft_plane_intersect_n;
	(*obj)->get_color = ft_get_plane_color;
	(*obj)->get_center = ft_get_center_plane;
	(*obj)->get_reflection = ft_get_plane_reflection;
	(*obj)->get_albus = ft_get_plane_albus;
	(*obj)->to_camera = NULL;
	(*obj)->data = (*pl);
	return (true);
}

t_obj			*ft_new_plane(t_parser *var)
{
	t_obj			*obj;
	t_plane			*new_plane;
	static int8_t	count = 0;

	if (ft_set_pl_mem(&obj, &new_plane) == error)
		return (NULL);
	obj->flag = var->flag;
	obj->intersect = (obj->flag == plane) ?
			ft_plane_intersect : ft_disk_intersect;
	new_plane->size = var->size;
	new_plane->s2 = var->size * var->size;
	new_plane->world_centr = var->pa;
	new_plane->world_normal = (t_v3d){ 0, 1, 0 };
	if_plane_rot(new_plane, var);
	new_plane->color = var->color;
	new_plane->reflection = var->reflection;
	new_plane->albus = var->albus;
	obj->next = NULL;
	printf("plane #%d added\n", ++count);
	return (obj);
}
