/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:20:54 by myoung            #+#    #+#             */
/*   Updated: 2017/01/05 16:41:08 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

#include <stdio.h>

void		color_hook(t_view *view)
{
	if (view->pressed->c)
	{
		printf("Hey!");
		view->r = rand() % 3;
		view->g = rand() % 3;
		view->b = rand() % 3;
		init_color_table(view, 100);
	}
}
