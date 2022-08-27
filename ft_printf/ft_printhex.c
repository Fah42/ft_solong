/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:07:17 by fhadhri           #+#    #+#             */
/*   Updated: 2022/06/16 12:14:20 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_lenght(unsigned int n)
{
	int	lenght;

	lenght = 0;
	while (n != 0)
	{
		lenght++;
		n /= 16;
	}
	return (lenght);
}

void	ft_put_hex(unsigned int n, char c)
{
	if (n >= 16)
	{
		ft_put_hex(n / 16, c);
		ft_put_hex(n % 16, c);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
		{
			if (c == 'x')
				ft_putchar_fd((n - 10 + 'a'), 1);
			if (c == 'X')
				ft_putchar_fd((n - 10 + 'A'), 1);
		}
	}
}

int	ft_printhex(unsigned int n, char c)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		ft_put_hex(n, c);
		return (ft_hex_lenght(n));
	}
}
