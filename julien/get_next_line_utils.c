/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:46:31 by juchene           #+#    #+#             */
/*   Updated: 2022/08/25 11:33:39 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (*s++)
		i++;
	return (i);
}

int	ft_found_nl(char *s)
{
	int	nl;

	nl = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (nl = 1);
		s++;
	}
	return (nl);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src != NULL && i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}
