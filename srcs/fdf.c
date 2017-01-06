/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 21:22:20 by myoung            #+#    #+#             */
/*   Updated: 2017/01/05 16:57:17 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void		show_controls(void)
{
	ft_putstr("w/s : rotate by x axis\n"
			"a/d : rotate by y axis\n"
			"q/e : rotate by z axis\n"
			"\n"
			"c   : trippy colors\n"
			"ijkl: translate (move around)\n"
			"+/- : zoom / scale\n"
			"with z x or y, scale that axis\n"
			"Esc to quit.\n");
}

void			fdf(t_view *view)
{
	show_controls();
	init_color_table(view, 100);
	full_redraw(view);
	view_set_hooks(view);
	mlx_loop(view->id);
}
