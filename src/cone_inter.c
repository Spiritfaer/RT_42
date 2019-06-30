/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 16:21:19 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/23 16:23:32 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_init_cone_1_math_var(t_c_m *v, t_ray *ray, const void *data)
{
	v->cone = (t_cone*)data;
	v->ro = ray->orig;
	v->rd = ray->dir;
	v->pa = v->cone->world_start;
	v->pb = v->cone->world_end;
	v->ra = 0;
	v->rb = v->cone->radius;
	v->ba = vec_3sub(v->pb, v->pa);
	v->oa = vec_3sub(v->ro, v->pa);
	v->ob = vec_3sub(v->ro, v->pb);
	v->m0 = vec_3dot(v->ba, v->ba);
	v->m1 = vec_3dot(v->oa, v->ba);
	v->m2 = vec_3dot(v->ob, v->ba);
	v->m3 = vec_3dot(v->rd, v->ba);
	v->tmp_1 = vec_1zero();
	v->tmp_2 = vec_1zero();
}

void	ft_init_cone_2_math_var(t_c_m *v)
{
	v->m4 = vec_3dot(v->rd, v->oa);
	v->m5 = vec_3dot(v->oa, v->oa);
	v->rr = v->ra - v->rb;
	v->hy = v->m0 + v->rr * v->rr;
	v->k2 = v->m0 * v->m0 - v->m3 * v->m3 * v->hy;
	v->k1 = v->m0 * v->m0 * v->m4 - v->m1 * v->m3 * v->hy
			+ v->m0 * v->ra * (v->rr * v->m3 * 1.0);
	v->k0 = v->m0 * v->m0 * v->m5 - v->m1 * v->m1 * v->hy
			+ v->m0 * v->ra * (v->rr * v->m1 * 2.0 - v->m0 * v->ra);
	v->h = v->k1 * v->k1 - v->k2 * v->k0;
}

int8_t	ft_cone_up_cup(t_c_m *v, t_hit *hit)
{
	v->tmp_1 = vec_3sub(vec_3fmul(v->oa, v->m3), vec_3fmul(v->rd, v->m1));
	if (vec_3dot(v->tmp_1, v->tmp_1) < (v->ra * v->ra * v->m3 * v->m3)
		&& (hit->t = -v->m1 / v->m3))
	{
		hit->norml_hit = vec_3fmul(vec_3invert_dir(&v->ba),
						ft_inversesqrt(v->m0));
		return (true);
	}
	return (false);
}

int8_t	ft_cone_dawn_cup(t_c_m *v, t_hit *hit)
{
	v->tmp_1 = vec_3sub(vec_3fmul(v->ob, v->m3), vec_3fmul(v->rd, v->m2));
	if (vec_3dot(v->tmp_1, v->tmp_1) < (v->rb * v->rb * v->m3 * v->m3)
		&& (hit->t = -v->m2 / v->m3))
	{
		hit->norml_hit = vec_3fmul(v->ba, ft_inversesqrt(v->m0));
		return (true);
	}
	return (false);
}

int8_t	ft_cone_body(t_c_m *v, t_hit *hit)
{
	v->tmp_1 = vec_3add(v->oa, vec_3fmul(v->rd, hit->t));
	v->tmp_2 = vec_3fmul(v->ba, v->rr * v->ra);
	v->tmp_1 = vec_3add(vec_3fmul(v->tmp_1, v->m0), v->tmp_2);
	v->tmp_1 = vec_3fmul(v->tmp_1, v->m0);
	v->tmp_2 = vec_3fmul(v->ba, v->hy * v->y);
	hit->norml_hit = vec_3sub(v->tmp_1, v->tmp_2);
	return (true);
}
