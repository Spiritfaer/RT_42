/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 10:41:54 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/14 20:37:18 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

uint8_t		add_8_bit(uint16_t a, uint16_t b)
{
	int16_t sum;

	sum = a + b;
	return (int_to_char(sum));
}

uint8_t		mult_8_bit(double_t a, double_t f)
{
	double_t mult;

	mult = a * f;
	return (int_to_char((uint32_t)mult));
}

uint8_t		inter_8_bit(uint16_t a, uint16_t b)
{
	float_t cof;
	int16_t sum;

	cof = ((float_t)a - (float_t)b) / 2;
	sum = (int16_t)((float_t)a - cof);
	sum = int_to_char(sum);
	return (sum);
}

void		set_color(t_rgb *color, uint8_t r, uint8_t g, uint8_t b)
{
	color->r = r;
	color->g = g;
	color->b = b;
	set_rgb_to_int(color);
}

void		set_int_to_rgb(t_rgb *src)
{
	src->r = (src->color & RED) >> 16u;
	src->g = (src->color & GREEN) >> 8u;
	src->b = (src->color & BLUE);
}
