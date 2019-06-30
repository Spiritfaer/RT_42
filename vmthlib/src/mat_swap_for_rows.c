/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_swap_for_rows.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 18:56:48 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/07 18:56:50 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vmth.h"

void			swap_for_rows(t_matrix *m, t_v2i i)
{
	double_t	*tmp;
	int32_t		p;

	p = i.y;
	tmp = m->matrix[i.y];
	while (p < m->size)
	{
		if (m->matrix[p][i.x] != 0)
		{
			m->matrix[i.y] = m->matrix[p];
			m->matrix[p] = tmp;
			p = m->size;
		}
		p++;
	}
}
