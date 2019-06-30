/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:33:19 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/28 00:35:45 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int8_t			ray_intersect_cone(t_ray *ray, const void *data, t_hit *hit)
{
	t_c_m	v;

	ft_init_cone_1_math_var(&v, ray, data);
	if (v.m1 < 0.0)
	{
		if (ft_cone_up_cup(&v, hit) == true)
			return (true);
	}
	else if (v.m2 > 0.0)
	{
		if (ft_cone_dawn_cup(&v, hit) == true)
			return (true);
	}
	ft_init_cone_2_math_var(&v);
	if (v.h < 0.0)
		return (false);
	hit->t = (-v.k1 - sqrt(v.h)) / v.k2;
	v.y = v.m1 + (hit->t) * v.m3;
	if (v.y > 0.0 && v.y < v.m0)
		if (ft_cone_body(&v, hit) == true)
			return (true);
	return (false);
}

t_v3d			ft_get_cone_n_hit(t_ray *ray, t_hit *hit, struct s_obj *obj)
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

static int8_t	ft_set_cone_mem(t_obj **obj, t_cone **cone)
{
	if (!((*obj) = (t_obj*)malloc(sizeof(t_obj))))
		return (error);
	if (!((*cone) = (t_cone*)malloc(sizeof(t_cone))))
	{
		free((*obj));
		return (error);
	}
	ft_memset((*obj), 0, sizeof(t_obj));
	ft_memset((*cone), 0, sizeof(t_cone));
	(*obj)->get_center = ft_get_center_cone;
	(*obj)->get_color = ft_get_cone_color;
	(*obj)->get_n_hit = ft_get_cone_n_hit;
	(*obj)->get_albus = ft_get_cone_albus;
	(*obj)->get_reflection = ft_get_cone_reflection;
	(*obj)->intersect = ray_intersect_cone;
	(*obj)->data = (*cone);
	(*obj)->flag = sphere;
	(*obj)->to_camera = NULL;
	(*obj)->next = NULL;
	return (true);
}

void			if_cone_rot(t_cone *cone, t_parser *var)
{
	cone->world_normal = vec_3sub(var->pb, var->pa);
	vec_3drotate(&cone->world_normal, var->rot);
	cone->world_end = vec_3add(var->pa, cone->world_normal);
	vec_3normalize(&cone->world_normal);
}

t_obj			*ft_new_cone(t_parser *var)
{
	static int8_t	count = 0;
	t_obj			*obj;
	t_cone			*new_cone;

	if (ft_set_cone_mem(&obj, &new_cone) == error)
		return (NULL);
	obj->flag = cone;
	new_cone->world_start = var->pa;
	new_cone->world_end = var->pb;
	new_cone->radius = var->size;
	new_cone->size = var->size;
	new_cone->color = var->color;
	new_cone->albus = var->albus;
	new_cone->reflection = var->reflection;
	if_cone_rot(new_cone, var);
	printf("cone #%d added\n", ++count);
	return (obj);
}
