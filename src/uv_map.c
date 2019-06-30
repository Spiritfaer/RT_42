/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 17:15:52 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/30 17:15:52 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

Uint32		set_color_img(SDL_Surface *img, int x, int y)
{
	int		byt;
	uint8_t	*pix;

	(x < 0) ? x = 0 : 0;
	if (!img)
		return (0);
	byt = img->format->BytesPerPixel;
	pix = (uint8_t *)img->pixels + y * img->pitch + x * byt;
	if (byt == 1)
		return (*pix);
	if (byt == 2)
		return (*(uint16_t *)pix);
	if (byt == 3)
	{
		if (SDL_BYTEORDER != SDL_BIG_ENDIAN)
			return (pix[0] << 16 | pix[1] << 8 | pix[2]);
		else
			return (pix[0] | pix[1] << 8 | pix[2] << 16);
	}
	if (byt == 4)
		return (*(uint32_t *)pix);
	return (0);
}

int			set_img_cord_to_sphere(t_v3d p, t_sphere *sp)
{
	Uint32	*pix;
	double	u;
	double	v;

	pix = NULL;
	if (sp->img == NULL)
		return (sp->color.color);
	vec_3normalize(&p);
	u = 0.5 + atan2(p.z, p.x) / (2 * PI);
	v = 0.5 - asin(p.y) / PI;
	pix = (Uint32*)sp->img->pixels;
	return (set_color_img(sp->img, (int)(u * sp->img->w),
			(int)(v * sp->img->h)));
}
