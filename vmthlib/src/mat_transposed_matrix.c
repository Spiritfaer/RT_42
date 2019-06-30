/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_transposed_matrix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 18:57:33 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/07 19:02:24 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vmth.h"

t_matrix		*transposed_matrix(t_matrix *m)
{
	t_v2i		i;
	t_matrix	*temp;

	i = vec_2i(vec_2d(0.0, 0.0));
	temp = get_new_matrix(m->size);
	while (i.y < m->size)
	{
		i.x = 0;
		while (i.x < m->size)
		{
			temp->matrix[i.x][i.y] = m->matrix[i.y][i.x];
			i.x++;
		}
		i.y++;
	}
	destroy_matrix(&m);
	return (temp);
}
