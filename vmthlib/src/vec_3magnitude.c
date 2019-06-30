/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_3magnitude.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 21:37:43 by istalevs          #+#    #+#             */
/*   Updated: 2018/05/13 21:51:01 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vmth.h"

/*
**	длинна или модуль(magnitude) вектора (3D)
*/

double	vec_3magnitude(t_v3d v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}