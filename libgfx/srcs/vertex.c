/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 00:27:35 by myoung            #+#    #+#             */
/*   Updated: 2016/11/03 01:26:04 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgfx.h>

t_2dp		*get_2dp(float x, float y)
{
	t_2dp	*out;

	out = (t_2dp*)malloc(sizeof(t_2dp));
	out->x = x;
	out->y = y;
	return (out);
}

t_3dp		*get_3dp(float x, float y, float z)
{
	t_3dp	*out;

	out = (t_3dp*)malloc(sizeof(t_3dp));
	out->x = x;
	out->y = y;
	out->z = z;
	return (out);
}

t_vertex	*get_vertex(float x, float y, float z)
{
	t_vertex *out;

	out = (t_vertex*)malloc(sizeof(t_vertex));
	out->local = get_3dp(x, y, z);
	out->world = get_3dp(0, 0, 0);
	out->aligned = get_3dp(0, 0, 0);
	out->projected = get_3dp(0, 0, 0);
	out->color = z;
	return (out);
}
