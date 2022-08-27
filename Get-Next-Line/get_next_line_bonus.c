/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:48:14 by fhadhri           #+#    #+#             */
/*   Updated: 2022/07/26 13:44:14 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_prev(const char *str)
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

char	*ft_next(char *str)
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
		return (NULL);
	n = 0;
	i++;
	while (str[i] != '\0')
		string[n++] = str[i++];
	string[n] = '\0';
	free(str);
	return (string);
}

int	ft_newline(const char *str)
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

char	*ft_read(int fd, char *buffer, char *tmp, char *str)
{
	int	bytes_read;

	while (1)
	{
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
		if (ft_newline(str) == 1 || bytes_read == 0)
			break ;
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[1048576];
	char		*buffer;
	char		*ligne;
	char		*tmp;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	tmp = NULL;
	str[fd] = ft_read(fd, buffer, tmp, str[fd]);
	if (str == NULL)
		return (NULL);
	ligne = ft_prev(str[fd]);
	str[fd] = ft_next(str[fd]);
	return (ligne);
}

// int	main(void)
// {
// 	int	fd;
// 	char *ligne;

// 	fd = open("LOL.txt", O_RDONLY);
// 	ligne = get_next_line(fd);
// 	printf("1e ligne = %s\n", ligne);
// 	free(ligne);
// 	ligne = get_next_line(fd);
// 	printf("2e ligne = %s\n", ligne);
// 	free(ligne);
// 	ligne = get_next_line(fd);
// 	printf("3e ligne = %s", ligne);
// 	return (0);
// }
