/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:14:57 by fhadhri           #+#    #+#             */
/*   Updated: 2022/05/16 15:58:16 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (n == 0)
		return (0);
	while (j == 0 && i < n)
	{
		j = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	return (j);
}
/*
int main(void)
{
    const char s1[] = "test";
    const char s2[] = "testsss";
    size_t n = 7;

	printf("%i\n",ft_strncmp(s1,s2,n));
	printf("%i\n",strncmp(s1,s2,n));
    return (0);
}
*/