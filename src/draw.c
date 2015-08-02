/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 21:56:26 by amaurer           #+#    #+#             */
/*   Updated: 2015/04/28 22:33:40 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <libft.h>

#define PT_COLOR1	0x555555
#define PT_COLOR2	0xffffff

static void	clear(t_fdf *fdf)
{
	t_pt	pt;
	t_uint	size[2];

	pt.x_2d = 0;
	pt.y_2d = 0;
	size[0] = WINDOW_WIDTH;
	size[1] = WINDOW_HEIGHT;
	draw_filled_rect(fdf->gfx, &pt, size, 0);
}

static void	set_colors(t_fdf *fdf, t_pt *pt1, t_pt *pt2, t_color **colors)
{
	double	tmp;

	tmp = (PT_COLOR2 - PT_COLOR1) / (fdf->max_height - fdf->min_height);
	tmp *= (pt1->z - fdf->min_height);
	tmp += PT_COLOR1;
	colors[0] = color_make(tmp);
	tmp = (PT_COLOR2 - PT_COLOR1) / (fdf->max_height - fdf->min_height);
	tmp *= (pt2->z - fdf->min_height);
	tmp += PT_COLOR1;
	colors[1] = color_make(tmp);
}

static void	fdf_draw_line(t_fdf *fdf, t_uint x, t_uint y)
{
	t_pt	*pt1;
	t_pt	*pt2;
	t_color	*colors[2];

	pt1 = &(fdf->map[y][x]);
	if (x < fdf->width - 1)
	{
		pt2 = &(fdf->map[y][x + 1]), set_colors(fdf, pt1, pt2, colors);
		if (pt1->z > pt2->z)
			colors_swap(colors);
		if (fdf->use_colors)
			draw_line_gradient(fdf->gfx, pt1, pt2, colors);
		else
			draw_line(fdf->gfx, pt1, pt2, 0xffffff);
	}
	if (y < fdf->height - 1)
	{
		pt2 = &(fdf->map[y + 1][x]), set_colors(fdf, pt1, pt2, colors);
		if (pt1->z > pt2->z)
			colors_swap(colors);
		if (fdf->use_colors)
			draw_line_gradient(fdf->gfx, pt1, pt2, colors);
		else
			draw_line(fdf->gfx, pt1, pt2, 0xffffff);
	}
}

void		draw(t_fdf *fdf)
{
	t_uint	x;
	t_uint	y;

	clear(fdf);
	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			fdf_draw_line(fdf, x, y);
			x++;
		}
		y++;
	}
	mlx_update(fdf->gfx);
}

void		update_points(t_fdf *fdf)
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
			pt->x_2d = (x - y) * fdf->scale_x + fdf->offset_x;
			pt->y_2d = (x + y) * fdf->scale_y - pt->z * fdf->scale_z
			+ fdf->offset_y;
			pt->x_2d *= fdf->global_scale;
			pt->y_2d *= fdf->global_scale;
			x++;
		}
		y++;
	}
}
