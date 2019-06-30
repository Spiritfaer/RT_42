/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_minors_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 18:55:59 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/07 19:32:42 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vmth.h"

t_matrix		*get_minors_matrix(t_matrix *m)
{
	t_v2i		i;
	t_matrix	*minors;

	i.x = 0;
	i.y = 0;
	minors = get_new_matrix(m->size);
	while (i.y < m->size)
	{
		i.x = 0;
		while (i.x < m->size)
		{
			minors->matrix[i.y][i.x] = get_minor(m, i);
			i.x++;
		}
		i.y++;
	}
	change_symbol(minors);
	minors = transposed_matrix(minors);
	return (minors);
}
