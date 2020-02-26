/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegon-i <taegon-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:51:08 by taegon-i          #+#    #+#             */
/*   Updated: 2019/07/30 18:07:19 by taegon-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t		ft_count_words(char const *s, char c)
{
	size_t			words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			words++;
			while (*s && *s != c)
				s++;
		}
	}
	return (words);
}

static char			*ft_get_word(char *word, char c)
{
	char			*start;

	start = word;
	while (*word && *word != c)
		word++;
	*word = '\0';
	return (ft_strdup(start));
}

static void			ft_free_words(char **words, size_t i)
{
	while (i--)
		ft_strdel(&(words[i]));
	free(*words);
}

static char			**ft_get_words(char *s, char c,
		size_t words_count, size_t i)
{
	char			**words;
	char			*word;
	size_t			k;

	k = 0;
	if ((words = (char **)ft_memalloc(sizeof(char *) * (words_count + 1))))
	{
		while (i < 1)
		{
			while (*s == c)
				s++;
			if (*s)
			{
				if (!(word = ft_get_word(s, c)))
				{
					ft_free_words(words, i);
					return (NULL);
				}
				words[i++] = word;
				s += (ft_strlen(word) + 1);
			}
		}
		words[i] = NULL;
	}
	return (words);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**words;
	char			*line;

	if (!s || !(line = ft_strdup((char *)s)))
		return (NULL);
	words = ft_get_words(line, c, ft_count_words(line, c), 0);
	free(line);
	return (words);
}
