/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_gradient.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 12:46:51 by amaurer           #+#    #+#             */
/*   Updated: 2015/04/28 22:40:13 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fdf.h"

static void	draw_line_gradient1(t_graphics *gfx, t_pt *a, t_pt *b,
	t_color **colors)
{
	int		x;
	t_color	*color;
	t_color	*interval;
	int		tmp;

	interval = color_get_interval(colors[0], colors[1], b->x_2d - a->x_2d);
	color = colors[0];
	x = a->x_2d;
	while (x < b->x_2d)
	{
		if (colors[0]->hex < colors[1]->hex)
			color_sub(color, interval);
		else
			color_add(color, interval);
		tmp = a->y_2d;
		tmp += ((b->y_2d - a->y_2d) * (x - a->x_2d)) / (b->x_2d - a->x_2d);
		draw_pixel(gfx, x, tmp, color->hex);
		++x;
	}
}

static void	draw_line_gradient2(t_graphics *gfx, t_pt *a, t_pt *b,
	t_color **colors)
{
	int		y;
	t_color	*color;
	t_color	*interval;
	int		tmp;

	colors_swap(colors);
	interval = color_get_interval(colors[0], colors[1],
		ft_abs(b->y_2d - a->y_2d));
	color = colors[0];
	y = a->y_2d;
	while (y < b->y_2d)
	{
		if (colors[0]->hex > colors[1]->hex)
			color_sub(color, interval);
		else
			color_add(color, interval);
		tmp = a->x_2d;
		tmp += ((b->x_2d - a->x_2d) * (y - a->y_2d)) / (b->y_2d - a->y_2d);
		draw_pixel(gfx, tmp, y, color->hex);
		++y;
	}
}

void		draw_line_gradient(t_graphics *gfx, t_pt *pt1, t_pt *pt2,
	t_color **colors)
{
	if (ft_abs(pt2->x_2d - pt1->x_2d) > ft_abs(pt2->y_2d - pt1->y_2d))
	{
		if (pt1->x_2d >= pt2->x_2d)
			pt_swap(&pt1, &pt2);
		draw_line_gradient1(gfx, pt1, pt2, colors);
	}
	else
	{
		if (pt1->y_2d >= pt2->y_2d)
			pt_swap(&pt1, &pt2);
		draw_line_gradient2(gfx, pt1, pt2, colors);
	}
}
