/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 21:50:07 by amaurer           #+#    #+#             */
/*   Updated: 2015/04/28 22:12:02 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"
#include <libft.h>

static void	hook_key2(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_SCALE_DOWN_X)
		action_scale_x(fdf, -1);
	else if (keycode == KEY_SCALE_UP_Y)
		action_scale_y(fdf, 1);
	else if (keycode == KEY_SCALE_DOWN_Y)
		action_scale_y(fdf, -1);
	else if (keycode == KEY_SCALE_UP_Z)
		action_scale_z(fdf, 1);
	else if (keycode == KEY_SCALE_DOWN_Z)
		action_scale_z(fdf, -1);
	else if (keycode == KEY_CENTER)
		action_center(fdf);
	else if (keycode == KEY_TOGGLE_CENTER)
		action_toggle_center(fdf);
	else if (keycode == KEY_TOGGLE_COLORS)
		action_toggle_colors(fdf);
	else if (keycode == KEY_RESET)
		action_reset(fdf);
}

int			hook_key(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESCAPE)
		exit(0);
	else if (keycode == KEY_MOVE_UP)
		action_move(fdf, 0, 1);
	else if (keycode == KEY_MOVE_DOWN)
		action_move(fdf, 0, -1);
	else if (keycode == KEY_MOVE_RIGHT)
		action_move(fdf, 1, 0);
	else if (keycode == KEY_MOVE_LEFT)
		action_move(fdf, -1, 0);
	else if (keycode == KEY_ZOOM_IN)
		action_scale(fdf, 1);
	else if (keycode == KEY_ZOOM_OUT)
		action_scale(fdf, -1);
	else if (keycode == KEY_SCALE_UP_X)
		action_scale_x(fdf, 1);
	else
		hook_key2(keycode, fdf);
	return (0);
}

int			hook_expose(t_fdf *fdf)
{
	action_center(fdf);
	draw(fdf);
	return (0);
}

void		mlx_hooks_init(t_fdf *fdf)
{
	mlx_key_hook(fdf->graphics.win, hook_key, fdf);
	mlx_expose_hook(fdf->graphics.win, hook_expose, fdf);
}
