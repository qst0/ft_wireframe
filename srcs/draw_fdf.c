/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 21:18:26 by myoung            #+#    #+#             */
/*   Updated: 2016/11/04 23:29:30 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	full_redraw(t_view *view)
{
	local_to_world(view);
	redraw(view);
}

void	redraw(t_view *view)
{
	world_to_aligned(view);
	aligned_to_projected(view);
	mlx_clear_window(view->img, view->win);
	view->project ? draw_projected(view) : draw_wireframe(view);
}

void	draw_projected(t_view *view)
{
	int		y;
	int		x;

	y = -1;
	while (++y < view->height)
	{
		x = -1;
		while (++x < view->width)
		{
			if (x < view->width - 1)
				drawline(view, *(view->points[y][x]->projected),
						*(view->points[y][x + 1]->projected));
			if (y < view->height - 1)
				drawline(view, *(view->points[y][x]->projected),
						*(view->points[y + 1][x]->projected));
		}
	}
}

void	draw_wireframe(t_view *view)
{
	int		y;
	int		x;

	y = -1;
	while (++y < view->height)
	{
		x = -1;
		while (++x < view->width)
		{
			if (x < view->width - 1)
				drawline(view, *(view->points[y][x]->aligned),
						*(view->points[y][x + 1]->aligned));
			if (y < view->height - 1)
				drawline(view, *(view->points[y][x]->aligned),
						*(view->points[y + 1][x]->aligned));
		}
	}
}
