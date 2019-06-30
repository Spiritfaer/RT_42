/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 20:43:55 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/26 12:01:47 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMP_H
# define TEMP_H

# include "struct.h"

void		print_v3d(const t_v3d *src, char *str);
void		print_v3i(const t_v3i *src, char *str);
void		ft_print_color(const t_rgb *color);
void		ft_print_plane(const void *data);
void		ft_print_sphere(const void *data);
void		ft_print_box(const void *data);
void		ft_print_cone(const void *data);
void		print_list(t_list *head);
void		print_matrix(double_t **matrix, int32_t n);
void		obj_info(const t_obj *obj);
void		light_info(const t_light *light_list);
void		print_sdl(t_sdl *sdl);
void		ft_split_del(char **head);
void		push_back_list(const char *line, t_list **des);
void		push_back_light(t_light *src, t_light **des);
void		push_back_obj(t_obj *src, t_obj **des);
void		fs_double_swap(double_t *s, double_t *d);
uint32_t	set_pixel_color(t_rgb c, t_hit *hit, t_light *l, t_ray *ray);
t_list		*ft_new_char_list(void const *content, size_t content_size);
void		print_process(void);
void		ft_map(double_t *var, double_t min, double_t max);
float_t		random_col_cof(void);
t_rgb		col_mult_f(t_rgb *src, double_t cof);
t_rgb		col_div_f(t_rgb *src, double_t cof);

#endif
