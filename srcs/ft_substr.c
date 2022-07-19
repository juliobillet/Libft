/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbillet <jbillet@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:04:33 by jbillet           #+#    #+#             */
/*   Updated: 2022/05/16 08:01:15 by jbillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if ((s_len - start) < len)
		sub_str = malloc(sizeof(char) * (s_len - start + 1));
	else
		sub_str = malloc(sizeof(char) * (len + 1));
	if (!sub_str)
		return (NULL);
	ft_strlcpy(sub_str, (s + start), (len + 1));
	return (sub_str);
}
