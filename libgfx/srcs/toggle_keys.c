/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toggle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 22:03:48 by myoung            #+#    #+#             */
/*   Updated: 2017/01/05 16:29:50 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>

static void		toggle_wasd(int keycode, t_view *view, int toggle)
{
	if (keycode == KEY_W)
		view->pressed->w = toggle;
	if (keycode == KEY_S)
		view->pressed->s = toggle;
	if (keycode == KEY_A)
		view->pressed->a = toggle;
	if (keycode == KEY_D)
		view->pressed->d = toggle;
}

static void		toggle_ijklc(int keycode, t_view *view, int toggle)
{
	if (keycode == KEY_I)
		view->pressed->i = toggle;
	if (keycode == KEY_J)
		view->pressed->j = toggle;
	if (keycode == KEY_K)
		view->pressed->k = toggle;
	if (keycode == KEY_L)
		view->pressed->l = toggle;
	if (keycode == KEY_C)
		view->pressed->c = toggle;
}

void			toggle_pressed(int keycode, t_view *view, int toggle)
{
	toggle_wasd(keycode, view, toggle);
	toggle_ijklc(keycode, view, toggle);
	if (keycode == KEY_X)
		view->pressed->x = toggle;
	if (keycode == KEY_Y)
		view->pressed->y = toggle;
	if (keycode == KEY_Z)
		view->pressed->z = toggle;
	if (keycode == KEY_Q)
		view->pressed->q = toggle;
	if (keycode == KEY_E)
		view->pressed->e = toggle;
	if (keycode == KEY_O)
		view->pressed->o = toggle;
	if (keycode == KEY_P)
		view->pressed->p = toggle;
	if (keycode == KEY_PLUS)
		view->pressed->plus = toggle;
	if (keycode == KEY_MINUS)
		view->pressed->minus = toggle;
}
