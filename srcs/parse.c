/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 02:29:48 by myoung            #+#    #+#             */
/*   Updated: 2016/11/04 21:53:30 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void			parse_points(t_view *view, int fd)
{
	char	*line;
	char	**points;
	int		i[3];

	line = (char*)malloc(sizeof(char) * 4096);
	view->points = (t_vertex***)malloc(sizeof(t_vertex**) * view->height);
	i[1] = 0;
	view->z_min = 2147483647;
	view->z_max = -2147483648;
	while (ft_get_next_line(fd, &line))
	{
		points = ft_strsplit(line, ' ');
		view->points[i[1]] = (t_vertex**)malloc(
				sizeof(t_vertex*) * view->width);
		i[0] = -1;
		while (++i[0] < view->width)
		{
			i[2] = ft_atoi(points[i[0]]);
			view->points[i[1]][i[0]] = get_vertex(i[0], i[1], i[2]);
			view->z_min = view->z_min > i[2] ? i[2] : view->z_min;
			view->z_max = view->z_max < i[2] ? i[2] : view->z_max;
		}
		i[1]++;
	}
	free(line);
}

static void			pre_parse(t_view *view, int fd)
{
	char	*line;
	char	**points;
	int		width;

	line = (char*)malloc(sizeof(char) * 4096);
	view->height = 0;
	view->width = 0;
	while (ft_get_next_line(fd, &line))
	{
		points = ft_strsplit(line, ' ');
		width = 0;
		while (points[width])
			width++;
		if (view->width != 0 && view->width != width)
			exit(0);
		view->width = width;
		view->height++;
	}
	free(line);
}

static int			safe_open(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("File Error!");
		exit(0);
	}
	return (fd);
}

void				parse(t_view *view, char *filename)
{
	int fd;

	fd = safe_open(filename);
	pre_parse(view, fd);
	close(fd);
	fd = safe_open(filename);
	parse_points(view, fd);
	close(fd);
}
