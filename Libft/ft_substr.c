/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:45:45 by fhadhri           #+#    #+#             */
/*   Updated: 2022/05/19 15:10:19 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*dest;
	size_t				i;
	unsigned int		max;

	max = ft_strlen(s);
	i = 0;
	if (!s)
		return (NULL);
	if (start >= max)
		return (ft_strdup(""));
	if (len >= max)
		dest = (char *) malloc(sizeof(char) * (ft_strlen(s + start) + 1));
	else
		dest = (char *) malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (i < len && start < max)
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}
// 💩💩💩💩💩💩💩💩

// int	main(void)
// {
// 	const char s[] = "tripouille";
// 	size_t len = 1;
// 	unsigned int start = 1;
// 	char * sub;

// 	sub = ft_substr(s, start, len);
// 	printf("[%s]\n", sub);
// 	free(sub);

// 	return (0);
// }