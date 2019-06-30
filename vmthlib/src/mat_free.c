/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 18:55:04 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/07 18:55:07 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vmth.h"

void			free_mat(double_t **data, int32_t size)
{
	if (!data)
		return ;
	while (--size >= 0)
	{
		if (*(data + size) != NULL)
		{
			free(*(data + size));
			*(data + size) = NULL;
		}
	}
}

void			destroy_matrix(t_matrix **m)
{
	if (!(*m))
		return ;
	if ((*m)->matrix != NULL)
	{
		free_mat((*m)->matrix, (*m)->size);
		free((*m)->matrix);
		(*m)->matrix = NULL;
	}
	if ((*m)->inv_matrix != NULL)
	{
		free_mat((*m)->inv_matrix, (*m)->size);
		free((*m)->inv_matrix);
		(*m)->inv_matrix = NULL;
	}
	free(*m);
	*m = NULL;
}
