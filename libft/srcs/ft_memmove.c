/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 12:10:20 by myoung            #+#    #+#             */
/*   Updated: 2016/10/19 15:32:27 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** ft_memmove explained
**
** str:
** 0123456789
** ^   ^
** src dst
**
** str 0x287AEF10 (made up pointer)
**
** src = &str[0];
** dst = &str[4];
**
** src 0x287AEF10 (the same as str!)
** dst 0x287AEF14 (four down the line)
**
**
** ft_memmove(dst, src, 5);
**
** Our goal is to move 01234 (the first 5 bytes in src)
**  to str[4] which is our dst.
**
** Move forwards:
** 0123456789
** 0123056789
** 0123016789
** 0123012789
** 0123012389
** 0123012309
** ....01230.
**
** we destroyed our 4! This isn't what we want!
**
** Move Backwards:
** 0123456789
** 0123456749
** 0123456349
** 0123452349
** 0123412349
** 0123012349
** ....01234.
**
** This works!
*/

void		*ft_memmove(void *dst, const void *src, size_t n)
{
	signed char		op;
	size_t			cur;
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	if (dst < src)
	{
		op = 1;
		cur = 0;
	}
	else
	{
		op = -1;
		cur = n - 1;
		n = -1;
	}
	while (cur != n)
	{
		d[cur] = s[cur];
		cur += op;
	}
	return (dst);
}
