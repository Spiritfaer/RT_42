/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:10:59 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/23 15:29:55 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	ft_int_hlp(double_t *nx, double_t *nz, double_t *xx, double_t *xz)
{
	*nx = (*nz > *nx) ? *nz : *nx;
	*xx = (*xz < *xx) ? *xz : *xx;
}

int8_t		ft_box_intersect(t_ray *ray, const void *data, t_hit *hit)
{
	t_aabb_ray	r;
	t_v3d		tmin;
	t_v3d		tmax;
	t_v3d		bounds[2];

	ft_box_var(ray, &r, bounds, data);
	tmin.x = (bounds[r.flag[0]].x - ray->orig.x) * r.invdir.x;
	tmax.x = (bounds[1 - r.flag[0]].x - ray->orig.x) * r.invdir.x;
	tmin.y = (bounds[r.flag[1]].y - ray->orig.y) * r.invdir.y;
	tmax.y = (bounds[1 - r.flag[1]].y - ray->orig.y) * r.invdir.y;
	if ((tmin.x > tmax.y) || (tmin.y > tmax.x))
		return (false);
	ft_int_hlp(&tmin.x, &tmin.y, &tmax.x, &tmax.y);
	tmin.z = (bounds[r.flag[2]].z - ray->orig.z) * r.invdir.z;
	tmax.z = (bounds[1 - r.flag[2]].z - ray->orig.z) * r.invdir.z;
	if ((tmin.x > tmax.z) || (tmin.z > tmax.x))
		return (false);
	ft_int_hlp(&tmin.x, &tmin.z, &tmax.x, &tmax.z);
	hit->t = tmin.x;
	if (hit->t < 0)
	{
		hit->t = tmax.x;
		return (false);
	}
	return (true);
}

static void	ft_dop_box(double_t *vx, double_t *vz, double_t *nx, double_t *nz)
{
	if (fabs(*vx) >= fabs(*vz))
		*nx = (*vx > 0) ? 1 : -1;
	else
		*nz = (*vz > 0) ? 1 : -1;
}

t_v3d		ft_box_intersect_n(t_ray *ray, t_hit *hit, struct s_obj *obj)
{
	t_v3d	normal;
	t_v3d	v;
	t_box	*b;

	if (!ray || !hit || !obj)
		return (vec_1zero());
	b = obj->data;
	normal = vec_1zero();
	hit->point_hit = vec_3add(ray->orig, vec_3fmul(ray->dir, hit->t_near));
	v = vec_3sub(hit->point_hit, b->centr);
	if (fabs(v.x) >= fabs(v.y))
		ft_dop_box(&v.x, &v.z, &normal.x, &normal.z);
	else
		ft_dop_box(&v.y, &v.z, &normal.y, &normal.z);
	hit->norml_hit = vec_3norm(normal);
	hit->point_hit = vec_3add(hit->point_hit,
			vec_3fmul(hit->norml_hit, hit->bias));
	return (normal);
}
