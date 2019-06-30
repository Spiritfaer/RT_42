/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_sdl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 12:22:10 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/09 12:24:27 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

SDL_Surface	*new_canvas(uint32_t width, uint32_t height)
{
	SDL_Surface	*new_surf;

	new_surf = SDL_CreateRGBSurface(0, width, height, 32,
		0, 0, 0, 0);
	return (new_surf);
}

void		ft_del_sdl(t_sdl *sdl)
{
	if (sdl->renderer)
		SDL_DestroyRenderer(sdl->renderer);
	if (sdl->window)
		SDL_DestroyWindow(sdl->window);
	if (sdl->init_flag)
		SDL_Quit();
}

int8_t		ft_init_img(void)
{
	int32_t		img_flags;

	img_flags = IMG_INIT_PNG | IMG_INIT_JPG;
	if ((IMG_Init(img_flags) & img_flags))
		return (false);
	return (true);
}

int8_t		ft_init_sdl(t_sdl *sdl)
{
	int8_t	result;

	result = 1;
	if ((sdl->init_flag = SDL_Init(SDL_INIT_EVERYTHING)) < 0)
	{
		result--;
		printf("ERROR! SDL_INIT\n");
	}
	else
	{
		sdl->window = SDL_CreateWindow(sdl->win_name, 40, 40,
			sdl->screen_s.x, sdl->screen_s.y, SDL_WINDOW_SHOWN);
		if (!sdl->window)
		{
			result--;
			printf("ERROR! CREATED WINDOWS FAIL\n");
		}
		else
			sdl->renderer = SDL_CreateRenderer(sdl->window, -1,
				SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	}
	if (!ft_init_img())
		result--;
	return (result);
}

t_sdl		*ft_new_sdl(void)
{
	t_sdl	*sdl;

	if (!(sdl = (t_sdl*)malloc(sizeof(t_sdl))))
		return (NULL);
	memset(sdl, 0, sizeof(t_sdl));
	sdl->init_flag = 0;
	sdl->window = NULL;
	sdl->renderer = NULL;
	sdl->cur_key = NULL;
	sdl->win_name = "RT_V1";
	sdl->screen_s.x = WIN_SIZE_W;
	sdl->screen_s.y = WIN_SIZE_H;
	sdl->iar = ((double_t)sdl->screen_s.x) / ((double_t)sdl->screen_s.y);
	sdl->canvas = new_canvas(sdl->screen_s.x, sdl->screen_s.y);
	sdl->loop = 1;
	if (ft_init_sdl(sdl) < 0)
	{
		free(sdl);
		sdl = NULL;
		return (NULL);
	}
	sdl->screen_tx = SDL_CreateTextureFromSurface(sdl->renderer, sdl->canvas);
	return (sdl);
}
