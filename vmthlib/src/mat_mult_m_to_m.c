/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_mult_m_to_m.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 18:57:01 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/07 20:18:33 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vmth.h"

t_matrix	*mult_m_to_m(t_matrix *one, t_matrix *two)
{
	t_v2i		i;
	t_matrix	*mult_m;
	double_t	buffer_src[32];
	double_t	buffer_dst[32];

	i.x = 0;
	i.y = 0;
	mult_m = get_new_matrix(one->size);
	while (i.y < one->size)
	{
		i.x = 0;
		get_rows(one, i.y, buffer_src);
		while (i.x < one->size)
		{
			get_colums(two, i.x, buffer_dst);
			mult_m->matrix[i.y][i.x] =
				mult_for_double_buffer(buffer_src, buffer_dst, mult_m->size);
			i.x++;
		}
		i.y++;
	}
	return (mult_m);
}
