/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_get_minor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 18:55:29 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/07 19:25:37 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vmth.h"

static void	init_var(t_v2i *ij, t_v2i *ii)
{
	ii->x = 0;
	ii->y = 0;
	ij->x = 0;
	ij->y = 0;
}

static void	iter_var(t_v2i *ii)
{
	ii->y++;
	ii->x = 0;
}

static void	cpy_step(t_matrix *temp, t_v2i *ii, t_matrix *m, t_v2i *ij)
{
	temp->matrix[ii->y][ii->x] = m->matrix[ij->y][ij->x];
	ii->x++;
}

double		get_minor(t_matrix *m, t_v2i i)
{
	t_matrix	*temp;
	double_t	result;
	t_v2i		ij;
	t_v2i		ii;

	init_var(&ij, &ii);
	temp = get_new_matrix(m->size - 1);
	while (ij.y < m->size)
	{
		ij.x = 0;
		while (ij.x < m->size)
		{
			if (ij.x != i.x && ij.y != i.y)
				cpy_step(temp, &ii, m, &ij);
			ij.x++;
		}
		if (ii.x == temp->size)
			iter_var(&ii);
		ij.y++;
	}
	result = get_discriminant(temp, get_copy_matryx(temp));
	destroy_matrix(&temp);
	return (result);
}
