/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 20:44:12 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/24 11:45:23 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_H
# define OBJ_H

# include "vmth.h"
# include "color.h"

enum				e_type_flag {
	error = -1, plane, sphere, box, disk, cone, cylinder,
	camera, global_light, point_light, paralel_light
};

typedef struct		s_sphere
{
	t_v3d			world_centr;
	t_v3d			world_norm;
	t_v3d			cam_norm;
	t_rgb			color;
	double_t		radius;
	double_t		rad2;
	double_t		reflection;
	double_t		albus;
	SDL_Surface		*img;
}					t_sphere;

typedef struct		s_plane
{
	t_v3d			world_normal;
	t_v3d			world_centr;
	t_rgb			color;
	double_t		size;
	double_t		s2;
	double_t		reflection;
	double_t		albus;
}					t_plane;

typedef struct		s_box
{
	t_v3d			min;
	t_v3d			max;
	t_v3d			centr;
	t_v3d			world_norm;
	double_t		size;
	t_rgb			color;
	double_t		reflection;
	double_t		albus;
}					t_box;

typedef struct		s_cone
{
	t_v3d			world_start;
	t_v3d			world_end;
	t_v3d			world_normal;
	t_rgb			color;
	double_t		radius;
	double_t		reflection;
	double_t		albus;
	double			size;
}					t_cone;

typedef struct		s_cylinder
{
	t_v3d			world_start;
	t_v3d			world_end;
	t_v3d			world_normal;
	double_t		radius;
	t_rgb			color;
	double_t		reflection;
	double_t		albus;
	t_v3d			centr;
	t_v3d			cam_centr;
	t_v3d			v;
}					t_cylinder;

typedef	struct		s_light
{
	t_v3d			pos;
	t_v3d			cam_pos;
	t_rgb			color;
	t_v3d			dir;
	t_rgb			light_color;
	double_t		power_light;
	t_v3d			intensity_light;
	double_t		r2;
	t_v3d			invdir;
	int8_t			type;
	t_matrix		*transform;
	struct s_light	*next;
}					t_light;

#endif
