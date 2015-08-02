/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 20:55:36 by amaurer           #+#    #+#             */
/*   Updated: 2015/04/28 22:15:10 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <libft.h>
#include <stdlib.h>
#include <limits.h>

static t_uint	get_line_width(const char *line)
{
	t_uint	i;

	i = 1;
	while (*line == ' ')
		line++;
	while ((line = ft_strchr(line, ' ')))
	{
		while (*line == ' ')
			line++;
		i++;
	}
	return (i);
}

static void		parse_line(t_fdf *fdf, const char *line, t_uint y)
{
	t_uint	x;
	t_pt	*pt;

	fdf->map[y] = malloc(sizeof(t_pt) * fdf->width);
	ft_bzero(fdf->map[y], sizeof(t_pt) * fdf->width);
	pt = &(fdf->map[y][0]);
	pt->z = ft_atoi(line);
	pt->x_2d = 0;
	pt->y_2d = y;
	x = 1;
	while ((line = ft_strchr(line, ' ')))
	{
		pt = &(fdf->map[y][x]);
		pt->z = ft_atoi(line);
		pt->x_2d = x;
		pt->y_2d = y;
		if (pt->z > fdf->max_height)
			fdf->max_height = pt->z;
		if (pt->z < fdf->min_height)
			fdf->min_height = pt->z;
		while (*line == ' ')
			line++;
		x++;
	}
}

void			parse(t_fdf *fdf, const char *filename)
{
	int		fd;
	char	*line;
	t_uint	tmp;

	fdf->max_height = INT_MIN;
	fdf->min_height = INT_MAX;
	fd = file_open(filename);
	while (get_next_line(fd, &line) > 0)
	{
		if ((tmp = get_line_width(line)) > fdf->width)
			fdf->width = tmp;
		fdf->height++;
		free(line);
	}
	file_close(fd);
	fdf->map = malloc(sizeof(t_pt*) * fdf->height);
	fd = file_open(filename);
	tmp = 0;
	while (get_next_line(fd, &line) > 0)
	{
		parse_line(fdf, line, tmp);
		free(line);
		tmp++;
	}
	file_close(fd);
}
