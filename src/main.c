/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 18:19:10 by amaurer           #+#    #+#             */
/*   Updated: 2015/04/28 22:15:24 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <libft.h>
#include <stdlib.h>

static void	usage(void)
{
	ft_putendl("usage: fdf map.fdf");
}

int			main(int argc, char **argv)
{
	t_fdf	fdf;

	fdf.gfx = &(fdf.graphics);
	fdf.width = 0;
	fdf.height = 0;
	fdf.scale_x = DEFAULT_SCALE_X;
	fdf.scale_y = DEFAULT_SCALE_Y;
	fdf.scale_z = DEFAULT_SCALE_Z;
	fdf.global_scale = DEFAULT_GLOBAL_SCALE;
	fdf.auto_center = 1;
	fdf.use_colors = 0;
	if (argc == 2)
	{
		parse(&fdf, argv[1]);
		update_points(&fdf);
		mlx_initialize(&fdf);
	}
	else
		usage();
	return (EXIT_SUCCESS);
}
