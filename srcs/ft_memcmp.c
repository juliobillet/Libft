/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbillet <jbillet@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:07:14 by jbillet           #+#    #+#             */
/*   Updated: 2022/05/16 07:55:30 by jbillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*un_char_s1;
	unsigned char	*un_char_s2;

	if (n == 0)
		return (0);
	i = 0;
	un_char_s1 = (unsigned char *)s1;
	un_char_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if (un_char_s1[i] != un_char_s2[i])
			return (un_char_s1[i] - un_char_s2[i]);
		i++;
	}
	return (0);
}
