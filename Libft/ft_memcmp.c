/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 12:16:23 by fhadhri           #+#    #+#             */
/*   Updated: 2022/05/12 14:26:24 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*fs;
	const unsigned char	*ss;
	int					i;
	int					nn;

	i = 0;
	nn = n;
	fs = s1;
	ss = s2;
	while (i < nn)
	{
		if (fs[i] != ss[i])
		{
			return (fs[i] - ss[i]);
		}
		i++;
	}
	return (0);
}
