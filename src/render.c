/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 18:50:33 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/28 00:40:02 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			aa_ray_help(t_dr_m *v, t_aa_var *aa_var, t_v2i i)
{
	if (i.x == 1 && i.y == 1)
		v->p_clr = clr_add_clr(col_mult_f(&aa_var->tmp,
				aa_var->high_cof), v->p_clr);
	else
		v->p_clr = clr_add_clr(col_mult_f(&aa_var->tmp,
				aa_var->low_cof), v->p_clr);
}

uint32_t		aa_ray(const t_sdl *sdl, const t_scena *s, t_dr_m *v, t_v2i i)
{
	t_aa_var	aa_var;

	i.x = 0;
	v->p_clr = get_black_color();
	init_aa_ray_var(&aa_var);
	while (i.x < aa_var.size_map)
	{
		v->p.x = (2 * (v->i.x + aa_var.step_map[i.x])
			/ sdl->screen_s.x - 1) * s->cam_p->scale * sdl->iar;
		i.y = 0;
		while (i.y < aa_var.size_map)
		{
			v->p.y = (1 - 2 * (v->i.y + aa_var.step_map[i.y])
				/ sdl->screen_s.y) * s->cam_p->scale;
			v->ray.dir = mult_vect_matrix_3_3(v->p, (s->cam_p->cam->matrix));
			vec_3normalize(&v->ray.dir);
			aa_var.tmp = cast_ray(sdl, s, &v->ray, 0);
			aa_ray_help(v, &aa_var, i);
			i.y++;
		}
		i.x++;
	}
	if (sdl->menu_bw)
		v->p_clr = b_n_w_mode(v->p_clr);
	return (v->p_clr.color);
}

uint32_t		base_ray(const t_sdl *sdl, const t_scena *scena, t_dr_m *v)
{
	v->p.x = (2 * (v->i.x + 0.5) / sdl->screen_s.x - 1)
			* scena->cam_p->scale * sdl->iar;
	v->p.y = (1 - 2 * (v->i.y + 0.5) / sdl->screen_s.y)
			* scena->cam_p->scale;
	v->ray.dir = mult_vect_matrix_3_3(v->p, (scena->cam_p->cam->matrix));
	vec_3normalize(&v->ray.dir);
	v->p_clr = cast_ray(sdl, scena, &v->ray, 0);
	if (sdl->menu_bw)
		v->p_clr = b_n_w_mode(v->p_clr);
	return (v->p_clr.color);
}

void			*ft_draw_tread(void *var)
{
	t_dr_m	*tread_var;
	t_v2i	i;

	tread_var = (t_dr_m*)var;
	tread_var->ray.orig = mult_vect_matrix_4_4(vec_1zero(),
			tread_var->scena->cam_p->cam->matrix);
	tread_var->ray.type = primary;
	i.x = tread_var->start;
	while (i.x < tread_var->end)
	{
		i.y = 0;
		while (i.y < tread_var->sdl->screen_s.y)
		{
			tread_var->i.x = i.x;
			tread_var->i.y = i.y;
			tread_var->pixel_buffer[i.x + i.y * tread_var->sdl->screen_s.x] =
				(!tread_var->scena->cam_p->aa)
				? base_ray(tread_var->sdl, tread_var->scena, tread_var)
				: aa_ray(tread_var->sdl,
						tread_var->scena, tread_var, (t_v2i) {0, 0});
			i.y++;
		}
		i.x++;
	}
	return (NULL);
}

void			ft_render(t_sdl *sdl, t_scena *scena)
{
	pthread_t	thread[THREAD_N];
	void		**tread_var;
	int8_t		i;

	if (!(tread_var = in_th(sdl, scena,
							sdl->canvas->pixels, scena->cam_p->cam->matrix)))
		return ;
	while (sdl->loop && (i = -1))
	{
		if (scena->cam_p->on)
		{
			while (++i < THREAD_N)
				pthread_create(&thread[i], NULL, ft_draw_tread, tread_var[i]);
			while (--i >= 0)
				pthread_join(thread[i], NULL);
			SDL_UpdateTexture(sdl->screen_tx,
					NULL, sdl->canvas->pixels, WIN_SIZE_W << 2u);
			SDL_RenderCopy(sdl->renderer, sdl->screen_tx, 0, 0);
			SDL_RenderPresent(sdl->renderer);
			scena->cam_p->on = false;
		}
		event_guard(sdl, scena, &sdl->time);
	}
	print_matrix(scena->cam_p->cam->matrix, scena->cam_p->cam->size);
	SDL_FreeSurface(sdl->canvas);
}
