/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 17:53:48 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/28 00:21:27 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

double_t		ft_get_cylinder_reflection(const void *data)
{
	return (((t_cylinder*)data)->reflection);
}

double_t		ft_get_cylinder_albus(const void *data)
{
	return (((t_cylinder*)data)->albus);
}

t_v3d			ft_get_center_cylinder(const void *data)
{
	return (((t_cylinder*)data)->cam_centr);
}

t_rgb			ft_get_cylinder_color(const void *data)
{
	return (((t_cylinder*)data)->color);
}

t_v3d			ft_get_cylinder_n_hit(t_ray *ray, t_hit *hit, struct s_obj *obj)
{
	if (!ray || !hit || !obj)
		return (vec_1zero());
	hit->point_hit = vec_3add(ray->orig,
						((t_cylinder*)obj->data)->world_start);
	hit->point_hit = vec_3add(hit->point_hit, vec_3fmul(ray->dir, hit->t));
	vec_3normalize(&hit->norml_hit);
	hit->point_hit = vec_3add(hit->point_hit,
						vec_3fmul(hit->norml_hit, hit->bias));
	return (hit->norml_hit);
}
