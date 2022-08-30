/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:51:58 by fhadhri           #+#    #+#             */
/*   Updated: 2022/08/30 17:14:27 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (i);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_free(char *s1, char *s2, int mode)
{
	char	*new_str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	new_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new_str == NULL)
		return (NULL);
	while (s1[++i])
		new_str[i] = s1[i];
	while (s2[++j])
		new_str[i++] = s2[j];
	new_str[i] = '\0';
	if (mode == 1 || mode == 3)
		free(s1);
	if (mode == 2 || mode == 3)
		free(s2);
	return (new_str);
}

char	*ft_free(char *str)
{
	free(str);
	return (NULL);
}
