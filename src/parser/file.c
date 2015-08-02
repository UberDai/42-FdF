/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/24 15:00:20 by amaurer           #+#    #+#             */
/*   Updated: 2015/04/27 19:20:44 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <libft.h>
#include <fcntl.h>
#include <unistd.h>

int		file_open(const char *filename)
{
	int		fd;

	if (ft_strlen(filename) == 0)
		die("Incorrect input file name.");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		die("Could not open the input file.");
	return (fd);
}

void	file_close(int fd)
{
	if (close(fd))
		die("Could not close the input file.");
}
