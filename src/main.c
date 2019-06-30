/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 18:31:18 by istalevs          #+#    #+#             */
/*   Updated: 2019/06/28 20:36:06 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int8_t		new_scene(const char *file_name, t_scena *scene)
{
	if (!start_to_parse(file_name, scene))
		return (false);
	return (true);
}

int			main(int argc, char **argv)
{
	t_sdl		*sdl;
	t_scena		scena;

	if (argc != 2)
		return (0);
	srand((unsigned int)time(NULL));
	ft_memset(&scena, 0, sizeof(t_scena));
	sdl = ft_new_sdl();
	if (!new_scene(argv[1], &scena))
		return (error);
	ft_render(sdl, &scena);
	destroy_camera(&scena.cam_p);
	if (sdl)
	{
		ft_del_sdl(sdl);
		free(sdl);
	}
	return (0);
}
