/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 21:09:38 by myoung            #+#    #+#             */
/*   Updated: 2016/10/19 15:32:35 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtrimc(const char *s, char c)
{
	int		i;
	int		j;
	char	*new;

	if (!s)
		return (NULL);
	i = 0;
	while (*s == c)
		s++;
	i = ft_strlen(s) - 1;
	if (i == -1)
		return (NULL);
	while (!s[i] || s[i] == c)
		i--;
	new = ft_strnew(++i);
	if (!new)
		return (NULL);
	j = i;
	i = 0;
	while (i < j)
	{
		new[i] = s[i];
		i++;
	}
	return (new);
}
