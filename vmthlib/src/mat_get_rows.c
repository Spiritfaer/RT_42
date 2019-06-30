/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_get_rows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 18:55:16 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/07 18:55:21 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vmth.h"

void			get_rows(t_matrix *m, int32_t y, double_t *buffer)
{
	int32_t	i;

	i = 0;
	while (i < m->size)
	{
		buffer[i] = m->matrix[y][i];
		i++;
	}
}
