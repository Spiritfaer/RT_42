/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_parse_help4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 16:52:42 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/30 16:52:43 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_v3d		get_cof(JSON_Object *obj)
{
	t_v3d		pos;
	JSON_Array	*cov;

	if (json_object_has_value_of_type(obj, "cov", JSONArray))
	{
		cov = json_object_get_array(obj, "cov");
		pos.x = json_array_get_number(cov, 0);
		pos.y = json_array_get_number(cov, 1);
		pos.z = json_array_get_number(cov, 2);
		printf("adding COV [%6.2f, %6.2f, %6.2f]\n", pos.x, pos.y, pos.z);
		return (pos);
	}
	return ((t_v3d){0, 0, 0});
}

int			get_image(JSON_Object *obj, t_parser *par)
{
	const char	*img_path;

	par->img = NULL;
	if (json_object_has_value_of_type(obj, "image", JSONString))
	{
		img_path = json_object_get_string(obj, "image");
		printf("PATH = %s\n", img_path);
		par->img = IMG_Load(img_path);
		if (!par->img)
			return (0);
	}
	else
		par->img = NULL;
	return (1);
}

int			find_obj(t_json *tmp, JSON_Object *obj, t_scena *scena)
{
	tmp->i = 0;
	tmp->value = json_object_get_value(obj, "Objects");
	tmp->list_ob = json_value_get_array(tmp->value);
	while (tmp->i < json_array_get_count(tmp->list_ob))
	{
		printf("\n--- Parsing objects ---\n");
		tmp->object = json_array_get_object(tmp->list_ob, tmp->i);
		if (!get_object_parsed(tmp->object, scena))
			return (false);
		tmp->i++;
	}
	return (true);
}

int			find_light(t_json *tmp, JSON_Object *obj, t_scena *scena)
{
	tmp->i = 0;
	tmp->value = json_object_get_value(obj, "Lights");
	tmp->list_ob = json_value_get_array(tmp->value);
	while (tmp->i < json_array_get_count(tmp->list_ob))
	{
		printf("\n--- Parsing lights ---\n");
		tmp->object = json_array_get_object(tmp->list_ob, tmp->i);
		if (!get_light_parsed(tmp->object, scena))
			return (false);
		tmp->i++;
	}
	return (true);
}
