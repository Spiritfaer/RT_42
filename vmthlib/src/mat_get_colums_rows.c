/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_get_colums_rows.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 18:54:32 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/23 21:05:17 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vmth.h"

void		set_rows_bff(double_t *src, int32_t s, double_t *b, double_t mult)
{
	int32_t	i;

	i = 0;
	while (i < s)
	{
		b[i] = src[i] * mult;
		i++;
	}
}

void		get_colums(t_matrix *m, int32_t x, double_t *buffer)
{
	int32_t	i;

	i = 0;
	while (i < m->size)
	{
		buffer[i] = m->matrix[i][x];
		i++;
	}
}
