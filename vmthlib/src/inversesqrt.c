/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inversesqrt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 11:29:36 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/23 11:29:37 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vmth.h"

/*
** i = *(uint64_t*)&x;				get bits for floating value
** i = 0x5f375a86 - (i >> 1u);		gives initial guess y0
** x = *(float_t *)&i;				convert bits back to float
** x = x * (1.5f - xhalf * x * x);	Newton step, repeating increases accuracy
*/

float_t	ft_inversesqrt(float_t x)
{
	float_t		xhalf;
	uint64_t	i;

	xhalf = 0.5f * x;
	i = *(uint64_t*)&x;
	i = 0x5f375a86 - (i >> 1u);
	x = *(float_t *)&i;
	x = x * (1.5f - xhalf * x * x);
	return (x);
}
