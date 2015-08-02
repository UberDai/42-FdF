/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/24 18:09:42 by amaurer           #+#    #+#             */
/*   Updated: 2015/04/28 22:31:00 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <libft.h>
#include <limits.h>

static void	action_center_get_size(t_fdf *fdf, int limit_x[], int limit_y[])
{
	t_uint	x;
	t_uint	y;
	t_pt	*pt;

	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			pt = &(fdf->map[y][x]);
			if (pt->x_2d < limit_x[0])
				limit_x[0] = pt->x_2d;
			if (pt->x_2d > limit_x[1])
				limit_x[1] = pt->x_2d;
			if (pt->y_2d < limit_y[0])
				limit_y[0] = pt->y_2d;
			else if (pt->y_2d > limit_y[1])
				limit_y[1] = pt->y_2d;
			x++;
		}
		y++;
	}
}

void		center(t_fdf *fdf)
{
	int		limit_x[2];
	int		limit_y[2];
	int		width;
	int		height;

	limit_x[0] = INT_MAX;
	limit_x[1] = INT_MIN;
	limit_y[0] = INT_MAX;
	limit_y[1] = INT_MIN;
	update_points(fdf);
	action_center_get_size(fdf, limit_x, limit_y);
	width = limit_x[1] - limit_x[0];
	height = limit_y[1] - limit_y[0];
	fdf->offset_x = (fdf->height - 1) * fdf->scale_x;
	fdf->offset_y = 0;
	fdf->offset_x += ((WINDOW_WIDTH / 2 - width / 2)
		* (1.0 / fdf->global_scale));
	fdf->offset_y += ((WINDOW_HEIGHT / 2 - height / 2)
		* (1.0 / fdf->global_scale));
	fdf->offset_y += fdf->max_height * fdf->scale_z / 2;
	update_points(fdf);
}

void		action_center(t_fdf *fdf)
{
	center(fdf);
	draw(fdf);
}

void		action_move(t_fdf *fdf, int x, int y)
{
	fdf->auto_center = 0;
	fdf->offset_x += x * 50;
	fdf->offset_y -= y * 50;
	update_points(fdf);
	draw(fdf);
}

void		action_scale(t_fdf *fdf, int direction)
{
	if (fdf->global_scale <= 0.011)
		fdf->global_scale += direction * 0.001;
	else if (fdf->global_scale <= 0.11)
		fdf->global_scale += direction * 0.01;
	else
		fdf->global_scale += direction * 0.1;
	if (fdf->global_scale < 0.001)
		fdf->global_scale = 0.001;
	update_points(fdf);
	if (fdf->auto_center)
		center(fdf);
	draw(fdf);
}
