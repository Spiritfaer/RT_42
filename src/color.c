/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 10:44:38 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/14 20:25:00 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_rgb	clr_add_clr(t_rgb one, t_rgb two)
{
	t_rgb res;

	res.r = add_8_bit(one.r, two.r);
	res.g = add_8_bit(one.g, two.g);
	res.b = add_8_bit(one.b, two.b);
	set_rgb_to_int(&res);
	return (res);
}

int32_t	colort_int_add_colort_int(int32_t one, int32_t two)
{
	t_rgb one_t;
	t_rgb two_t;
	t_rgb res;

	one_t.color = one;
	two_t.color = two;
	set_int_to_rgb(&one_t);
	set_int_to_rgb(&two_t);
	res.r = inter_8_bit(one_t.r, two_t.r);
	res.g = inter_8_bit(one_t.g, two_t.g);
	res.b = inter_8_bit(one_t.b, two_t.b);
	set_rgb_to_int(&res);
	return (res.color);
}

t_rgb	colort_mult_f(t_rgb one, double_t f)
{
	t_rgb res;

	res.r = mult_8_bit(one.r, f);
	res.g = mult_8_bit(one.g, f);
	res.b = mult_8_bit(one.b, f);
	set_rgb_to_int(&res);
	return (res);
}

t_rgb	colort_mult_vec(t_rgb one, t_v3d v)
{
	t_rgb res;

	res.r = mult_8_bit(one.r, v.x);
	res.g = mult_8_bit(one.g, v.y);
	res.b = mult_8_bit(one.b, v.z);
	set_rgb_to_int(&res);
	return (res);
}

t_rgb	b_n_w_mode(t_rgb src)
{
	int	k;

	k = (src.r + src.b + src.g) / 3;
	set_color(&src, k, k, k);
	return (src);
}
