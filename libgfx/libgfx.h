/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 03:27:52 by myoung            #+#    #+#             */
/*   Updated: 2016/11/04 23:08:23 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGFX_H
# define LIBGFX_H

# include <math.h>
# include <mlx.h>
# include <libft.h>

# define WIN_WIDTH 1600
# define WIN_HEIGHT 1200

# define KEY_UP 126
# define KEY_DOWN 125

# define KEY_ZOOM_IN 49
# define KEY_ZOOM_OUT 257

# define KEY_SEMI 41
# define KEY_A 0
# define KEY_B 11
# define KEY_C 8
# define KEY_D 2
# define KEY_E 14
# define KEY_F 3
# define KEY_G 5
# define KEY_H 4
# define KEY_I 34
# define KEY_J 38
# define KEY_K 40
# define KEY_L 37
# define KEY_M 46
# define KEY_N 45
# define KEY_O 31
# define KEY_P 35
# define KEY_Q 12
# define KEY_R 15
# define KEY_S 1
# define KEY_T 17
# define KEY_U 32
# define KEY_V 9
# define KEY_W 13
# define KEY_X 7
# define KEY_Y 16
# define KEY_Z 6
# define KEY_PLUS 69
# define KEY_MINUS 78

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

typedef struct	s_keys
{
	int			semi:1;
	int			i:1;
	int			j:1;
	int			k:1;
	int			l:1;
	int			m:1;
	int			n:1;
	int			o:1;
	int			p:1;
	int			x:1;
	int			y:1;
	int			z:1;
	int			q:1;
	int			w:1;
	int			e:1;
	int			a:1;
	int			s:1;
	int			d:1;
	int			left:1;
	int			up:1;
	int			right:1;
	int			down:1;
	int			plus:1;
	int			minus:1;
}				t_keys;

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
