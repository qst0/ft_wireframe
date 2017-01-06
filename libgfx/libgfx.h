/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 03:27:52 by myoung            #+#    #+#             */
/*   Updated: 2017/01/05 16:17:54 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGFX_H
# define LIBGFX_H

# include <math.h>
# include <mlx.h>
# include <keys.h>
# include <libft.h>

# define WIN_WIDTH 1600
# define WIN_HEIGHT 1200

typedef int		t_color;

typedef struct	s_2dp
{
	float		x;
	float		y;
}				t_2dp;

typedef struct	s_3dp
{
	float		x;
	float		y;
	float		z;
}				t_3dp;

typedef struct	s_vertex
{
	t_3dp		*local;
	t_3dp		*world;
	t_3dp		*aligned;
	t_3dp		*projected;
	t_color		color;
}				t_vertex;

typedef struct	s_view
{
	void		*id;
	void		*win;
	void		*img;
	char		*pixels;
	t_vertex	***points;
	t_color		*colors;
	int			num_colors;
	int			width;
	int			height;
	int			z_min;
	int			z_max;
	float		theta;
	float		phi;
	float		psi;
	float		x_scale;
	float		y_scale;
	float		z_scale;
	float		scale;
	float		x_shift;
	float		y_shift;
	float		z_shift;
	float		r;
	float		g;
	float		b;
	int			focal_dist;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_keys		*pressed;
	int			project:1;
}				t_view;

void			toggle_pressed(int keycode, t_view *view, int toggle);

void			use_view_image(t_view *view);
void			create_view_image(t_view *view);

void			init_color_table(t_view *view, int colors);

void			mat_bzero(float mat[4][4]);
void			get_id_matrix(float mat[4][4]);

void			vec_mat_mult(t_3dp *src, float mat[4][4], t_3dp *dst);

void			mat_mult(float m1[4][4], float m2[4][4], float p[4][4]);
void			mat_translate(float p[4][4], float x, float y, float z);
void			mat_scale(float p[4][4], float x, float y, float z);
void			mat_rotate(float p[4][4], float theta, float phi, float psi);

void			draw_point(t_view *view, int x, int y, float z);
void			drawline(t_view *view, t_3dp p0, t_3dp p1);

t_2dp			*get_2dp(float x, float y);
t_3dp			*get_3dp(float x, float y, float z);
t_vertex		*get_vertex(float x, float y, float z);
#endif
