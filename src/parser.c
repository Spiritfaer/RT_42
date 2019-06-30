/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:26:00 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/24 12:09:56 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		set_count(int8_t *index, int8_t type)
{
	if (type >= plane && type <= disk)
		*index = 6;
	else if (type == cylinder || type == cone)
		*index = 7;
	else if (type == camera)
		*index = 5;
	else if (type >= global_light && type <= paralel_light)
		*index = 3;
	else
		*index = 0;
}

void		help_pars_info(const void *data, t_parser *var)
{
	if (ft_strnequ(data, "pos:", 4) || ft_strnequ(data, "pa:", 3))
		pars_pos(data, &var->pa, &var->flag);
	else if (ft_strnequ(data, "cov:", 4) || ft_strnequ(data, "pb:", 3))
		pars_pos(data, &var->pb, &var->flag);
	else if (ft_strnequ(data, "rot:", 4))
		pars_pos(data, &var->rot, &var->flag);
	else if (ft_strnequ(data, "color:", 6) || ft_strnequ(data, "bg:", 3))
		pars_color(data, &var->color, &var->flag);
	else if (ft_strnequ(data, "size:", 5) || ft_strnequ(data, "fov:", 4)
	|| ft_strnequ(data, "power:", 6))
		pars_size(data, &var->size, &var->flag);
	else if (ft_strnequ(data, "reflection:", 11))
		pars_size(data, &var->reflection, &var->flag);
	else if (ft_strnequ(data, "albus:", 6))
		pars_size(data, &var->albus, &var->flag);
	else
		var->flag = error;
}

void		pars_info(t_list **list, t_parser *var)
{
	int8_t	i;

	if ((var->flag = pars_type(list)) != -1)
	{
		set_count(&i, var->flag);
		while (i-- && (*list)->next && var->flag != error)
		{
			(*list) = (*list)->next;
			help_pars_info((*list)->content, var);
		}
	}
}

void		init_obj(t_scena *scena, t_parser *var)
{
	if (var->flag == sphere)
		push_back_obj(ft_new_sphere(var), &scena->obj_list);
	else if (var->flag == plane)
		push_back_obj(ft_new_plane(var), &scena->obj_list);
	else if (var->flag == disk)
		push_back_obj(ft_new_plane(var), &scena->obj_list);
	else if (var->flag == box)
		push_back_obj(ft_new_box(var), &scena->obj_list);
	else if (var->flag == cone)
		push_back_obj(ft_new_cone(var), &scena->obj_list);
	else if (var->flag == cylinder)
		push_back_obj(ft_new_cylinder(var), &scena->obj_list);
	else if (var->flag >= global_light && var->flag <= paralel_light)
		push_back_light(new_light(var), &scena->light_list);
	else if (var->flag == camera)
		scena->cam_p = new_camera(var);
	else
		write(1, "init_obj error!\n", 7);
}

int8_t		pars_file(const char *file_name, t_scena *scene)
{
	int32_t	fd;
	char	*line;

	line = NULL;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (false);
	while (get_next_line(fd, &line))
	{
		push_back_list(line, &scene->head_list);
		free(line);
	}
	close(fd);
	return (true);
}
