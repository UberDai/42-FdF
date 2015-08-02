/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 21:04:30 by amaurer           #+#    #+#             */
/*   Updated: 2015/04/27 19:50:07 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

void	mlx_initialize(t_fdf *fdf)
{
	t_graphics	*g;

	g = fdf->gfx;
	g->mlx = mlx_init();
	if (!g->mlx)
		die("Count not init mlx");
	if (!(g->win = mlx_new_window(g->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF")))
		die("Could not create the window.");
	if (!(g->img = mlx_new_image(g->mlx, WINDOW_WIDTH, WINDOW_HEIGHT)))
		die("Could not create the image.");
	g->data = mlx_get_data_addr(g->img, &g->bpp, &g->line_size, &g->endian);
	if (!g->data)
		die("Could not get image data.");
	mlx_hooks_init(fdf);
	mlx_loop(g->mlx);
}

void	mlx_update(t_graphics *gfx)
{
	mlx_put_image_to_window(gfx->mlx, gfx->win, gfx->img, 0, 0);
}
