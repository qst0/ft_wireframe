/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 13:32:31 by myoung            #+#    #+#             */
/*   Updated: 2016/10/19 15:32:31 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strcat(char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	while (s1[j])
		j++;
	while (s2[i])
		s1[j++] = s2[i++];
	s1[j] = '\0';
	return (s1);
}
