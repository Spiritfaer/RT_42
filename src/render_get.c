/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 18:52:47 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/27 21:16:54 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		set_var(t_dr_m *v, const t_sdl *sdl)
{
	memset(v, 0, sizeof(t_ray));
	memset(&v->p, 0, sizeof(t_v3d));
	memset(&(v->i), 0, sizeof(t_v2i));
	v->pixel_buffer = (uint32_t*)sdl->canvas->pixels;
}

void		cast_var_init(t_hit *hit, t_rgb *color, t_ray *reflect)
{
	ft_memset(hit, 0, sizeof(t_hit));
	hit->bias = 0.1;
	ft_memset(color, 0, sizeof(t_rgb));
	ft_memset(reflect, 0, sizeof(t_ray));
}

int8_t		ft_trace(t_hit *hit, t_obj *index_obj, t_ray *ray)
{
	hit->t_near = DBL_MAX;
	while (index_obj)
	{
		hit->t = DBL_MAX;
		if (index_obj->intersect(ray, index_obj->data, hit) == true
			&& hit->t < hit->t_near
			&& hit->t > 0)
		{
			hit->t_near = hit->t;
			hit->hit_obj_near = index_obj;
			hit->norml_hit_near = hit->norml_hit;
		}
		index_obj = index_obj->next;
	}
	if (hit->t_near < DBL_MAX)
	{
		hit->norml_hit = hit->norml_hit_near;
		hit->hit_obj = hit->hit_obj_near;
		hit->t = hit->t_near;
		hit->hit_obj->get_n_hit(ray, hit, hit->hit_obj);
		return (true);
	}
	else
		return (false);
}
