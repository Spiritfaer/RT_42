/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 17:14:03 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/30 17:14:04 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

SDL_Surface		*optimize_window(t_sdl *sdl, SDL_Surface *pic)
{
	SDL_Surface	*optimized_pic;

	optimized_pic = SDL_ConvertSurface(pic, sdl->canvas->format, 0);
	if (optimized_pic == NULL)
		return (NULL);
	SDL_FreeSurface(pic);
	return (optimized_pic);
}

int				find_surf(t_sdl *sdl)
{
	sdl->menu = 1;
	if (sdl->menu_bw && sdl->menu_an)
		return (menu_b_an);
	else if (sdl->menu_bw)
		return (menu_blwh);
	else if (sdl->menu_an)
		return (menu_anal);
	return (0);
}

void			menu_click_box(t_sdl *sdl, int x, int y, t_camera *cam)
{
	int	surf;

	if (sdl->menu)
		SDL_GetMouseState(&x, &y);
	if (x >= 388 && x <= 697)
		if (y >= 592 && y <= 675)
			sdl->loop = 0;
	if (x >= 447 && x <= 495)
		if (y >= 492 && y <= 528)
			sdl->menu_an = sdl->menu_an == true ? false : true;
	if (x >= 465 && x <= 502)
		if (y >= 434 && y <= 461)
		{
			sdl->menu_bw = sdl->menu_bw == true ? false : true;
			sdl->b_n_w_mode = sdl->b_n_w_mode == 1 ? 0 : 1;
		}
	surf = find_surf(sdl);
	if (x >= 50 && x <= 294)
		if (y >= 576 && y <= 665)
		{
			cam->on = 1;
			sdl->menu = 0;
		}
	init_menu(sdl, surf);
}

SDL_Surface		*load_menu(int menu_list)
{
	SDL_Surface *menu;

	menu = NULL;
	if (menu_list == menu_main)
		menu = IMG_Load("images/menu_1.png");
	else if (menu_list == menu_anal)
		menu = IMG_Load("images/menu_ana.png");
	else if (menu_list == menu_blwh)
		menu = IMG_Load("images/menu_bl.png");
	else if (menu_list == menu_b_an)
		menu = IMG_Load("images/menu_b_a.png");
	return (menu);
}

int				init_menu(t_sdl *sdl, int menu)
{
	SDL_Surface		*pic;
	SDL_Rect		stretch;
	SDL_Surface		*scaled;

	if ((pic = load_menu(menu)) == NULL)
		return (0);
	scaled = optimize_window(sdl, pic);
	stretch.x = 0;
	stretch.y = 0;
	stretch.w = WIN_SIZE_W;
	stretch.h = WIN_SIZE_H + 5;
	SDL_BlitScaled(scaled, NULL, sdl->canvas, &stretch);
	SDL_UpdateTexture(sdl->screen_tx,
					&stretch, sdl->canvas->pixels, WIN_SIZE_W << 2u);
	SDL_RenderCopy(sdl->renderer, sdl->screen_tx, 0, 0);
	SDL_RenderPresent(sdl->renderer);
	return (true);
}
