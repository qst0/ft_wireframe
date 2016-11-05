/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 21:22:20 by myoung            #+#    #+#             */
/*   Updated: 2016/11/04 21:22:26 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	fdf(t_view *view)
{
	init_color_table(view, 100);
	full_redraw(view);
	view_set_hooks(view);
	mlx_loop(view->id);
}
