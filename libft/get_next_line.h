/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 17:39:29 by myoung            #+#    #+#             */
/*   Updated: 2016/10/29 21:24:58 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 8
# define MAX_FD_COUNT 1024
# define FD_PACK files.array[files.index]
# define PACK pack->array[pack->index]
# include <sys/types.h>
# include <sys/uio.h>
# include <libft.h>

typedef	struct	s_fdbuf
{
	int			fd;
	size_t		bytes_read;
	size_t		buf_size;
	int			ret_flag;
	char		*buf;
}				t_fdbuf;

typedef	struct	s_fd_pack
{
	t_fdbuf		array[MAX_FD_COUNT];
	int			index;
	int			count;
}				t_fd_pack;

int				ft_get_next_line(const int fd, char **line);

#endif
