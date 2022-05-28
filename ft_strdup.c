/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbillet <jbillet@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:06:17 by jbillet           #+#    #+#             */
/*   Updated: 2022/05/16 07:56:32 by jbillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	s_len;
	char	*new_str;

	s_len = ft_strlen(s);
	new_str = malloc(sizeof(char) * s_len + 1);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s, s_len);
	new_str[s_len] = '\0';
	return (new_str);
}
