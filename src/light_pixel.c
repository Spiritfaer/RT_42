/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 18:55:13 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/27 20:25:07 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		init_light_math(t_l_m *v, t_light *light, t_hit *hit)
{
	if (light)
	{
		v->i_light = light;
		v->light_cof = 0;
		v->spec = 0;
	}
	else if (hit)
	{
		v->lhit = *hit;
		v->test_in = 0;
		v->spec = 0;
	}
}

void		ft_lght_1_m(const t_scena *scena, t_hit *hit, t_l_m *v, t_ray *ray)
{
	v->dist = vec_3magnitude(v->to_light.dir);
	vec_3normalize(&v->to_light.dir);
	v->to_light.orig = hit->point_hit;
	v->to_light.type = shadow;
	if (!ft_trace(&v->lhit, scena->obj_list, &v->to_light)
		|| v->lhit.t_near > v->dist || v->lhit.hit_obj == hit->hit_obj)
	{
		v->light_cof = vec_3dot(hit->norml_hit, v->to_light.dir) / v->dist;
		v->test_in = v->light_cof * v->i_light->power_light;
		v->test_in = v->test_in > 0 ? v->test_in : 0;
		v->test_in = v->test_in > 1 ? 1 : v->test_in;
		if (hit->hit_obj->get_reflection(hit->hit_obj->data) > 0.0f)
		{
			v->reflect.dir = vec_3dreflect(vec_3invert_dir(&v->to_light.dir),
					hit->norml_hit);
			v->reflect.orig = hit->point_hit;
			v->reflect.type = ReflectionAndRefraction;
			v->r_dot_d = vec_3dot(v->reflect.dir, vec_3invert_dir(&ray->dir));
			if (v->r_dot_d > 0)
				v->spec = (v->test_in * pow(v->r_dot_d,
					hit->hit_obj->get_reflection(hit->hit_obj->data) * 256));
		}
	}
}

void		light_color(t_l_m *v, t_hit *hit, t_rgb *color)
{
	v->tmp = col_mult_f(&hit->color_hit, v->test_in);
	v->tmp = clr_add_clr(v->tmp, col_mult_f(&v->i_light->color,
				hit->hit_obj->get_albus(hit->hit_obj->data) * v->test_in));
	v->tmp = clr_add_clr(v->tmp, col_mult_f(&v->i_light->color, v->spec));
	*color = clr_add_clr(*color, v->tmp);
	v->i_light = v->i_light->next;
}

void		test_sphere_texture(t_hit *hit)
{
	if (hit->hit_obj->flag == sphere)
	{
		hit->color_hit.color = set_img_cord_to_sphere(vec_3sub(hit->point_hit,
			hit->norml_hit), (t_sphere*)hit->hit_obj->data);
		set_int_to_rgb(&hit->color_hit);
	}
	else
		hit->color_hit = hit->hit_obj->get_color(hit->hit_obj->data);
}

void		light_pixel(const t_scena *s, t_hit *hit, t_rgb *color, t_ray *ray)
{
	t_l_m	v;

	*color = get_black_color();
	init_light_math(&v, s->light_list, NULL);
	test_sphere_texture(hit);
	while (v.i_light)
	{
		init_light_math(&v, NULL, hit);
		if (v.i_light->type == global_light)
			v.test_in = v.i_light->power_light;
		else
		{
			if (v.i_light->type == point_light)
				v.to_light.dir = vec_3sub(v.i_light->pos, hit->point_hit);
			else if (v.i_light->type == paralel_light)
				v.to_light.dir = v.i_light->dir;
			ft_lght_1_m(s, hit, &v, ray);
		}
		light_color(&v, hit, color);
	}
}
