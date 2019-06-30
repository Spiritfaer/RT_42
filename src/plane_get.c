/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:15:46 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/26 09:48:47 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

double_t	ft_get_plane_albus(const void *data)
{
	return (((t_plane*)data)->albus);
}

t_rgb		ft_get_plane_color(const void *data)
{
	return (((t_plane*)data)->color);
}

t_v3d		ft_get_center_plane(const void *data)
{
	return (((t_plane*)data)->world_centr);
}

double_t	ft_get_plane_reflection(const void *data)
{
	return (((t_plane*)data)->reflection);
}

t_v3d		ft_plane_intersect_n(t_ray *ray, t_hit *hit, struct s_obj *obj)
{
	t_plane	*pl;

	if (!hit || !ray || !obj)
		return (vec_1zero());
	pl = obj->data;
	hit->point_hit = vec_3add(ray->orig, vec_3fmul(ray->dir, hit->t_near));
	if (vec_3dot(ray->dir, pl->world_normal) < 0.0)
		hit->norml_hit = pl->world_normal;
	else
		hit->norml_hit = vec_3invert_dir(&pl->world_normal);
	hit->point_hit = vec_3add(hit->point_hit,
						vec_3fmul(hit->norml_hit, hit->bias));
	return (hit->norml_hit);
}
