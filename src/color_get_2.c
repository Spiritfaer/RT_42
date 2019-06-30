/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_get_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 10:44:13 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/14 21:17:36 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

uint8_t	int_to_char(uint32_t in)
{
	in = (in > 255) ? 255 : in;
	return ((in & 255u));
}

void	set_rgb_to_int(t_rgb *src)
{
	src->color = (((uint32_t)src->r << 16u) & RED);
	src->color |= ((uint32_t)src->g << 8u) & GREEN;
	src->color |= (src->b & BLUE);
}
