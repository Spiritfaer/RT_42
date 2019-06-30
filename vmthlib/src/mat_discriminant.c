/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_discriminant.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 18:56:34 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/23 21:24:16 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vmth.h"

double_t		get_dis(t_matrix *m)
{
	double_t	res;

	res = m->matrix[0][0] * m->matrix[0][1]
			- m->matrix[1][0] * m->matrix[1][1];
	return (res);
}

/*
** t_matrix	*t_mat;
** t_mat = get_copy_matryx(m);
** !!!!!!!!!!!!IMORTENT!!!!!!!!!!!!
** use get_copy_matryx(m) when using get_discriminant()
** because t_mat been free();
*/

double_t		get_discriminant(t_matrix *m, t_matrix *t_mat)
{
	double_t	dis;
	double_t	bff[10];
	double_t	mult;
	t_v2i		i;

	memset(&i, 0, sizeof(t_v2i));
	if (m->size != 2 && (dis = 1))
		while (i.x < m->size && dis != 0 && (i.y = 0 + i.x) >= 0)
		{
			(t_mat->matrix[i.y][i.x] == 0) ? swap_for_rows(t_mat, i) : 0;
			while (++i.y < m->size)
				if (t_mat->matrix[i.y][i.x] != 0)
				{
					mult = t_mat->matrix[i.y][i.x] / t_mat->matrix[i.x][i.x];
					set_rows_bff(t_mat->matrix[i.x], t_mat->size, bff, mult);
					minus_matrix_buffer(t_mat->matrix[i.y], bff, t_mat->size);
				}
			i.x++;
			(dis != 0) ? dis *= t_mat->matrix[i.x - 1][i.x - 1] : 0;
		}
	else
		dis = get_dis(m);
	destroy_matrix(&t_mat);
	return (dis);
}
