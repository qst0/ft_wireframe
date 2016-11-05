/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 19:39:47 by myoung            #+#    #+#             */
/*   Updated: 2016/10/19 15:32:28 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		*ft_realloc(void *ptr, size_t size)
{
	void		*out;

	out = malloc(size * 2);
	ft_memcpy(out, ptr, size);
	free(ptr);
	return (out);
}
