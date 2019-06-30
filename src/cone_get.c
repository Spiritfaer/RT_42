/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:33:25 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/23 15:33:25 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

double_t		ft_get_cone_reflection(const void *data)
{
	return (((t_cone*)data)->reflection);
}

double_t		ft_get_cone_albus(const void *data)
{
	return (((t_cone*)data)->albus);
}

t_v3d			ft_get_center_cone(const void *data)
{
	return (((t_cone*)data)->world_start);
}

t_rgb			ft_get_cone_color(const void *data)
{
	return (((t_cone*)data)->color);
}
