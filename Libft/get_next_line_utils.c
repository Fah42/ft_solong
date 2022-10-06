/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:46:31 by fhadhri           #+#    #+#             */
/*   Updated: 2022/10/06 10:53:05 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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


size_t	ft_strlen_prtctd(const char *s)
{
	const char	*str;
	int			i;

	i = 0;
	str = s;
	if (!s)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
