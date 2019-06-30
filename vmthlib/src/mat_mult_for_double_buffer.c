/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_mult_for_double_buffer.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 18:56:22 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/07 18:56:25 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vmth.h"

double		mult_for_double_buffer(double_t *src, double_t *dst, int32_t size)
{
	double_t	sum;
	int32_t		i;

	sum = 0;
	i = 0;
	if (!src || !dst)
		return (sum);
	while (i < size)
	{
		sum += src[i] * dst[i];
		i++;
	}
	return (sum);
}
