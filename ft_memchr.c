/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbillet <jbillet@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:07:21 by jbillet           #+#    #+#             */
/*   Updated: 2022/05/16 07:55:21 by jbillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*unsigned_char_s;
	size_t			i;

	if (n < 1)
		return (NULL);
	i = 0;
	unsigned_char_s = (unsigned char *)s;
	while (i < n)
	{
		if (unsigned_char_s[i] == (unsigned char)(c))
			return ((void *)(unsigned_char_s + i));
		i++;
	}
	return (NULL);
}
