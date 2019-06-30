/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 12:19:38 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/15 23:07:29 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

double_t	ft_get_sphere_albus(const void *data)
{
	return (((t_sphere*)data)->albus);
}

t_v3d		ft_get_center_sphere(const void *data)
{
	return (((t_sphere*)data)->world_centr);
}

t_rgb		ft_get_sphere_color(const void *data)
{
	return (((t_sphere*)data)->color);
}

double_t	ft_get_sphere_reflection(const void *data)
{
	return (((t_sphere*)data)->reflection);
}
