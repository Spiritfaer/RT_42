/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_invert_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 18:57:22 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/23 22:29:38 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vmth.h"

static void			set_inv_matrix(t_matrix *m, double_t **minor, double_t d)
{
	t_v2i	i;

	i.x = 0;
	i.y = 0;
	while (i.y < m->size)
	{
		i.x = 0;
		while (i.x < m->size)
		{
			m->inv_matrix[i.y][i.x] = minor[i.y][i.x] / d;
			i.x++;
		}
		i.y++;
	}
}

void				invert_matrix(t_matrix *m)
{
	t_matrix	*minor_mat;
	double_t	dis;

	minor_mat = NULL;
	dis = 0;
	if (m->inv_matrix == NULL)
		m->inv_matrix = get_new_m(m->size);
	dis = get_discriminant(m, get_copy_matryx(m));
	minor_mat = get_minors_matrix(m);
	set_inv_matrix(m, minor_mat->matrix, dis);
	destroy_matrix(&minor_mat);
}
