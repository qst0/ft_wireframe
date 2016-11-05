/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 22:03:11 by myoung            #+#    #+#             */
/*   Updated: 2016/10/29 21:25:19 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

static char		*prep_next_line(t_fd_pack *pack, void *newline)
{
	int					offset;
	char				*out;

	offset = newline - (void*)PACK.buf;
	out = ft_strsub(PACK.buf, 0, offset);
	ft_memmove(PACK.buf, PACK.buf + offset + 1, PACK.buf_size - offset);
	PACK.bytes_read = PACK.bytes_read - offset - 1;
	ft_bzero(PACK.buf + PACK.bytes_read, PACK.buf_size - PACK.bytes_read);
	PACK.ret_flag = 1;
	return (out);
}

static char		*last_line(t_fd_pack *pack)
{
	char				*out;

	if (PACK.buf && ft_strlen(PACK.buf))
	{
		out = ft_strsub(PACK.buf, 0, PACK.bytes_read);
		PACK.buf = NULL;
		PACK.ret_flag = 1;
		return (out);
	}
	PACK.fd = -42;
	return (ft_strdup(""));
}

static char		*find_next_line(t_fd_pack *pack)
{
	int		read_ret;
	void	*newline;

	newline = NULL;
	if (PACK.bytes_read && PACK.buf)
		newline = ft_memchr(PACK.buf, '\n', PACK.bytes_read);
	while (!newline)
	{
		if (PACK.bytes_read + BUFF_SIZE > PACK.buf_size)
		{
			PACK.buf = (char*)ft_realloc((void*)PACK.buf, PACK.buf_size);
			PACK.buf_size *= 2;
		}
		read_ret = read(PACK.fd, PACK.buf + PACK.bytes_read, BUFF_SIZE);
		if (read_ret == 0 || read_ret == -1)
		{
			PACK.ret_flag = read_ret;
			return (read_ret == 0 ? last_line(pack) : NULL);
		}
		PACK.bytes_read += read_ret;
		newline = ft_memchr(PACK.buf, '\n', PACK.bytes_read);
	}
	return (prep_next_line(pack, newline));
}

static void		new_fd(t_fd_pack *pack, int fd)
{
	pack->array[pack->index].fd = fd;
	pack->array[pack->index].buf_size = BUFF_SIZE;
	pack->array[pack->index].buf = (char*)malloc(BUFF_SIZE);
}

int				ft_get_next_line(const int fd, char **line)
{
	static t_fd_pack	files;

	if (fd < 0 || !line)
		return (-1);
	files.index = 0;
	if (files.count)
	{
		while (files.index < files.count)
		{
			if (FD_PACK.fd == fd)
				break ;
			if (++files.index == files.count)
			{
				files.count++;
				new_fd(&files, fd);
			}
		}
	}
	else
	{
		files.count = 1;
		new_fd(&files, fd);
	}
	*line = find_next_line(&files);
	return (FD_PACK.ret_flag);
}
