/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbillet <jbillet@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:04:39 by jbillet           #+#    #+#             */
/*   Updated: 2022/05/16 08:01:59 by jbillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (ft_strchr(set, s1[start]) != NULL && s1[start] != '\0')
		start++;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[end]) && end != 0)
		end--;
	if ((int)(end - start + 1) <= 0)
		return (ft_strdup(""));
	return (ft_substr(s1, start, (end - start + 1)));
}
