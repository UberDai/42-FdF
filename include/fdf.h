/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 18:19:03 by amaurer           #+#    #+#             */
/*   Updated: 2015/04/28 22:29:28 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WINDOW_WIDTH			1500
# define WINDOW_HEIGHT			800

# define DEFAULT_SCALE_X		20
# define DEFAULT_SCALE_Y		10
# define DEFAULT_SCALE_Z		1
# define DEFAULT_GLOBAL_SCALE	1.0

/*
** KEY_ESCAPE			ESCAPE
** KEY_MOVE_UP			UP
** KEY_MOVE_DOWN		DOWN
** KEY_MOVE_RIGHT		RIGHT
** KEY_MOVE_LEFT		LEFT
** KEY_ZOOM_IN			PAVNUM +
** KEY_ZOOM_OUT			PAVNUM -
** KEY_CENTER			SPACE
** KEY_TOGGLE_CENTER	F
** KEY_TOGGLE_COLORS	C
** KEY_SCALE_UP_X		Q
** KEY_SCALE_DOWN_X		A
** KEY_SCALE_UP_Y		W
** KEY_SCALE_DOWN_Y		S
** KEY_SCALE_UP_Z		E
** KEY_SCALE_DOWN_Z		D
** KEY_RESET			R
*/

# define KEY_ESCAPE				53
# define KEY_MOVE_UP			126
# define KEY_MOVE_DOWN			125
# define KEY_MOVE_RIGHT			124
# define KEY_MOVE_LEFT			123
# define KEY_ZOOM_IN			69
# define KEY_ZOOM_OUT			78
# define KEY_CENTER				49
# define KEY_TOGGLE_CENTER		3
# define KEY_TOGGLE_COLORS		8
# define KEY_SCALE_UP_X			12
# define KEY_SCALE_DOWN_X		0
# define KEY_SCALE_UP_Y			13
# define KEY_SCALE_DOWN_Y		1
# define KEY_SCALE_UP_Z			14
# define KEY_SCALE_DOWN_Z		2
# define KEY_RESET				15

typedef struct			s_color
{
	double				r;
	double				g;
	double				b;
	int					hex;
}						t_color;

typedef unsigned int	t_uint;

typedef struct			s_pt
{
	int					z;
	int					x_2d;
	int					y_2d;
}						t_pt;

typedef struct			s_graphics
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data;
	int					bpp;
	int					line_size;
	int					endian;
}						t_graphics;

typedef struct			s_fdf
{
	t_graphics			graphics;
	t_graphics			*gfx;
	t_uint				width;
	t_uint				height;
	int					scale_x;
	int					scale_y;
	int					scale_z;
	double				global_scale;
	int					offset_x;
	int					offset_y;
	t_pt				**map;
	int					auto_center;
	int					use_colors;
	int					max_height;
	int					min_height;
}						t_fdf;

void					parse(t_fdf *fdf, const char *filename);
int						file_open(const char *filename);
void					file_close(int fd);

void					draw(t_fdf *fdf);
void					update_points(t_fdf *fdf);

void					action_move(t_fdf *fdf, int x, int y);
void					action_scale(t_fdf *fdf, int direction);
void					action_scale_x(t_fdf *fdf, int direction);
void					action_scale_y(t_fdf *fdf, int direction);
void					action_scale_z(t_fdf *fdf, int direction);
void					action_center(t_fdf *fdf);
void					action_toggle_center(t_fdf *fdf);
void					action_toggle_colors(t_fdf *fdf);
void					action_reset(t_fdf *fdf);
void					center(t_fdf *fdf);

void					draw_pixel(t_graphics *gfx, int x, int y, int color);
void					draw_line(t_graphics *gfx, t_pt *pt1, t_pt *pt2,
	int color);
void					draw_line_gradient(t_graphics *gfx, t_pt *pt1,
	t_pt *pt2, t_color **colors);
void					draw_rect(t_graphics *gfx, t_pt *pt,
	unsigned int size[], int color);
void					draw_filled_rect(t_graphics *gfx, t_pt *pt,
	unsigned int size[], int color);
void					mlx_update(t_graphics *gfx);
void					mlx_initialize(t_fdf *fdf);
void					mlx_hooks_init(t_fdf *fdf);
void					pt_swap(t_pt **a, t_pt **b);
t_pt					*create_pt(int x, int y, int z);

t_color					*color_get_interval(t_color *color1, t_color *color2,
	int divisor);
t_color					*color_make(int hex);
t_color					*color_make_rgb(double r, double g, double b);
void					color_add(t_color *color, t_color *alter);
int						color_get_hex(int r, int g, int b);
void					color_sub(t_color *color, t_color *alter);
void					colors_swap(t_color **colors);
void					color_divide(t_color *color, int divisor);
void					color_mult(t_color *color, int mult);

int						die(const char *message);

#endif
