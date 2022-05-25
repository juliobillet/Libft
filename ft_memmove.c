/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbillet <jbillet@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:07:05 by jbillet           #+#    #+#             */
/*   Updated: 2022/05/11 22:46:29 by jbillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_char;
	unsigned char	*src_char;
	unsigned char	*temp;

	if (n < 1)
		return (dest);
	i = 0;
	dest_char = (unsigned char *)dest;
	src_char = (unsigned char *)src;
	temp = (unsigned char *)ft_calloc(n, sizeof(char));
	while (i < n)
	{
		temp[i] = src_char[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		dest_char[i] = temp[i];
		i++;
	}
	free(temp);
	return (dest);
}
