/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:24:58 by lulee             #+#    #+#             */
/*   Updated: 2019/09/29 20:19:49 by lulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_word(char const *s, char c)
{
	size_t	words;

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

static char		*ft_get_word(char *word, char c)
{
	char *start;

	start = word;
	while (*word && *word != c)
		word++;
	*word = '\0';
	return (ft_strdup(start));
}

static void		ft_free_words(char **ptr_new, size_t i)
{
	while (i--)
		ft_strdel(&(ptr_new[i]));
	free(*ptr_new);
}

static char		**ft_get_words(char *s, char c, size_t word_count)
{
	char	**ptr_new;
	char	*word;
	size_t	i;

	i = 0;
	if ((ptr_new = (char **)ft_memalloc(sizeof(char *) * (word_count + 1))))
	{
		while (i < word_count)
		{
			while (*s == c)
				s++;
			if (*s)
			{
				if (!(word = ft_get_word(s, c)))
				{
					ft_free_words(ptr_new, i);
					return (NULL);
				}
				ptr_new[i++] = word;
				s += (ft_strlen(word) + 1);
			}
		}
		ptr_new[i] = NULL;
	}
	return (ptr_new);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ptr_new;
	char	*str_copy;

	if (!s || !(str_copy = ft_strdup((char *)s)))
		return (NULL);
	ptr_new = ft_get_words(str_copy, c, ft_count_word(str_copy, c));
	free(str_copy);
	return (ptr_new);
}
