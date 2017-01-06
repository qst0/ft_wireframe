/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 05:27:57 by myoung            #+#    #+#             */
/*   Updated: 2017/01/05 16:18:32 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	local_to_world(t_view *view)
{
	float	global[4][4];
	int		y;
	int		x;

	get_id_matrix(global);
	mat_translate(global, -(view->width / 2), -(view->height / 2), 0);
	mat_scale(global, view->x_scale, view->y_scale, view->z_scale);
	y = -1;
	while (++y < view->height)
	{
		x = -1;
		while (++x < view->width)
		{
			vec_mat_mult(view->points[y][x]->local, global,
					view->points[y][x]->world);
		}
	}
}

void	world_to_aligned(t_view *view)
{
	float	global[4][4];
	int		y;
	int		x;

	get_id_matrix(global);
	mat_rotate(global, view->theta, view->phi, view->psi);
	mat_scale(global, (WIN_WIDTH * view->scale) / view->width,
			(WIN_HEIGHT * view->scale) / view->height, view->scale);
	mat_translate(global, (view->project) ? view->x_shift :
			view->x_shift + WIN_WIDTH / 2,
			(view->project) ? view->y_shift : view->y_shift + WIN_HEIGHT / 2,
			view->z_shift);
	y = -1;
	while (++y < view->height)
	{
		x = -1;
		while (++x < view->width)
		{
			vec_mat_mult(view->points[y][x]->world, global,
					view->points[y][x]->aligned);
			view->points[y][x]->aligned->z = view->project ?
				view->points[y][x]->aligned->z : view->points[y][x]->local->z;
		}
	}
}

void	aligned_to_projected(t_view *view)
{
	float	global[4][4];
	int		y;
	int		x;

	get_id_matrix(global);
	y = -1;
	while (++y < view->height)
	{
		x = -1;
		while (++x < view->width)
		{
			if (!view->points[y][x]->aligned->z)
				view->points[y][x]->aligned->z = 0.001;
			view->points[y][x]->projected->x = view->focal_dist
				* view->points[y][x]->aligned->x
				/ (view->z_max - view->points[y][x]->aligned->z)
				+ WIN_WIDTH / 2;
			view->points[y][x]->projected->y = view->focal_dist
				* view->points[y][x]->aligned->y
				/ (view->z_max - view->points[y][x]->aligned->z)
				+ WIN_HEIGHT / 2;
			view->points[y][x]->projected->z = view->points[y][x]->local->z;
		}
	}
}

t_view	*new_view(void)
{
	t_view *view;

	view = (t_view*)malloc(sizeof(t_view));
	view->project = 0;
	view->theta = 0.0;
	view->phi = 0.0;
	view->psi = 0.0;
	view->scale = 0.5;
	view->x_scale = 1;
	view->y_scale = 1;
	view->z_scale = 1;
	view->x_shift = 0.0;
	view->y_shift = 0.0;
	view->z_shift = 0.0;
	view->focal_dist = 7;
	view->r = 1;
	view->g = 1;
	view->b = 1;
	view->id = mlx_init();
	view->win = mlx_new_window(view->id, WIN_WIDTH, WIN_HEIGHT, "FDF 42");
	view->pressed = (t_keys*)ft_memalloc(sizeof(t_keys));
	return (view);
}
