/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 10:52:46 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/14 10:37:05 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

double_t	ft_get_box_albus(const void *data)
{
	return (((t_box*)data)->albus);
}

t_v3d		ft_get_box_centr(const void *data)
{
	return (((t_box*)data)->centr);
}

t_rgb		ft_get_box_color(const void *data)
{
	return (((t_box*)data)->color);
}

double_t	ft_get_box_reflection(const void *data)
{
	return (((t_box*)data)->reflection);
}

t_v3d		ft_set_box_centr(t_box *box)
{
	box->centr.x = (box->min.x + box->max.x) / 2;
	box->centr.y = (box->min.y + box->max.y) / 2;
	box->centr.z = (box->min.z + box->max.z) / 2;
	box->size = vec_3magnitude(vec_3sub(box->max, box->min));
	return (box->centr);
}
