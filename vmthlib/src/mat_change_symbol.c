/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_change_symbol.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 18:51:20 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/07 18:54:09 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vmth.h"

void			change_symbol(t_matrix *m)
{
	t_v2i		i;

	i.x = 0;
	i.y = 0;
	while (i.y < m->size)
	{
		i.x = 0;
		while (i.x < m->size)
		{
			if (i.y == 0 || (i.y % 2) == 0)
			{
				if (m->matrix[i.y][i.x] != 0 && i.x % 2)
					m->matrix[i.y][i.x] *= (-1);
			}
			else
			{
				if (m->matrix[i.y][i.x] != 0 && (i.x % 2) == 0)
					m->matrix[i.y][i.x] *= (-1);
			}
			i.x++;
		}
		i.y++;
	}
}
