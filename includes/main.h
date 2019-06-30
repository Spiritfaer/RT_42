/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 20:43:23 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/28 18:42:56 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <pthread.h>
# include <errno.h>

# include "SDL_image.h"
# include "get_next_line.h"
# include "vmth.h"
# include "obj.h"
# include "temp.h"
# include "struct.h"
# include "parson.h"

# define MAX_DEPTH 3
# define WIN_SIZE_W 768u
# define WIN_SIZE_H 768u

enum		e_bool {false, true};
enum		e_ray_type {primary, shadow, ReflectionAndRefraction};
enum		e_key_press_surf {menu_main, menu_blwh, menu_anal, menu_b_an};

t_sdl		*ft_new_sdl(void);
void		ft_del_sdl(t_sdl *sdl);
int8_t		ft_init_sdl(t_sdl *sdl);
SDL_Surface *new_canvas(uint32_t width, uint32_t height);
t_obj		*ft_new_sphere(t_parser *var);
int8_t		ft_sphere_intersect(t_ray *ray, const void *data, t_hit *hit);
t_rgb		ft_get_sphere_color(const void *data);
t_v3d		ft_get_center_sphere(const void *data);
t_v3d		ft_get_sphere_n_hit(t_ray *ray, t_hit *hit, struct s_obj *obj);
double_t	ft_get_sphere_reflection(const void *data);
double_t	ft_get_sphere_albus(const void *data);
t_obj		*ft_new_plane(t_parser *var);
int8_t		ft_plane_intersect(t_ray *ray, const void *data, t_hit *hit);
t_v3d		ft_plane_intersect_n(t_ray *ray, t_hit *hit, struct s_obj *obj);
t_v3d		ft_get_center_plane(const void *data);
t_rgb		ft_get_plane_color(const void *data);
double_t	ft_get_plane_reflection(const void *data);
double_t	ft_get_plane_albus(const void *data);
t_obj		*ft_new_box(t_parser *var);
int8_t		ft_set_box_mem(t_obj **obj, t_box **b);
void		ft_box_var(t_ray *src, t_aabb_ray *dest, t_v3d *b, const void *d);
void		ft_del_box(t_obj **obj);
double_t	ft_get_box_albus(const void *data);
t_v3d		ft_set_box_centr(t_box *box);
t_rgb		ft_get_box_color(const void *data);
double_t	ft_get_box_reflection(const void *data);
t_v3d		ft_get_box_centr(const void *data);
int8_t		ft_box_intersect(t_ray *ray, const void *data, t_hit *hit);
t_v3d		ft_box_intersect_n(t_ray *ray, t_hit *hit, struct s_obj *obj);
void		ft_set_box_min_max(t_box *box);
t_obj		*ft_new_cylinder(t_parser *var);
t_v3d		ft_get_cylinder_n_hit(t_ray *ray, t_hit *hit,
				struct s_obj *obj);
double_t	ft_get_cylinder_reflection(const void *data);
double_t	ft_get_cylinder_albus(const void *data);
t_v3d		ft_get_center_cylinder(const void *data);
t_rgb		ft_get_cylinder_color(const void *data);
double_t	ft_get_cone_reflection(const void *data);
double_t	ft_get_cone_albus(const void *data);
t_v3d		ft_get_center_cone(const void *data);
t_rgb		ft_get_cone_color(const void *data);
void		ft_init_cone_1_math_var(t_c_m *v, t_ray *ray, const void *data);
void		ft_init_cone_2_math_var(t_c_m *v);
int8_t		ft_cone_up_cup(t_c_m *v, t_hit *t);
int8_t		ft_cone_dawn_cup(t_c_m *v, t_hit *hit);
int8_t		ft_cone_body(t_c_m *v, t_hit *hit);
void		event_guard(t_sdl *sdl, t_scena *sc, t_time *time);
uint8_t		move_camera(const uint8_t *cur_key, t_matrix *camera, t_time *time);
void		time_tick(t_time *t);
void		ft_render(t_sdl *sdl, t_scena *scene);
void		ft_draw(const t_sdl *sdl, const t_scena *scene);
t_rgb		cast_ray(const t_sdl *sdl, const t_scena *s,
						t_ray *r, int16_t dth);
void		set_var(t_dr_m *v, const t_sdl *sdl);
void		cast_var_init(t_hit *hit, t_rgb *color, t_ray *reflect);
int8_t		ft_trace(t_hit *hit, t_obj *index_obj, t_ray *ray);
void		light_pixel(const t_scena *s, t_hit *hit,
						t_rgb *color, t_ray *ray);
t_camera	*new_camera(t_parser *var);
void		destroy_camera(t_camera **camera);
void		camera_to(t_camera *camera, t_parser *var);
t_v3d		get_cam_pos(t_camera *cam);
t_light		*new_light(t_parser *var);
t_v3d		get_to_light_dir(t_hit *hit, t_light *light);
int8_t		new_scene(const char *file_name, t_scena *scene);
int8_t		parser(t_scena *scene);
void		pars_info(t_list **list, t_parser *var);
int8_t		pars_size(const char *str, double_t *src, int8_t *type);
int8_t		pars_color(const char *str, t_rgb *color, int8_t *type);
int8_t		pars_pos(const char *str, t_v3d *pos, int8_t *type);
int8_t		pars_type(t_list **list);
void		init_obj(t_scena *scena, t_parser *var);
int8_t		pars_file(const char *file_name, t_scena *scene);
int8_t		ft_solve_quadratic(t_v3d *abc, t_v2d *tt);
t_obj		*ft_new_cone(t_parser *var);
void		**in_th(const t_sdl *sdl,
					const t_scena *s, void *p, double_t **m);
uint32_t	base_ray(const t_sdl *sdl, const t_scena *scena, t_dr_m *v);
void		init_aa_ray_var(t_aa_var *var);
uint32_t	aa_ray(const t_sdl *sdl,
					const t_scena *s, t_dr_m *v, t_v2i i);

int			get_flag_object(const char *type);
int			get_camera_parsed(JSON_Object *cam, t_scena *scena);
int			get_object_parsed(JSON_Object *obj, t_scena *scena);
int			parse_objects(JSON_Object *obj, t_scena *scena);
double_t	get_albus(JSON_Object *obj);
int			get_light_parsed(JSON_Object *light, t_scena *scena);
t_v3d		get_cup_pos(JSON_Object *obj);
double_t	get_reflection(JSON_Object *obj);
double_t	get_size(JSON_Object *obj);
double_t	get_fov(JSON_Object *cam);
int			get_flag_light(const char *type);
t_v3d		get_position(JSON_Object *obj);
t_v3d		get_rotation(JSON_Object *obj);
t_v3d		get_cof(JSON_Object *obj);
double_t	get_power(JSON_Object *obj);
int			start_to_parse(const char *file, t_scena *scena);
t_rgb		get_parsed_color(JSON_Object *obj);
int			if_analias(JSON_Object *obj);
int			is_object_ok(JSON_Object *obj);
int			is_light_ok(JSON_Object *light);
int			is_camera_ok(JSON_Object *cam);
int			find_obj(t_json *tmp, JSON_Object *obj, t_scena *scena);
int			find_light(t_json *tmp, JSON_Object *obj, t_scena *scena);

int			get_image(JSON_Object *obj, t_parser *par);
int			set_img_cord_to_sphere(t_v3d p, t_sphere *sp);
int			init_menu(t_sdl *sdl, int menu);
void		menu_click_box(t_sdl *sdl, int x, int y, t_camera *cam);
t_rgb		b_n_w_mode(t_rgb src);

#endif
