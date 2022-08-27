/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:30:16 by fhadhri           #+#    #+#             */
/*   Updated: 2022/05/13 11:19:45 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	lenght;

	lenght = ft_strlen(s) + 1;
	d = (char *) malloc(lenght * sizeof(char));
	if (!d)
		return (NULL);
	return (ft_strcpy(d, s));
}
/*
int main (void)
{
	char str[] = "salut";
	printf("%s", ft_strdup(str));
	return (0);
}*/