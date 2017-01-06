/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 20:13:58 by myoung            #+#    #+#             */
/*   Updated: 2017/01/05 16:25:04 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <libft.h>
# include <libgfx.h>
# include <fcntl.h>

void	fdf(t_view *view);
void	parse(t_view *view, char *filename);
void	redraw(t_view *view);
void	full_redraw(t_view *view);
int		mouse_hook(int button, int x, int y, t_view *view);
int		exit_hook(t_view *view);
void	view_set_hooks(t_view *view);

void	draw_projected(t_view *view);

t_view	*new_view();
void	color_hook(t_view *view);
void	zook_hook(t_view *view);
void	translate_hook(t_view *view);
void	scale_hook_work(t_view *view);
void	toggle_pressed(int keycode, t_view *view, int toggle);
int		key_press_hook(int keycode, t_view *view);
int		key_release_hook(int keycode, t_view *view);
int		expose_hook(t_view *view);
int		my_loop_hook(t_view *view);
void	redraw(t_view *view);
void	local_to_world(t_view *view);
void	world_to_aligned(t_view *view);
void	aligned_to_projected(t_view *view);
void	draw_wireframe(t_view *view);
void	draw_projected(t_view *view);

#endif
