/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 18:34:03 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/23 17:48:36 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int8_t			ft_solve_quadratic(t_v3d *abc, t_v2d *tt)
{
	double_t	discr;
	double_t	q;

	discr = abc->y * abc->y - 4 * abc->x * abc->z;
	if (discr < 0)
		return (0);
	else if (discr == 0)
	{
		tt->y = -0.5 * abc->y / abc->x;
		tt->x = tt->y;
	}
	else
	{
		q = (abc->y > 0) ?
			-0.5 * (abc->y + sqrt(discr)) :
			-0.5 * (abc->y - sqrt(discr));
		tt->x = q / abc->x;
		tt->y = abc->z / q;
	}
	if (tt->x > tt->y)
		fs_double_swap(&tt->x, &tt->y);
	return (true);
}

int8_t			ft_sphere_intersect(t_ray *ray, const void *data, t_hit *hit)
{
	const t_sphere	*s;
	t_v2d			tt;
	t_v3d			light;
	t_v3d			abc;

	s = data;
	tt = vec_2d(0.0, 0.0);
	light = vec_3sub(ray->orig, s->world_centr);
	abc.x = vec_3magnitude(ray->dir);
	abc.y = 2 * vec_3dot(ray->dir, light);
	abc.z = vec_3dot(light, light) - s->rad2;
	if (ft_solve_quadratic(&abc, &tt) == false)
		return (false);
	if (tt.x > tt.y)
		fs_double_swap(&tt.x, &tt.y);
	if (tt.x < 0)
	{
		tt.x = tt.y;
		if (tt.x < 0)
			return (false);
	}
	hit->t = tt.x;
	return (true);
}

t_v3d			ft_get_sphere_n_hit(t_ray *ray, t_hit *hit, struct s_obj *obj)
{
	t_sphere	*sp;

	if (!ray || !hit || !obj)
		return (vec_1zero());
	sp = obj->data;
	hit->point_hit = vec_3add(ray->orig, vec_3fmul(ray->dir, hit->t_near));
	hit->norml_hit = vec_3sub(hit->point_hit, sp->world_centr);
	vec_3normalize(&hit->norml_hit);
	hit->point_hit = vec_3add(hit->point_hit,
			vec_3fmul(hit->norml_hit, hit->bias));
	return (hit->norml_hit);
}

static int8_t	ft_set_sp_mem(t_obj **obj, t_sphere **sp)
{
	if (!((*obj) = (t_obj*)malloc(sizeof(t_obj))))
		return (error);
	if (!((*sp) = (t_sphere*)malloc(sizeof(t_sphere))))
	{
		free((*obj));
		return (error);
	}
	ft_memset((*obj), 0, sizeof(t_obj));
	ft_memset((*sp), 0, sizeof(t_sphere));
	(*obj)->get_center = ft_get_center_sphere;
	(*obj)->get_color = ft_get_sphere_color;
	(*obj)->get_n_hit = ft_get_sphere_n_hit;
	(*obj)->get_reflection = ft_get_sphere_reflection;
	(*obj)->to_camera = NULL;
	(*obj)->intersect = ft_sphere_intersect;
	(*obj)->get_albus = ft_get_sphere_albus;
	(*obj)->data = (*sp);
	(*obj)->flag = sphere;
	(*obj)->next = NULL;
	return (true);
}

t_obj			*ft_new_sphere(t_parser *var)
{
	t_obj			*obj;
	t_sphere		*new_sphere;
	static int8_t	count = 0;

	if (ft_set_sp_mem(&obj, &new_sphere) == error)
		return (NULL);
	new_sphere->cam_norm = vec_1up();
	vec_3drotate(&new_sphere->cam_norm, var->rot);
	vec_3normalize(&new_sphere->cam_norm);
	new_sphere->radius = var->size;
	new_sphere->rad2 = var->size * var->size;
	new_sphere->world_centr = var->pa;
	new_sphere->color = var->color;
	new_sphere->reflection = var->reflection;
	new_sphere->albus = var->albus;
	new_sphere->img = var->img;
	printf("spchere #%d added\n", ++count);
	return (obj);
}
