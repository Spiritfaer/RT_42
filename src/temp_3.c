/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 18:18:24 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/30 18:18:24 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

float_t		random_col_cof(void)
{
	const float_t	m[] = { -.005, -.0025, -.001, .0, .0, .001, .0025, .005 };

	return (m[rand() % (sizeof(m) / sizeof(float_t) + 1 - 0) + 0]);
}

t_rgb		col_mult_f(t_rgb *src, double_t cof)
{
	t_rgb	res;
	t_v3d	col;

	res = get_black_color();
	col = vec_1zero();
	col.x = src->r * (cof + random_col_cof()) + random_col_cof();
	ft_map(&col.x, 0, 255);
	col.y = src->g * (cof + random_col_cof()) + random_col_cof();
	ft_map(&col.y, 0, 255);
	col.z = src->b * (cof + random_col_cof()) + random_col_cof();
	ft_map(&col.z, 0, 255);
	res.r = col.x;
	res.g = col.y;
	res.b = col.z;
	set_rgb_to_int(&res);
	return (res);
}

t_rgb		col_div_f(t_rgb *src, double_t cof)
{
	t_rgb	res;
	t_v3d	col;

	res = get_black_color();
	col = vec_1zero();
	col.x = src->r / (cof + random_col_cof()) + random_col_cof();
	ft_map(&col.x, 0, 255);
	col.y = src->g / (cof + random_col_cof()) + random_col_cof();
	ft_map(&col.y, 0, 255);
	col.z = src->b / (cof + random_col_cof()) + random_col_cof();
	ft_map(&col.z, 0, 255);
	res.r = col.x;
	res.g = col.y;
	res.b = col.z;
	set_rgb_to_int(&res);
	return (res);
}
