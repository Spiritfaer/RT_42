/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_1back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 14:23:47 by istalevs          #+#    #+#             */
/*   Updated: 2018/05/20 14:24:54 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vmth.h"

t_v3d		vec_1back(void)
{
	t_v3d	new;

	new = (t_v3d){0, 0, 1};
	return (new);
}
