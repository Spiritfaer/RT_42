/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_parse_scene_objects.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 16:55:25 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/30 16:55:26 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		start_to_parse(const char *file, t_scena *scena)
{
	JSON_Value	*root_value;
	JSON_Object	*list_ob;

	root_value = json_parse_file(file);
	list_ob = json_value_get_object(root_value);
	if (json_value_get_type(root_value) != JSONObject)
		return (false);
	if (!parse_objects(list_ob, scena))
		return (false);
	json_value_free(root_value);
	return (true);
}

int		get_camera_parsed(JSON_Object *cam, t_scena *scena)
{
	t_parser	par;

	if (!is_camera_ok(cam))
		return (false);
	par.flag = camera;
	par.color = get_parsed_color(cam);
	par.size = get_fov(cam);
	par.pa = get_position(cam);
	par.pb = get_cof(cam);
	par.rot = get_rotation(cam);
	par.analias = if_analias(cam);
	init_obj(scena, &par);
	return (true);
}

int		get_object_parsed(JSON_Object *obj, t_scena *scena)
{
	t_parser	par;
	const char	*type;

	if (!is_object_ok(obj))
		return (false);
	type = json_object_get_string(obj, "type");
	par.img = NULL;
	if (json_object_has_value_of_type(obj, "image", JSONString))
		get_image(obj, &par);
	par.flag = get_flag_object(type);
	par.albus = get_albus(obj);
	par.pa = get_position(obj);
	par.pb = get_cup_pos(obj);
	par.reflection = get_reflection(obj);
	par.color = get_parsed_color(obj);
	par.size = get_size(obj);
	par.rot = get_rotation(obj);
	init_obj(scena, &par);
	return (true);
}

int		parse_objects(JSON_Object *obj, t_scena *scena)
{
	t_json tmp;

	if (!json_object_has_value_of_type(obj, "Camera", JSONObject))
		return (false);
	find_obj(&tmp, obj, scena);
	find_light(&tmp, obj, scena);
	tmp.object = json_object_get_object(obj, "Camera");
	if (!get_camera_parsed(tmp.object, scena))
		return (false);
	return (true);
}

int		get_light_parsed(JSON_Object *light, t_scena *scena)
{
	t_parser	par;
	const char	*type;

	if (!is_light_ok(light))
		return (false);
	type = json_object_get_string(light, "type");
	par.flag = get_flag_light(type);
	par.pa = get_position(light);
	par.color = get_parsed_color(light);
	par.size = get_power(light);
	init_obj(scena, &par);
	return (true);
}
