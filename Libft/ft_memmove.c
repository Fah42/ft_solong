/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:37:40 by fhadhri           #+#    #+#             */
/*   Updated: 2022/05/21 10:59:30 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char const	*lasts;
	const char	*s;
	char		*lastd;
	char		*d;

	s = src;
	d = dest;
	if (!src && !dest)
		return (NULL);
	lastd = d + (n - 1);
	lasts = s + (n - 1);
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		while (n--)
			*lastd-- = *lasts--;
	}
	return (dest);
}
