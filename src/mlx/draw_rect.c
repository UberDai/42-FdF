/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/24 18:19:25 by amaurer           #+#    #+#             */
/*   Updated: 2015/04/27 19:48:41 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_rect(t_graphics *gfx, t_pt *pt, unsigned int size[], int color)
{
	unsigned int		i;

	i = 0;
	while (i < size[0])
	{
		draw_pixel(gfx, pt->x_2d + i, pt->y_2d, color);
		draw_pixel(gfx, pt->x_2d + i, pt->y_2d + size[1], color);
		i++;
	}
	i = 0;
	while (i < size[1])
	{
		draw_pixel(gfx, pt->x_2d, pt->y_2d + i, color);
		draw_pixel(gfx, pt->x_2d + size[0], pt->y_2d + i, color);
		i++;
	}
}

void	draw_filled_rect(t_graphics *gfx, t_pt *pt, unsigned int size[],
	int color)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	while (i < size[0])
	{
		j = 0;
		while (j < size[1])
		{
			draw_pixel(gfx, pt->x_2d + i, pt->y_2d + j, color);
			j++;
		}
		i++;
	}
}
