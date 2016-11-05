/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 00:39:05 by myoung            #+#    #+#             */
/*   Updated: 2016/11/04 22:55:21 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	view_set_hooks(t_view *view)
{
	mlx_expose_hook(view->win, expose_hook, view);
	mlx_do_key_autorepeatoff(view->id);
	mlx_hook(view->win, 2, 0, key_press_hook, view);
	mlx_hook(view->win, 3, 0, key_release_hook, view);
	mlx_hook(view->win, 17, 0, exit_hook, view);
	mlx_loop_hook(view->id, my_loop_hook, view);
}

int		main(int argc, char **argv)
{
	t_view	*view;

	if (argc != 2)
	{
		ft_putendl("Usage : ./fdf map.fdf");
		return (0);
	}
	view = new_view();
	parse(view, argv[1]);
	fdf(view);
}
