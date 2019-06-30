/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 10:34:16 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/24 12:17:54 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		camera_rot(t_camera *camera, t_v3d *forward, t_parser *var)
{
	vec_3drotate(forward, camera->rotation);
	var->pb = vec_3add(var->pa, *forward);
}

void		camera_to(t_camera *camera, t_parser *var)
{
	t_v3d	up;
	t_v3d	forward;
	t_v3d	right;

	up = vec_1up();
	vec_3drot(&up, Z, camera->rotation.z);
	if (!vec_3magnitude(vec_3sub(var->pa, var->pb)))
		var->pb.z -= camera->fov;
	forward = vec_3norm(vec_3sub(var->pa, var->pb));
	camera_rot(camera, &forward, var);
	right = vec_3dcross_prod(&up, &forward);
	up = vec_3dcross_prod(&forward, &right);
	camera->cam->matrix[0][0] = right.x;
	camera->cam->matrix[0][1] = right.y;
	camera->cam->matrix[0][2] = right.z;
	camera->cam->matrix[1][0] = up.x;
	camera->cam->matrix[1][1] = up.y;
	camera->cam->matrix[1][2] = up.z;
	camera->cam->matrix[2][0] = forward.x;
	camera->cam->matrix[2][1] = forward.y;
	camera->cam->matrix[2][2] = forward.z;
	camera->cam->matrix[3][0] = var->pa.x;
	camera->cam->matrix[3][1] = var->pa.y;
	camera->cam->matrix[3][2] = var->pa.z;
}

t_v3d		get_cam_pos(t_camera *cam)
{
	return ((t_v3d){cam->cam->matrix[3][0],
					cam->cam->matrix[3][1],
					cam->cam->matrix[3][2]});
}

t_camera	*new_camera(t_parser *var)
{
	t_camera	*camera;

	if ((camera = (t_camera*)malloc(sizeof(t_camera))) == NULL)
		return (NULL);
	memset(camera, 0, sizeof(t_camera));
	camera->fov = var->size;
	camera->rotation = var->rot;
	camera->on = 1;
	camera->scale = tan(deg_to_rad(camera->fov * 0.5));
	camera->cam = get_new_matrix(4);
	fill_vertical_matrix(camera->cam);
	camera_to(camera, var);
	camera->center_of_view = var->pb;
	print_matrix(camera->cam->matrix, camera->cam->size);
	camera->cam->inv_matrix = NULL;
	camera->bg_color = var->color;
	camera->aa = var->analias;
	printf("camera added\n");
	return (camera);
}

void		destroy_camera(t_camera **camera)
{
	destroy_matrix(&((*camera)->cam));
	free(*camera);
	*camera = NULL;
}
