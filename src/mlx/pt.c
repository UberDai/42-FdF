/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 22:20:33 by amaurer           #+#    #+#             */
/*   Updated: 2015/04/27 19:42:11 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fdf.h"

t_pt	*create_pt(int x, int y, int z)
{
	t_pt	*pt;

	pt = (t_pt*)ft_memalloc(sizeof(t_pt));
	pt->z = z;
	pt->x_2d = x;
	pt->y_2d = y;
	return (pt);
}

void	pt_swap(t_pt **a, t_pt **b)
{
	t_pt	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
