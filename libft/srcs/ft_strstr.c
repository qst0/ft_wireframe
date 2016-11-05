/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 13:36:39 by myoung            #+#    #+#             */
/*   Updated: 2016/10/19 15:32:35 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strstr(const char *big, const char *little)
{
	int				i;
	int				find_index;
	int				remember;

	find_index = 0;
	i = 0;
	if (little[0] == '\0')
		return ((char*)&big[0]);
	while (big[i] != '\0')
	{
		if (big[i] == little[find_index])
		{
			remember = i;
			while (big[i] == little[find_index])
			{
				if (little[find_index++ + 1] == '\0')
					return ((char*)&big[remember]);
				i++;
			}
			find_index = 0;
			i = remember;
		}
		i++;
	}
	return (0);
}
