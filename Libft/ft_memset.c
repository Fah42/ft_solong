/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:38:25 by fhadhri           #+#    #+#             */
/*   Updated: 2022/05/13 10:34:44 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;
	int		i;
	int		nn;

	i = 0;
	nn = n;
	str = s;
	while (i < nn)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
