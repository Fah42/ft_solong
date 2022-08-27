/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 07:53:50 by fhadhri           #+#    #+#             */
/*   Updated: 2022/05/21 10:57:44 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*str;
	char		*dd;

	str = (char *)src;
	dd = (char *)dest;
	if (!src && !dest)
		return (NULL);
	while (n--)
	{
		dd[n] = str[n];
	}
	return (dd);
}
