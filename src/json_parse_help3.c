/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_parse_help3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 16:48:49 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/30 16:48:49 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			is_camera_ok(JSON_Object *cam)
{
	if (!json_object_has_value_of_type(cam, "position", JSONArray) ||
		!json_object_has_value_of_type(cam, "rotation", JSONArray) ||
		!json_object_has_value_of_type(cam, "fov", JSONNumber))
		return (false);
	return (true);
}

int			is_light_ok(JSON_Object *light)
{
	if (!json_object_has_value_of_type(light, "type", JSONString) ||
		!json_object_has_value_of_type(light, "position", JSONArray) ||
		!json_object_has_value_of_type(light, "color", JSONArray))
		return (false);
	return (true);
}

int			is_object_ok(JSON_Object *obj)
{
	if (!json_object_has_value_of_type(obj, "type", JSONString) ||
		!json_object_has_value_of_type(obj, "position", JSONArray) ||
		!json_object_has_value_of_type(obj, "color", JSONArray) ||
		!json_object_has_value_of_type(obj, "size", JSONNumber) ||
		!json_object_has_value_of_type(obj, "reflection", JSONNumber))
		return (false);
	return (true);
}

double_t	get_size(JSON_Object *obj)
{
	double_t	size;

	if (json_object_has_value_of_type(obj, "size", JSONNumber))
	{
		size = json_object_get_number(obj, "size");
		return ((size < 0) ? 1 : size);
	}
	return (1);
}

double_t	get_fov(JSON_Object *cam)
{
	double_t	fov;

	if (json_object_has_value_of_type(cam, "fov", JSONNumber))
	{
		fov = json_object_get_number(cam, "fov");
		ft_map(&fov, 45, 120);
		return (fov);
	}
	return (60);
}
