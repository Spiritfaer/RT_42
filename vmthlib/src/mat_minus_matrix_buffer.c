/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_minus_matrix_buffer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 18:56:11 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/07 18:56:14 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vmth.h"

void			minus_matrix_buffer(double_t *src, double_t *dst, int32_t size)
{
	int32_t		i;

	i = 0;
	while (i < size)
	{
		*(src + i) -= *(dst + i);
		i++;
	}
}
