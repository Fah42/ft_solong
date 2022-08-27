/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:10:02 by fhadhri           #+#    #+#             */
/*   Updated: 2022/05/12 14:26:44 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	d;
	const char		*ss;
	int				i;

	d = (unsigned char)c;
	ss = s;
	i = 0;
	while (ss[i] != '\0')
	{
		if (ss[i] == d)
			return ((char *)&s[i]);
	i++;
	}
	if (ss[i] == d)
		return ((char *)&s[i]);
	else
		return (NULL);
}
