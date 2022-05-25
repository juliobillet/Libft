/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbillet <jbillet@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:07:30 by jbillet           #+#    #+#             */
/*   Updated: 2022/05/16 07:55:15 by jbillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_int_size(long int n)
{
	if (n < 0)
		return (1 + ft_int_size(-n));
	if ((n / 10) == 0)
		return (1);
	else
		return (1 + ft_int_size(n / 10));
}

static	char	*ft_reverse_str(char *str)
{
	size_t	i;
	size_t	len;
	char	temp;
	int		negative;

	i = 0;
	len = ft_strlen(str) - 1;
	if (str[0] == '-')
		negative = 1;
	else
		negative = 0;
	while (i < len - i)
	{
		temp = str[i + negative];
		str[i + negative] = str[len - i];
		str[len - i] = temp;
		i++;
	}
	return (str);
}

static	char	*ft_convert(int n, char *str, size_t len)
{
	size_t	i;

	i = len;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		i--;
	}
	while (n > 0)
	{
		str[len - i] = (n % 10) + '0';
		n = (n / 10);
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = ft_int_size(n);
	str = (char *)ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[len] = '\0';
	ft_convert(n, str, len);
	return (ft_reverse_str(str));
}
