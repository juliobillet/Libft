/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbillet <jbillet@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:07:05 by jbillet           #+#    #+#             */
/*   Updated: 2022/05/26 05:56:50 by jbillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_char;
	unsigned char	*src_char;

	if (n < 1)
		return (dest);
	dest_char = (unsigned char *)dest;
	src_char = (unsigned char *)src;
	if (dest > src)
		while (n--)
			dest_char[n] = src_char[n];
	else
		ft_memcpy(dest_char, src_char, n);
	return (dest);
}
