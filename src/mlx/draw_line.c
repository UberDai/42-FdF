/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 22:17:35 by amaurer           #+#    #+#             */
/*   Updated: 2015/04/27 19:42:20 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fdf.h"

static void	draw_line1(t_graphics *gfx, t_pt *a, t_pt *b, int color)
{
	int	x;
	int	x1;
	int	x2;
	int	y1;
	int	y2;

	x1 = a->x_2d;
	x2 = b->x_2d;
	y1 = a->y_2d;
	y2 = b->y_2d;
	x = x1;
	while (x < x2)
	{
		draw_pixel(gfx, x, y1 + ((y2 - y1) * (x - x1)) / (x2 - x1), color);
		++x;
	}
}

static void	draw_line2(t_graphics *gfx, t_pt *a, t_pt *b, int color)
{
	int	y;
	int	x1;
	int	x2;
	int	y1;
	int	y2;

	x1 = a->x_2d;
	x2 = b->x_2d;
	y1 = a->y_2d;
	y2 = b->y_2d;
	y = y1;
	while (y < y2)
	{
		draw_pixel(gfx, x1 + ((x2 - x1) * (y - y1)) / (y2 - y1), y, color);
		++y;
	}
}

void		draw_line(t_graphics *gfx, t_pt *pt1, t_pt *pt2, int color)
{
	if (ft_abs(pt2->x_2d - pt1->x_2d) > ft_abs(pt2->y_2d - pt1->y_2d))
	{
		if (pt1->x_2d >= pt2->x_2d)
			pt_swap(&pt1, &pt2);
		draw_line1(gfx, pt1, pt2, color);
	}
	else
	{
		if (pt1->y_2d >= pt2->y_2d)
			pt_swap(&pt1, &pt2);
		draw_line2(gfx, pt1, pt2, color);
	}
}
