/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:58:54 by fhadhri           #+#    #+#             */
/*   Updated: 2022/05/19 14:49:07 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		max;
	int		i;
	int		j;

	j = 0;
	i = 0;
	max = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *) malloc(sizeof(char) * max + 1);
	while (s1[i])
	{
		dest[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		dest[j] = s2[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	s1[] = "lorem ipsum";
	char	s2[] = "dolor sit amet";

	printf("%s", ft_strjoin(s1, s2));
	return (0);
}*/
