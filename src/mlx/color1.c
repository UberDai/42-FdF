/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 17:59:39 by amaurer           #+#    #+#             */
/*   Updated: 2015/04/28 22:36:36 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fdf.h"

t_color	*color_get_interval(t_color *color1, t_color *color2, int divisor)
{
	t_color	*interval;
	double	r;
	double	g;
	double	b;

	if (!divisor)
		return (color1);
	r = ft_absd((color1->r - color2->r) / (double)divisor);
	g = ft_absd((color1->g - color2->g) / (double)divisor);
	b = ft_absd((color1->b - color2->b) / (double)divisor);
	interval = color_make_rgb(r, g, b);
	interval->hex = color_get_hex(interval->r, interval->g, interval->b);
	return (interval);
}

t_color	*color_make_rgb(double r, double g, double b)
{
	t_color	*color;

	color = (t_color*)ft_memalloc(sizeof(t_color));
	color->r = (r >= 0) ? r : 0;
	color->r = (r <= 255) ? r : 255;
	color->g = (g >= 0) ? g : 0;
	color->g = (g <= 255) ? g : 255;
	color->b = (b >= 0) ? b : 0;
	color->b = (b <= 255) ? b : 255;
	color->hex = color_get_hex(r, g, b);
	return (color);
}

t_color *color_make(int val)
{
	t_color	*color;

	if (val > 0xFFFFFF)
		color = color_make(0xFFFFFF);
	if (val < 0)
		color = color_make(0);
	color = (t_color*)ft_memalloc(sizeof(t_color));
	color->hex = val;
	color->r = val >> 16 & 0xFF;
	color->g = val >> 8 & 0xFF;
	color->b = val & 0xFF;
	return (color);
}

void	color_add(t_color *color, t_color *alter)
{
	color->r = (color->r + alter->r <= 255) ? color->r + alter->r : 0;
	color->g = (color->g + alter->g <= 255) ? color->g + alter->g : 0;
	color->b = (color->b + alter->b <= 255) ? color->b + alter->b : 0;
	color->hex = color_get_hex(color->r, color->g, color->b);
}

int		color_get_hex(int r, int g, int b)
{
	return (b + g * 256 + r * 256 * 256);
}
