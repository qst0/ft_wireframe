/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 19:28:07 by myoung            #+#    #+#             */
/*   Updated: 2016/10/19 15:32:35 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_word_countc(const char *str, char c)
{
	int word_count;
	int i;
	int has_word;

	if (!str || !c)
		return (0);
	i = 0;
	word_count = 0;
	while (str[i] != '\0')
	{
		has_word = 0;
		while (c == str[i] && str[i])
			i++;
		while (c != str[i] && str[i])
		{
			has_word = 1;
			i++;
		}
		while (c == str[i] && str[i])
			i++;
		if (has_word == 1)
			word_count++;
	}
	return (word_count);
}

static int		ft_word_sizec(const char *str, char c)
{
	int i;

	if (!str || !c)
		return (0);
	i = 0;
	while (c == str[i] && str[i] != '\0')
		str++;
	while (c != str[i] && str[i] != '\0')
		i++;
	return (i);
}

char			**ft_strsplit(const char *str, char c)
{
	int		word_count;
	int		words_entered;
	int		i;
	char	**words;
	char	*word;

	i = 0;
	words_entered = 0;
	word_count = ft_word_countc(str, c);
	words = (char**)malloc(sizeof(char*) * (word_count + 1));
	while (words_entered < word_count)
	{
		word = (char*)malloc(sizeof(char) * (ft_word_sizec(str, c) + 1));
		if (!word || !words)
			return (NULL);
		while (c == str[0] && str[0])
			str++;
		while (c != str[0] && str[0])
			word[i++] = *str++;
		word[i] = '\0';
		words[words_entered++] = word;
		i = 0;
	}
	words[word_count] = 0;
	return (words);
}
