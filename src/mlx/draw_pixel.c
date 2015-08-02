/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 21:59:47 by amaurer           #+#    #+#             */
/*   Updated: 2015/04/23 22:03:42 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

void	draw_pixel(struct s_graphics *gfx, int x, int y, int color)
{
	int	i;
	int	index;

	if (x >= WINDOW_WIDTH || y >= WINDOW_HEIGHT || x < 0 || y < 0)
		return ;
	i = 0;
	while (i < gfx->bpp / 8)
	{
		index = (y * gfx->line_size) + (x * (gfx->bpp / 8)) + i;
		gfx->data[index] = color >> (i * 8) & 0xFF;
		i++;
	}
}
