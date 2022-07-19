/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbillet <jbillet@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:05:30 by jbillet           #+#    #+#             */
/*   Updated: 2022/05/16 07:59:17 by jbillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*big_ptr;

	i = 0;
	j = 0;
	big_ptr = (char *)big;
	if (little[0] == '\0')
		return (big_ptr);
	while (big[i] != '\0' && i < len)
	{
		while (big[i + j] == little[j] && (i + j) < len)
		{
			if (little[j + 1] == '\0')
				return (big_ptr + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
