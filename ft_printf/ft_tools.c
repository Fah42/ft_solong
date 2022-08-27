/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:09:55 by fhadhri           #+#    #+#             */
/*   Updated: 2022/06/16 12:22:31 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_intlen(long nb)
{
	int		i;

	i = 0;
	if (nb == 0)
	{
		i++;
		return (i);
	}
	if (nb < 0)
	{
		nb = nb * -1;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		i;
	long	nn;

	nn = n;
	i = ft_intlen(nn);
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!(dest))
		return (NULL);
	dest[i--] = '\0';
	if (nn == 0)
		dest[0] = 48;
	if (nn < 0)
	{
		dest[0] = '-';
		nn = nn * -1;
	}
	while (nn > 0)
	{
		dest[i] = 48 + (nn % 10);
		nn = nn / 10;
		i--;
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	const char	*str;
	int			i;

	i = 0;
	str = s;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_utoa(unsigned long n)
{
	char	*dest;
	int		i;
	long	nn;

	nn = n;
	i = ft_intlen(nn);
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!(dest))
		return (NULL);
	dest[i--] = '\0';
	if (nn == 0)
		dest[0] = 48;
	while (nn > 0)
	{
		dest[i] = 48 + (nn % 10);
		nn = nn / 10;
		i--;
	}
	return (dest);
}
