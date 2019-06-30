/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 20:43:39 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/28 16:32:28 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <parson.h>
# include "vmth.h"
# include "color.h"
# define THREAD_N 6
# define _INF (DBL_MAX*2)

typedef struct		s_aabb_ray
{
	t_v3d			invdir;
	int8_t			flag[3];
}					t_aabb_ray;

typedef struct		s_ray
{
	t_v3d			orig;
	t_v3d			dir;
	int16_t			type;
}					t_ray;

typedef struct		s_hit
{
	t_v3d			point_hit;
	t_v3d			norml_hit;
	t_v3d			norml_hit_near;
	t_rgb			color_hit;
	struct s_obj	*hit_obj;
	struct s_obj	*hit_obj_near;
	double_t		t_near;
	double_t		t;
	double_t		bias;
}					t_hit;

typedef struct		s_time
{
	double_t		old_time;
	double_t		time;
	double_t		frame_time;
	double_t		speed;
}					t_time;

typedef struct		s_camera
{
	t_matrix		*cam;
	double_t		fov;
	double_t		scale;
	uint8_t			on;
	t_v3d			center_of_view;
	t_v3d			rotation;
	t_rgb			bg_color;
	int8_t			aa:1;
}					t_camera;

typedef struct		s_scena
{
	struct s_obj	*obj_list;
	t_light			*light_list;
	t_camera		*cam_p;
	t_list			*head_list;
}					t_scena;

typedef struct		s_sdl
{
	t_time			time;
	int8_t			init_flag;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*screen_tx;
	SDL_Surface		*canvas;
	SDL_Event		event;
	const uint8_t	*cur_key;
	char			*win_name;
	t_v2i			screen_s;
	double_t		iar;
	int8_t			loop;
	int8_t			menu;
	int8_t			menu_ba;
	int8_t			menu_an;
	int8_t			menu_bw;
	int8_t			b_n_w_mode;
}					t_sdl;

typedef struct		s_parser
{
	t_rgb			color;
	t_v3d			rot;
	t_v3d			pa;
	t_v3d			pb;
	double_t		size;
	double_t		reflection;
	double_t		albus;
	int8_t			flag;
	SDL_Surface		*img;
	int8_t			analias:1;
}					t_parser;

typedef struct		s_obj
{
	void			*data;
	int8_t			(*intersect)(t_ray *ray, const void *data, t_hit* hit);
	t_rgb			(*get_color)(const void *data);
	t_v3d			(*get_center)(const void *data);
	t_v3d			(*get_n_hit)(t_ray *ray, t_hit *hit, struct s_obj *obj);
	double_t		(*get_reflection)(const void *data);
	double_t		(*get_albus)(const void *data);
	void			(*to_camera)(const t_matrix *camera, void *src);
	uint8_t			flag;
	struct s_obj	*next;
}					t_obj;

typedef struct		s_cone_mat
{
	t_cone			*cone;
	t_v3d			ro;
	t_v3d			rd;
	t_v3d			pa;
	t_v3d			pb;
	t_v3d			ba;
	t_v3d			oa;
	t_v3d			ob;
	t_v3d			tmp_1;
	t_v3d			tmp_2;
	double_t		ra;
	double_t		rb;
	double_t		m0;
	double_t		m1;
	double_t		m2;
	double_t		m3;
	double_t		m4;
	double_t		m5;
	double_t		rr;
	double_t		hy;
	double_t		k2;
	double_t		k1;
	double_t		k0;
	double_t		h;
	double_t		y;
}					t_c_m;

typedef struct		s_cylinder_mat
{
	t_cylinder		*cyl;
	t_v3d			ro;
	t_v3d			rd;
	t_v3d			pa;
	t_v3d			pb;
	t_v3d			ba;
	t_v3d			oc;
	t_v3d			one;
	t_v3d			two;
	double_t		ra;
	double_t		baba;
	double_t		bard;
	double_t		baoc;
	double_t		k2;
	double_t		k1;
	double_t		k0;
	double_t		h;
	double_t		y;
}					t_cl_m;

typedef struct		s_light_mat
{
	t_rgb			tmp;
	t_hit			lhit;
	t_ray			reflect;
	t_ray			to_light;
	t_light			*i_light;
	double_t		light_cof;
	double_t		dist;
	double_t		test_in;
	double_t		r_dot_d;
	double_t		spec;

}					t_l_m;

typedef struct		s_draw_mat
{
	const t_sdl		*sdl;
	const t_scena	*scena;
	t_ray			ray;
	t_v3d			p;
	t_v2i			i;
	t_rgb			p_clr;
	uint32_t		*pixel_buffer;
	int32_t			start;
	int32_t			end;
}					t_dr_m;

typedef struct		s_json
{
	JSON_Value		*value;
	JSON_Array		*list_ob;
	JSON_Object		*object;
	uint32_t		i;
}					t_json;

typedef struct		s_aa_var
{
	float_t			step_map[3];
	int32_t			size_map;
	float_t			high_cof;
	float_t			low_cof;
	t_rgb			tmp;
}					t_aa_var;

#endif
