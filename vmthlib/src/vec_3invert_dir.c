/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_3invert_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 18:49:58 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/07 18:50:01 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vmth.h"

t_v3d		vec_3invert_dir(const t_v3d *dir)
{
	t_v3d inv_dir;

	inv_dir.x = dir->x * -1;
	inv_dir.y = dir->y * -1;
	inv_dir.z = dir->z * -1;
	return (inv_dir);
}
