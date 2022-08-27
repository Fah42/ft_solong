/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:00:06 by fhadhri           #+#    #+#             */
/*   Updated: 2022/05/20 09:07:41 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*ss;
	const char	*lfs;
	size_t		i;
	size_t		j;

	i = 0;
	lfs = little;
	ss = big;
	if (lfs[i] == '\0')
		return ((char *) ss);
	while (ss[i])
	{
		j = 0;
		while (ss[i + j] == lfs[j] && (i + j) < len)
		{
			j++;
			if (lfs[j] == '\0')
				return ((char *)ss + i);
		}	
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	const char	*big = "lorem ipsum dolor sit amet";
	const char	*little = "dolor";
	char *ptr;
	size_t	len = 17;

	ptr = ft_strnstr(big, little, len);
	if (ptr == 0)
		printf("%p\n", ptr);
	else
		printf("%s\n", ptr);
	ptr = strnstr(big, little, len);
	if (ptr == 0)
		printf("%p\n", ptr);
	else
		printf("%s\n", ptr);
	return (0);
}*/