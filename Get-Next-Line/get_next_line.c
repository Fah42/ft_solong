/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:48:14 by fhadhri           #+#    #+#             */
/*   Updated: 2022/08/27 11:28:04 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_prev(const char *str)
{
	int		i;
	char	*string;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	string = malloc((i + 2) * sizeof(char));
	if (string == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		string[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		string[i] = '\n';
		i++;
	}
	string[i] = '\0';
	return (string);
}

static char	*ft_next(char *str)
{
	int		n;
	int		i;
	char	*string;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	n = ft_strlen(str);
	string = malloc((n - i) * sizeof(char));
	if (string == NULL)
		return (ft_free(str));
	n = 0;
	i++;
	while (str[i] != '\0')
		string[n++] = str[i++];
	string[n] = '\0';
	free(str);
	return (string);
}

static int	ft_newline(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_read(int fd, char *buffer, char *tmp, char *str)
{
	int	bytes_read;

	bytes_read = 1;
	while (1)
	{
		if (str != NULL && (ft_newline(str) == 1 || bytes_read == 0))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		tmp = str;
		if (tmp == NULL)
		{
			tmp = malloc(sizeof(char));
			tmp[0] = '\0';
		}
		str = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*buffer;
	char		*ligne;
	char		*tmp;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (ft_free(str));
	tmp = NULL;
	str = ft_read(fd, buffer, tmp, str);
	if (str == NULL)
		return (ft_free(str));
	ligne = ft_prev(str);
	if (ligne == NULL)
		return (ft_free(str));
	str = ft_next(str);
	return (ligne);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*ligne;

// 	fd = open("LOL.txt", O_RDONLY);
// 	(void)fd;
// 	ligne = get_next_line(fd);
// 	while (ligne != NULL)
// 	{
// 		printf("%s", ligne);
// 		free(ligne);
// 		ligne = get_next_line(fd);
// 	}
// 	return (0);
// }
