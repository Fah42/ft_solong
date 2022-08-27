/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:40:38 by fhadhri           #+#    #+#             */
/*   Updated: 2022/05/14 11:28:37 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// fonction qui verifie le set;
int	ft_checkset(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		k;
	char	*dest;

	i = 0;
	k = ft_strlen(s1) - 1;
	while (ft_checkset(s1[i], set))
	{
		i++;
	}
	while (ft_checkset(s1[k], set))
	{
		k--;
	}
	dest = ft_substr(s1, i, k - i + 1);
	return (dest);
}
/*
int	main(void)
{
	char	s1[] = "SalutSa";
	char	set[] = "Sa";
	printf("%s", ft_strtrim(s1, set));
	return (0);
}*/
