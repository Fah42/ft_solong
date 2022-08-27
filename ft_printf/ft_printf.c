/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:07:47 by fhadhri           #+#    #+#             */
/*   Updated: 2022/06/16 14:59:49 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, char c)
{
	int	print_ret;

	print_ret = 0;
	if (c == 'c')
		print_ret += ft_printchar(va_arg(args, int));
	if (c == 's')
		print_ret += ft_printstr(va_arg(args, char *));
	if (c == 'p')
		print_ret += ft_printaddr(va_arg(args, unsigned long long));
	if (c == 'd' || c == 'i')
		print_ret += ft_printint(va_arg(args, int));
	if (c == 'u')
		print_ret += ft_printu(va_arg(args, unsigned int));
	if (c == 'x' || c == 'X')
		print_ret += ft_printhex(va_arg(args, int), c);
	if (c == '%')
		print_ret += ft_printpercent();
	return (print_ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		print_ret;

	i = 0;
	print_ret = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			print_ret += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			print_ret += ft_printchar(str[i]);
	i++;
	}
	va_end(args);
	return (print_ret);
}

int	main(void)
{
	ft_printf("%p", -1);
	return (0);
}
