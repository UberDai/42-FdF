/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 18:54:47 by amaurer           #+#    #+#             */
/*   Updated: 2015/04/28 22:35:47 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_sub(t_color *color, t_color *alter)
{
	color->r = (color->r - alter->r >= 0) ? color->r - alter->r : 0;
	color->g = (color->g - alter->g >= 0) ? color->g - alter->g : 0;
	color->b = (color->b - alter->b >= 0) ? color->b - alter->b : 0;
	color->hex = color_get_hex(color->r, color->g, color->b);
}

void	colors_swap(t_color **colors)
{
	t_color	*tmp;

	tmp = colors[0];
	colors[0] = colors[1];
	colors[1] = tmp;
}

void	color_divide(t_color *color, int divisor)
{
	color->r = (color->r / divisor);
	if (color->r > 0xffffff)
		color->r = 0xffffff;
	else if (color->r < 0)
		color->r = 0;
	color->g = (color->g / divisor);
	if (color->g > 0xffffff)
		color->g = 0xffffff;
	else if (color->g < 0)
		color->g = 0;
	color->b = (color->b / divisor);
	if (color->b > 0xffffff)
		color->b = 0xffffff;
	else if (color->b < 0)
		color->b = 0;
	color->hex = color_get_hex(color->r, color->g, color->b);
}

void	color_mult(t_color *color, int mult)
{
	color->r = (color->r * mult);
	if (color->r > 0xffffff)
		color->r = 0xffffff;
	else if (color->r < 0)
		color->r = 0;
	color->g = (color->g * mult);
	if (color->g > 0xffffff)
		color->g = 0xffffff;
	else if (color->g < 0)
		color->g = 0;
	color->b = (color->b * mult);
	if (color->b > 0xffffff)
		color->b = 0xffffff;
	else if (color->b < 0)
		color->b = 0;
	color->hex = color_get_hex(color->r, color->g, color->b);
}
