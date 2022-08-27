/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 22:26:30 by fhadhri           #+#    #+#             */
/*   Updated: 2022/05/12 14:26:20 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ss;
	size_t				i;

	i = 0;
	ss = s;
	while (i < n)
	{
		if (ss[i] == (unsigned char)c)
		{
			return ((void *)&ss[i]);
		}
		i++;
	}
	return (0);
}
