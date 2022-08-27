/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 17:06:16 by fhadhri           #+#    #+#             */
/*   Updated: 2022/05/18 14:56:00 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	is_neg;
	int	res;

	i = 0;
	res = 0;
	if (!nptr)
		return (0);
	while ((nptr[i] >= 9 && nptr[i] <= 14) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '-')
		is_neg = -1;
	else
		is_neg = 1;
	if (is_neg == -1 || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return (res * is_neg);
}
