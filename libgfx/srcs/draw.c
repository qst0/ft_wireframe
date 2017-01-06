/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 15:47:11 by myoung            #+#    #+#             */
/*   Updated: 2017/01/05 16:07:17 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>

void		draw_point_to_img(t_view *view, int x, int y, float z)
{
	unsigned int	color;
	float			which;
	int				i;

	if (x > 0 && y > 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
	{
		i = (x * (view->bits_per_pixel / 8)) + (y * view->size_line);
		if (view->pixels[i] || view->pixels[i + 1] || view->pixels[i + 2])
			return ;
		if (!view->z_max && !view->z_min)
			view->z_max = 1;
		which = ((z - view->z_min) / (view->z_max - view->z_min))
			* (view->num_colors);
		color = view->colors[abs((int)which - 1)];
		view->pixels[i] = color;
		view->pixels[++i] = color >> 8;
		view->pixels[++i] = color >> 16;
	}
}

void		draw_point(t_view *view, int x, int y, float z)
{
	unsigned int	color;
	float			which;

	if (x > 0 && y > 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
	{
		if (!view->z_max && !view->z_min)
			view->z_max = 1;
		which = ((z - view->z_min) / (view->z_max - view->z_min))
			* (view->num_colors);
		color = view->colors[abs((int)which - 1)];
		mlx_pixel_put(view->id, view->win, x, y, color);
	}
}

static int	swap_vars(t_3dp *p0, t_3dp *p1)
{
	float temp;

	if (fabs(p1->x - p0->x) > fabs(p1->y - p0->y))
		return (0);
	temp = p0->y;
	p0->y = p0->x;
	p0->x = temp;
	temp = p1->y;
	p1->y = p1->x;
	p1->x = temp;
	return (1);
}

void		drawline(t_view *view, t_3dp p0, t_3dp p1)
{
	float	delta[3];
	float	error;
	float	slope;
	int		dir;

	dir = swap_vars(&p0, &p1);
	delta[0] = p1.x - p0.x;
	delta[1] = p1.y - p0.y;
	delta[2] = p1.z - p0.z;
	slope = fabs(delta[1] / delta[0]);
	error = -1.0;
	while ((int)p0.x != (int)p1.x)
	{
		draw_point(view, dir ? p0.y : p0.x, dir ? p0.x : p0.y, p0.z);
		error += slope;
		if (error >= 0.0)
		{
			p0.y += (p0.y > p1.y) ? -1.0 : 1.0;
			error -= 1.0;
		}
		p0.z += delta[2] / fabs(delta[0]);
		p0.x += (p0.x > p1.x) ? -1.0 : 1.0;
	}
}
