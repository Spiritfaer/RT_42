/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 18:23:09 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/28 00:25:57 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			ft_init_cl_1_math_var(t_cl_m *v, t_ray *ray, const void *data)
{
	v->cyl = (t_cylinder*)data;
	v->ro = ray->orig;
	v->rd = ray->dir;
	v->pa = v->cyl->world_start;
	v->pb = v->cyl->world_end;
	v->ra = v->cyl->radius;
	v->ba = vec_3sub(v->pb, v->pa);
	v->oc = vec_3sub(v->ro, v->pa);
	v->baba = vec_3dot(v->ba, v->ba);
	v->bard = vec_3dot(v->ba, v->rd);
	v->baoc = vec_3dot(v->ba, v->oc);
	v->k2 = v->baba - v->bard * v->bard;
	v->k1 = v->baba * vec_3dot(v->oc, v->rd) - v->baoc * v->bard;
	v->k0 = v->baba * vec_3dot(v->oc, v->oc) - v->baoc * v->baoc
			- v->ra * v->ra * v->baba;
	v->h = v->k1 * v->k1 - v->k2 * v->k0;
}

int8_t			ft_cylinder_inter(t_ray *ray, const void *data, t_hit *hit)
{
	t_cl_m	v;

	ft_init_cl_1_math_var(&v, ray, data);
	if (v.h < 0.0)
		return (false);
	v.h = sqrt(v.h);
	hit->t = (-v.k1 - v.h) / v.k2;
	v.y = v.baoc + (hit->t) * v.bard;
	if (v.y > 0.0 && v.y < v.baba)
	{
		v.one = vec_3fmul(v.rd, (hit->t));
		v.one = vec_3add(v.one, v.oc);
		v.two = vec_3fmul(v.ba, v.y / v.baba);
		hit->norml_hit = vec_3fdiv(vec_3sub(v.one, v.two), v.ra);
		return (true);
	}
	hit->t = (((v.y < 0.0) ? 0.0 : v.baba) - v.baoc) / v.bard;
	if (fabs(v.k1 + v.k2 * (hit->t)) < v.h)
	{
		hit->norml_hit = vec_3fmul(v.ba, ft_sing(v.y) / v.baba);
		return (true);
	}
	return (false);
}

static int8_t	ft_set_cl_mem(t_obj **obj, t_cylinder **cl)
{
	if (!((*obj) = (t_obj*)malloc(sizeof(t_obj))))
		return (error);
	if (!((*cl) = (t_cylinder*)malloc(sizeof(t_cylinder))))
	{
		free((*obj));
		return (error);
	}
	ft_memset((*obj), 0, sizeof(t_obj));
	ft_memset((*cl), 0, sizeof(t_cylinder));
	(*obj)->get_center = ft_get_center_cylinder;
	(*obj)->get_color = ft_get_cylinder_color;
	(*obj)->get_n_hit = ft_get_cylinder_n_hit;
	(*obj)->get_reflection = ft_get_cylinder_reflection;
	(*obj)->intersect = ft_cylinder_inter;
	(*obj)->get_albus = ft_get_cylinder_albus;
	(*obj)->data = (*cl);
	(*obj)->flag = cylinder;
	(*obj)->to_camera = NULL;
	(*obj)->next = NULL;
	return (true);
}

void			if_cylinder_rot(t_cylinder *cylinder, t_parser *var)
{
	cylinder->world_normal = vec_3sub(var->pb, var->pa);
	vec_3drotate(&cylinder->world_normal, var->rot);
	cylinder->world_end = vec_3add(var->pa, cylinder->world_normal);
	vec_3normalize(&cylinder->world_normal);
}

t_obj			*ft_new_cylinder(t_parser *var)
{
	static int8_t	count = 0;
	t_obj			*obj;
	t_cylinder		*new_cylinder;

	if (ft_set_cl_mem(&obj, &new_cylinder) == error)
		return (NULL);
	new_cylinder->world_start = var->pa;
	new_cylinder->radius = var->size;
	new_cylinder->color = var->color;
	new_cylinder->albus = var->albus;
	new_cylinder->reflection = var->reflection;
	if_cylinder_rot(new_cylinder, var);
	printf("cylinder #%d added\n", ++count);
	return (obj);
}
