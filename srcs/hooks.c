/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 05:26:48 by myoung            #+#    #+#             */
/*   Updated: 2017/01/05 16:19:33 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		exit_hook(t_view *view)
{
	mlx_destroy_window(view->id, view->win);
	exit(0);
}

int		expose_hook(t_view *view)
{
	redraw(view);
	return (0);
}

int		my_loop_hook(t_view *view)
{
	color_hook(view);
	translate_hook(view);
	if (view->pressed->w)
		view->theta += 0.05;
	if (view->pressed->s)
		view->theta -= 0.05;
	if (view->pressed->a)
		view->phi -= 0.05;
	if (view->pressed->d)
		view->phi += 0.05;
	if (view->pressed->q)
		view->psi += 0.05;
	if (view->pressed->e)
		view->psi -= 0.05;
	if (view->pressed->o && view->focal_dist < 9)
		view->focal_dist++;
	if (view->pressed->p && view->focal_dist > 0)
		view->focal_dist--;
	if (view->pressed->minus || view->pressed->plus)
		scale_hook_work(view);
	else
		redraw(view);
	return (0);
}

int		key_press_hook(int keycode, t_view *view)
{
	if (keycode == 53)
		exit(0);
	if (keycode == KEY_M)
		view->project = view->project ? 0 : 1;
	toggle_pressed(keycode, view, 1);
	return (0);
}

int		key_release_hook(int keycode, t_view *view)
{
	toggle_pressed(keycode, view, 0);
	return (0);
}
