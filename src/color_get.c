/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 10:42:23 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/09 10:42:24 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_rgb	get_black_color(void)
{
	return ((t_rgb) {0, 0, 0, BLACK});
}

t_rgb	get_red_color(void)
{
	return ((t_rgb) { 255, 0, 0, RED });
}

t_rgb	get_green_color(void)
{
	return ((t_rgb) { 0, 255, 0, GREEN });
}

t_rgb	get_blue_color(void)
{
	return ((t_rgb) { 0, 0, 255, BLUE });
}

t_rgb	get_white_color(void)
{
	return ((t_rgb) { 255, 255, 255, WHITE });
}
