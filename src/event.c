/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 10:46:24 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/27 22:17:02 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		time_tick(t_time *t)
{
	t->old_time = t->time;
	t->time = SDL_GetTicks();
	t->frame_time = (t->time - t->old_time) / 10000.0;
	t->speed = t->frame_time * 30.0;
}

uint8_t		move_camera(const uint8_t *cur_key, t_matrix *camera, t_time *time)
{
	uint8_t i;

	i = false;
	if (cur_key[SDL_SCANCODE_W] && (i = true))
		camera->matrix[3][1] += time->speed;
	if (cur_key[SDL_SCANCODE_S] && (i = true))
		camera->matrix[3][1] -= time->speed;
	if (cur_key[SDL_SCANCODE_A] && (i = true))
		camera->matrix[3][0] -= time->speed;
	if (cur_key[SDL_SCANCODE_D] && (i = true))
		camera->matrix[3][0] += time->speed;
	if (cur_key[SDL_SCANCODE_SPACE] && (i = true))
		camera->matrix[3][2] += time->speed;
	if (cur_key[SDL_SCANCODE_LCTRL] && (i = true))
		camera->matrix[3][2] -= time->speed;
	return (i);
}

uint8_t		move_fov(const uint8_t *cur_key, t_camera *cam)
{
	if (cur_key[SDL_SCANCODE_UP])
	{
		if (cam->fov < 150)
		{
			cam->fov += 1;
			printf("\nfov = %3.1f\n", cam->fov);
			return (true);
		}
	}
	else if (cur_key[SDL_SCANCODE_DOWN])
	{
		if (cam->fov > 20)
		{
			cam->fov -= 1;
			printf("\nfov = %3.1f\n", cam->fov);
			return (true);
		}
	}
	return (false);
}

void		save_screen_shot(t_sdl *sdl)
{
	static uint32_t	screen_shot = 0;
	char			*screen_stamp;
	char			*digit;

	printf("ok\n");
	digit = ft_itoa(screen_shot);
	screen_stamp = ft_strjoin("screen-shot-", digit);
	free(digit);
	digit = ft_strjoin(screen_stamp, ".png");
	IMG_SavePNG(sdl->canvas, digit);
	free(digit);
	free(screen_stamp);
}

void		event_guard(t_sdl *sdl, t_scena *sc, t_time *time)
{
	t_v2i	i;

	time_tick(time);
	sc->cam_p->aa = sdl->menu_an;
	SDL_PollEvent(&sdl->event);
	sdl->cur_key = SDL_GetKeyboardState(NULL);
	if (sdl->event.type == SDL_QUIT)
		sdl->loop = false;
	if (sdl->cur_key[SDL_SCANCODE_ESCAPE])
		sdl->loop = false;
	if (sdl->menu == 0 && !sc->cam_p->aa)
		sc->cam_p->on |= move_camera(sdl->cur_key, sc->cam_p->cam, time);
	if (sdl->event.button.button == SDL_BUTTON_LEFT
		&& sdl->event.button.type != SDL_MOUSEBUTTONUP &&
		sdl->event.button.clicks == 1 && sdl->menu == 1)
		menu_click_box(sdl, i.x, i.y, sc->cam_p);
	if (sdl->event.type == SDL_KEYDOWN && !sdl->event.key.repeat)
	{
		if (sdl->cur_key[SDL_SCANCODE_Q])
			save_screen_shot(sdl);
		if (!sdl->menu && sdl->cur_key[SDL_SCANCODE_G])
			menu_click_box(sdl, i.x, i.y, sc->cam_p);
	}
	sdl->event.button.button = 0;
}
