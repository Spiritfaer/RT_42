/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_parse_help2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 16:45:05 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/30 16:45:06 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

double_t	get_albus(JSON_Object *obj)
{
	double_t	albus;

	if (json_object_has_value_of_type(obj, "albus", JSONNumber))
	{
		albus = json_object_get_number(obj, "albus");
		ft_map(&albus, 0, 1);
		printf("adding albus : %6.2f\n", albus);
		return (albus);
	}
	return (0.0);
}

double_t	get_power(JSON_Object *obj)
{
	double_t	power;

	if (json_object_has_value_of_type(obj, "power", JSONNumber))
	{
		power = json_object_get_number(obj, "power");
		power = (power < 0) ? 0 : power;
		printf("adding power : %6.2f\n", power);
		return (power);
	}
	return (0.0);
}

int			if_analias(JSON_Object *obj)
{
	double_t	antialiasing;

	if (json_object_has_value_of_type(obj, "antialiasing", JSONNumber))
	{
		antialiasing = json_object_get_number(obj, "antialiasing");
		antialiasing = (antialiasing != 1) ? 0 : 1;
		printf("adding antialiasing : %6.2f\n", antialiasing);
		return ((int32_t)antialiasing);
	}
	return (0);
}

t_v3d		get_cup_pos(JSON_Object *obj)
{
	t_v3d		cup;
	JSON_Array	*pb;

	if (json_object_has_value_of_type(obj, "cup point", JSONArray))
	{
		pb = json_object_get_array(obj, "cup point");
		cup.x = json_array_get_number(pb, 0);
		cup.y = json_array_get_number(pb, 1);
		cup.z = json_array_get_number(pb, 2);
		printf("adding cupition [%6.2f, %6.2f, %6.2f]\n", cup.x, cup.y, cup.z);
		return (cup);
	}
	printf("no cup point\n");
	return ((t_v3d){0, 0, 0});
}

double_t	get_reflection(JSON_Object *obj)
{
	double_t	reflect;

	if (json_object_has_value_of_type(obj, "reflection", JSONNumber))
	{
		reflect = json_object_get_number(obj, "reflection");
		ft_map(&reflect, 0, 1);
		printf("adding reflection : %6.2f\n", reflect);
		return (reflect);
	}
	return (0);
}
