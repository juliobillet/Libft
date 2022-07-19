/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbillet <jbillet@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:06:33 by jbillet           #+#    #+#             */
/*   Updated: 2022/06/09 00:30:37 by jbillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**ft_split_s(char const *s, char c, char **result, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	word_len;

	i = 0;
	j = 0;
	word_len = 0;
	while (i < len + 1)
	{
		if (s[i] == c || !s[i])
		{
			if (word_len > 0)
			{
				result[j] = (char *)ft_calloc(word_len + 1, sizeof(char));
				if (result[j])
					ft_strlcpy(result[j], &s[i - word_len], (word_len + 1));
				word_len = 0;
				j++;
			}
		}
		else
			word_len++;
		i++;
	}
	return (result);
}

static	size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;
	size_t	new_word;

	i = 0;
	words = 0;
	new_word = 0;
	while (s[i])
	{
		if (s[i] != c && !new_word)
		{
			new_word = 1;
			words++;
		}
		else if (s[i] == c)
			new_word = 0;
		i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	total_words;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	total_words = ft_count_words(s, c);
	result = (char **)malloc(sizeof (char *) * (total_words + 1));
	if (!result)
		return (NULL);
	result = ft_split_s(s, c, result, s_len);
	result[total_words] = NULL;
	return (result);
}
