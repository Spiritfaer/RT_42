/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_get_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 18:54:49 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/07 18:54:52 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vmth.h"

t_matrix		*get_copy_matryx(t_matrix *m)
{
	t_matrix	*copy;
	t_v2i		i;

	i.x = 0;
	i.y = 0;
	copy = get_new_matrix(m->size);
	while (i.y < m->size)
	{
		i.x = 0;
		while (i.x < m->size)
		{
			copy->matrix[i.y][i.x] = m->matrix[i.y][i.x];
			i.x++;
		}
		i.y++;
	}
	copy->inv_matrix = NULL;
	copy->size = m->size;
	return (copy);
}
