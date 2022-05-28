/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbillet <jbillet@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:06:42 by jbillet           #+#    #+#             */
/*   Updated: 2022/05/16 19:51:36 by jbillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_min_limit(int n, int fd)
{
	if (n == (INT_MIN))
	{
		write(fd, "-2147483648", 11);
		return (1);
	}
	else
		return (0);
}

static int	ft_check_if_negative(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
		return (n);
	}
	else
		return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	nbr_as_char;

	if (ft_is_min_limit(n, fd))
		return ;
	else
	{
		n = ft_check_if_negative(n, fd);
		if (n < 10)
		{
			nbr_as_char = n + 48;
			write(fd, &nbr_as_char, 1);
		}
		else
		{
			ft_putnbr_fd(n / 10, fd);
			nbr_as_char = (n % 10) + 48;
			write(fd, &nbr_as_char, 1);
		}
	}
}
