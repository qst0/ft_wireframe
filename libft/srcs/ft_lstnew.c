/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 19:57:11 by myoung            #+#    #+#             */
/*   Updated: 2016/10/19 15:32:26 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *link;

	if (!(link = malloc(sizeof(t_list))))
		return (NULL);
	content_size = content == NULL ? 0 : content_size;
	link->content_size = content_size;
	if (!(link->content = malloc(content_size)))
		return (NULL);
	link->content = content ?
		ft_memcpy(link->content, (void*)content, content_size) : NULL;
	link->next = NULL;
	return (link);
}
