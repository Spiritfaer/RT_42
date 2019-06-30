/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_get_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 17:41:33 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/30 17:41:34 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		ft_reflect(t_ray *reflect, t_ray *ray, t_hit *hit, t_rgb *color)
{
	reflect->dir = vec_3dreflect(ray->dir, hit->norml_hit);
	reflect->orig = hit->point_hit;
	reflect->type = ReflectionAndRefraction;
	if (ray->type == ReflectionAndRefraction)
	{
		*color = colort_mult_f(*color,
			1 - hit->hit_obj->get_albus(hit->hit_obj->data));
		hit->color_hit = colort_mult_f(hit->color_hit, 1);
	}
}

t_rgb		cast_ray(const t_sdl *sdl, const t_scena *s, t_ray *r, int16_t dth)
{
	t_hit	hit;
	t_rgb	color;
	t_ray	reflect;

	if (dth >= MAX_DEPTH)
		return (s->cam_p->bg_color);
	cast_var_init(&hit, &color, &reflect);
	if (ft_trace(&hit, s->obj_list, r))
	{
		light_pixel(s, &hit, &color, r);
		if (hit.hit_obj->get_reflection(hit.hit_obj->data) > 0
			|| (!color.color && !dth))
		{
			ft_reflect(&reflect, r, &hit, &color);
			color = clr_add_clr(colort_mult_f(
					cast_ray(sdl, s, &reflect, dth + 1),
					hit.hit_obj->get_reflection(hit.hit_obj->data)), color);
		}
		return (color);
	}
	else
		return (s->cam_p->bg_color);
}

void		**in_th(const t_sdl *sdl, const t_scena *s, void *p, double_t **m)
{
	t_dr_m	**v;
	int8_t	index;

	index = 0;
	if ((v = (t_dr_m **)malloc(sizeof(t_dr_m*) * THREAD_N)))
	{
		while (index < THREAD_N)
		{
			if ((v[index] = (t_dr_m*)malloc(sizeof(t_dr_m))))
			{
				ft_memset(v[index], 0, sizeof(t_dr_m));
				v[index]->p.z = -1;
				v[index]->pixel_buffer = (uint32_t*)p;
				v[index]->start = (WIN_SIZE_W / THREAD_N) * index;
				v[index]->end = (WIN_SIZE_W / THREAD_N) * (index + 1);
				v[index]->ray.orig = mult_vect_matrix_4_4(vec_1zero(), m);
				v[index]->ray.type = primary;
				v[index]->sdl = sdl;
				v[index]->scena = s;
				index++;
			}
		}
	}
	return ((void**)v);
}

void		init_aa_ray_var(t_aa_var *var)
{
	var->step_map[0] = 0.1;
	var->step_map[1] = 0.5;
	var->step_map[2] = 0.9;
	var->size_map = 3;
	var->high_cof = 0.5;
	var->low_cof = var->high_cof / (var->size_map * var->size_map - 1);
	var->tmp = get_black_color();
}
