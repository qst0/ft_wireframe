/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 19:50:21 by myoung            #+#    #+#             */
/*   Updated: 2016/10/19 15:32:26 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_itoa(int n)
{
	char	*digits;
	char	*result;
	int		nlen;
	int		i;

	digits = ft_strdup("0123456789");
	if (n == -2147483648 || n == 0)
		return (n ? ft_strdup("-2147483648") : ft_strdup("0"));
	nlen = ft_nlen(n);
	result = n < 0 ? ft_strnew(nlen + 1) : ft_strnew(nlen);
	if (!result)
		return (NULL);
	result[nlen] = n < 0 ? '-' : 0;
	n = n < 0 ? -n : n;
	i = result[0] == '-' ? 1 : 0;
	while (n)
	{
		result[i] = digits[n % 10];
		n /= 10;
		i++;
	}
	result = ft_strrev(result);
	return (result);
}
