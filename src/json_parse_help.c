/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_parse_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 16:49:20 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/30 16:49:20 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			get_flag_object(const char *type)
{
	if (strcmp(type, "sphere") == 0)
		return (sphere);
	else if (strcmp(type, "plane") == 0)
		return (plane);
	else if (strcmp(type, "cone") == 0)
		return (cone);
	else if (strcmp(type, "box") == 0)
		return (box);
	else if (strcmp(type, "disk") == 0)
		return (disk);
	else if (strcmp(type, "cylinder") == 0)
		return (cylinder);
	printf("adding -= %s =-\n", type);
	return (error);
}

int			get_flag_light(const char *type)
{
	printf("___________%s\n", type);
	if (strcmp(type, "global light") == 0)
		return (global_light);
	else if (strcmp(type, "point light") == 0)
		return (point_light);
	else if (strcmp(type, "paralel light") == 0)
		return (paralel_light);
	return (error);
}

t_v3d		get_position(JSON_Object *obj)
{
	t_v3d		pos;
	JSON_Array	*position;

	if (json_object_has_value_of_type(obj, "position", JSONArray))
	{
		position = json_object_get_array(obj, "position");
		pos.x = json_array_get_number(position, 0);
		pos.y = json_array_get_number(position, 1);
		pos.z = json_array_get_number(position, 2);
		printf("adding position [%6.2f, %6.2f, %6.2f]\n", pos.x, pos.y, pos.z);
		return (pos);
	}
	return ((t_v3d){0, 0, 0});
}

t_v3d		get_rotation(JSON_Object *obj)
{
	t_v3d		rot;
	JSON_Array	*rotation;

	if (json_object_has_value_of_type(obj, "rotation", JSONArray))
	{
		rotation = json_object_get_array(obj, "rotation");
		rot.x = json_array_get_number(rotation, 0);
		ft_map(&rot.x, 0, 360);
		rot.y = json_array_get_number(rotation, 1);
		ft_map(&rot.y, 0, 360);
		rot.z = json_array_get_number(rotation, 2);
		ft_map(&rot.z, 0, 360);
		printf("adding rotation [%6.2f, %6.2f, %6.2f]\n", rot.x, rot.y, rot.z);
		return (rot);
	}
	return ((t_v3d){1, 0, 0});
}

t_rgb		get_parsed_color(JSON_Object *obj)
{
	t_rgb		col;
	double_t	r;
	double_t	g;
	double_t	b;
	JSON_Array	*color;

	if (!json_object_has_value_of_type(obj, "color", JSONArray))
		printf("no color\n");
	color = json_object_get_array(obj, "color");
	r = json_array_get_number(color, 0);
	ft_map(&r, 0, 255);
	g = json_array_get_number(color, 1);
	ft_map(&g, 0, 255);
	b = json_array_get_number(color, 2);
	ft_map(&b, 0, 255);
	set_color(&col, (uint8_t)r, (uint8_t)g, (uint8_t)b);
	printf("adding color [%d, %d, %d]\n", (int)col.r, (int)col.g, (int)col.b);
	return (col);
}
