/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbillet <jbillet@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:04:51 by jbillet           #+#    #+#             */
/*   Updated: 2022/05/16 07:59:23 by jbillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long int	keep_last;
	size_t		i;

	i = 0;
	keep_last = -1;
	if (c > 255)
		return ((char *)(s));
	while (s[i] != '\0')
	{
		if (s[i] == c)
			keep_last = i;
		i++;
	}
	if (keep_last >= 0)
		return ((char *)(s + keep_last));
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}
