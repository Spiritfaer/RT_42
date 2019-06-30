/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:26:12 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/09 11:42:30 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int8_t		pars_pos(const char *str, t_v3d *pos, int8_t *type)
{
	char	**split;

	if (ft_splitter(str, ' ') != 4 || *(str + ft_strlen(str) - 1) != ';')
	{
		*type = error;
		return (false);
	}
	split = ft_strsplit(str, ' ');
	pos->x = ft_atof(split[1]);
	pos->y = ft_atof(split[2]);
	pos->z = ft_atof(split[3]);
	ft_split_del(split);
	return (true);
}

int8_t		pars_color(const char *str, t_rgb *color, int8_t *type)
{
	char	**split;
	int32_t	tmp;

	if (ft_splitter(str, ' ') != 4 || *(str + ft_strlen(str) - 1) != ';')
	{
		*type = error;
		return (false);
	}
	split = ft_strsplit(str, ' ');
	tmp = ft_atoi(split[1]);
	color->r = int_to_char(tmp);
	tmp = ft_atoi(split[2]);
	color->g = int_to_char(tmp);
	tmp = ft_atoi(split[3]);
	color->b = int_to_char(tmp);
	set_rgb_to_int(color);
	ft_split_del(split);
	return (true);
}

int8_t		pars_size(const char *str, double_t *src, int8_t *type)
{
	char	**split;

	if (ft_splitter(str, ' ') != 2 || *(str + ft_strlen(str) - 1) != ';')
	{
		*type = error;
		return (false);
	}
	split = ft_strsplit(str, ' ');
	*src = ft_atof(split[1]);
	ft_split_del(split);
	return (true);
}

int8_t		pars_type(t_list **list)
{
	if (!list || !*list)
		return (error);
	if (ft_strnequ((((char*)((*list)->content)) + 6), "sphere;", 7))
		return (sphere);
	else if (ft_strnequ((((char*)((*list)->content)) + 6), "plane;", 6))
		return (plane);
	else if (ft_strnequ((((char*)((*list)->content)) + 6), "disk;", 5))
		return (disk);
	else if (ft_strnequ((((char*)((*list)->content)) + 6), "box;", 4))
		return (box);
	else if (ft_strnequ((((char*)((*list)->content)) + 6), "cone;", 5))
		return (cone);
	else if (ft_strnequ((((char*)((*list)->content)) + 6), "cylinder;", 9))
		return (cylinder);
	else if (ft_strnequ((((char*)((*list)->content)) + 6), "point light;", 12))
		return (point_light);
	else if (ft_strnequ((((char*)((*list)->content)) + 6),
			"paralel light;", 14))
		return (paralel_light);
	else if (ft_strnequ((((char*)((*list)->content)) + 6), "global light;", 13))
		return (global_light);
	else if (ft_strnequ((((char*)((*list)->content)) + 6), "camera;", 7))
		return (camera);
	else
		return (error);
}

int8_t		parser(t_scena *scena)
{
	t_list		*tmp;
	t_parser	var;

	tmp = scena->head_list;
	while (tmp)
	{
		if (ft_strnequ(tmp->content, "type:", 5))
		{
			pars_info(&tmp, &var);
			if (!tmp->next
			|| !ft_strnequ(tmp->next->content, "end;", 4)
			|| var.flag == error)
				return (error);
			else
				tmp = tmp->next;
			init_obj(scena, &var);
		}
		else if (ft_strnequ(tmp->content, "end;", 4))
			tmp = tmp->next;
		else
			return (false);
	}
	return (true);
}
