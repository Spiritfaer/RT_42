/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_reflect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 14:02:58 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/09 16:50:30 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** V == vector
** N == normal
** c1 - скалярное произведение
** Rl - вектор, отраженный лучь
** c1 = -dot_product( N, V )
** Rl = V + (2 * N * c1 )
** или R = 2 * N * dot(N, L) - L
*/

#include "vmth.h"

t_v3d		vec_reflect(t_v3d vector, t_v3d normal)
{
	t_v3d new;

	new = vec_3fmul(vec_3fmul(normal, vec_3dot(normal, vector)), 2);
	new = vec_3sub(new, vector);
	return (new);
}
