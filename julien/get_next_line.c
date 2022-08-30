/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:26:36 by juchene           #+#    #+#             */
/*   Updated: 2022/08/24 11:44:03 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_buff_adjust(char *s, size_t n)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen(s + n);
	if (i < l)
		ft_memcpy(s, s + n, l);
	while ((i + l) < BUFFER_SIZE && s[i + l])
	{
		s[i + l] = 0;
		i++;
	}
	return (s);
}

static	char	*ft_line_builder(char *line, char *buff)
{
	size_t	len;
	size_t	len_line;
	char	*build;

	len_line = ft_strlen(line);
	len = 0;
	while (buff[len] != '\n' && buff[len])
		len++;
	if (buff[len] == '\n')
		len++;
	build = (char *)malloc(len_line + len + 1);
	if (!build)
		return (NULL);
	build[len_line + len] = 0;
	ft_memcpy(build, line, len_line);
	ft_memcpy(build + len_line, buff, len);
	ft_buff_adjust(buff, len);
	if (line)
	{
		free(line);
		line = NULL;
	}
	return (build);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			oct_readed;

	oct_readed = 1;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	while (!ft_found_nl(line) && oct_readed != 0)
	{
		if (!buff[0])
		{
			oct_readed = read(fd, buff, BUFFER_SIZE);
			buff[oct_readed] = 0;
		}
		line = ft_line_builder(line, buff);
		if (!line)
			break ;
	}
	if (!line || !line[0])
	{
		free(line);
		return (NULL);
	}
	return (line);
}
