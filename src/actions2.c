/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 17:56:44 by amaurer           #+#    #+#             */
/*   Updated: 2015/04/28 22:15:19 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	action_toggle_center(t_fdf *fdf)
{
	fdf->auto_center = !fdf->auto_center;
	if (fdf->auto_center)
	{
		center(fdf);
		draw(fdf);
	}
}

void	action_scale_x(t_fdf *fdf, int direction)
{
	fdf->scale_x += direction;
	update_points(fdf);
	if (fdf->auto_center)
		center(fdf);
	draw(fdf);
}

void	action_scale_y(t_fdf *fdf, int direction)
{
	fdf->scale_y += direction;
	update_points(fdf);
	if (fdf->auto_center)
		center(fdf);
	draw(fdf);
}

void	action_scale_z(t_fdf *fdf, int direction)
{
	fdf->scale_z += direction;
	update_points(fdf);
	if (fdf->auto_center)
		center(fdf);
	draw(fdf);
}

void	action_reset(t_fdf *fdf)
{
	fdf->scale_x = DEFAULT_SCALE_X;
	fdf->scale_y = DEFAULT_SCALE_Y;
	fdf->scale_z = DEFAULT_SCALE_Z;
	fdf->global_scale = DEFAULT_GLOBAL_SCALE;
	fdf->auto_center = 1;
	update_points(fdf);
	center(fdf);
	draw(fdf);
}
