/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 12:04:59 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/26 12:01:47 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		ft_split_del(char **head)
{
	int8_t	i;

	i = 0;
	while (head[i])
	{
		free(head[i]);
		head[i] = NULL;
		i++;
	}
	free(head);
	head = NULL;
}

void		fs_double_swap(double_t *s, double_t *d)
{
	double_t t;

	t = *s;
	*s = *d;
	*d = t;
}

uint32_t	set_pixel_color(t_rgb c, t_hit *hit, t_light *l, t_ray *ray)
{
	t_rgb		result;
	double_t	dist;
	double_t	dist_c;
	double_t	lambert_cof;
	t_rgb		light_color;

	(void)ray;
	result = get_black_color();
	dist = vec_3magnitude(vec_3sub(l->cam_pos, hit->point_hit));
	dist_c = l->power_light / dist;
	lambert_cof = vec_3dot(get_to_light_dir(hit, l), hit->norml_hit) * dist_c;
	result = colort_mult_f(c, lambert_cof);
	light_color = colort_mult_f(l->color, (dist_c * lambert_cof));
	set_rgb_to_int(&light_color);
	result = clr_add_clr(result, light_color);
	return (result.color);
}

void		print_process(void)
{
	static double_t	old_percent = 0;
	static uint32_t	curent_pixel = 0;
	uint32_t		win_size;
	double_t		pr;

	curent_pixel++;
	win_size = WIN_SIZE_W * WIN_SIZE_H;
	pr = (double_t)curent_pixel / win_size;
	pr = (uint32_t)(pr * 100);
	if (old_percent != pr)
		printf("process %d%%\n", (uint32_t)pr);
	old_percent = pr;
}
