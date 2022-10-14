/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 22:43:32 by fhadhri           #+#    #+#             */
/*   Updated: 2022/10/14 12:42:48 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_is_square(t_data *data, char **map, t_check_line *check)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->x = ft_strlen_ret(map[0]) - 1;
	if (!map)
		return (2);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 && (map[i][j] == '1'
				|| map[i][j] == '\n'))
				check->check_first_line++;
			if (i == data->y && (map[i][j] == '1'
				|| map[i][j] == '\n'))
				check->check_last_line++;
			if (j == 0 && (map[i][j] == '1'))
				check->check_first_column++;
			if (j == data->x && (map[i][j] == '1'
				|| map[i][j] == '\n'))
				check->check_last_column++;
			j++;
		}
		i++;
	}
	if (check->check_first_line != check->check_last_line)
		return (1);
	if (check->check_first_column != check->check_last_column)
		return (1);
	return (0);
}

int ft_check_bad_char(t_data *data, char **map, t_env *env)
{
	int	i;
	int	j;

	i = 0;
	if (!map)
		return (1);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 && (map[i][j] != '1'
				&& map[i][j] != '\n'))
				return (1);
			if (i == data->y && (map[i][j] != '1'
				&& map[i][j] != '\n'))
				return (1);
			if (map[i][j] == 'C')
				env->collectible++;
			else if (map[i][j] == 'E')
				env->exit++;
			else if (map[i][j] == 'P')
			{
				env->player_x = i;
				env->player_y = j;
				env->player++;
			}
			else if (map[i][j] == '0'
					|| map[i][j] == '1'
					|| map[i][j] == '\n')
				env->wall++;
			else
				env->bad_char++;
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_get_map_height(t_data *data)
{
	int		fd;
	char	*line;

	data->y = 0;
	fd = open(data->map_path, O_RDONLY);
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		data->y++;
		free(line);
	}
	data->y -= 1;
	close(fd);
}

void	ft_fill_map(t_data *data, char ***map)
{
	int	i;

	i = 0;
	ft_get_map_height(data);
	(*map) = ft_calloc(sizeof((*map)), (data->y + 2));
	if (!(*map))
		return ;
	(*map)[data->y + 1] = NULL;
	data->map_fd = open(data->map_path, O_RDONLY);
	while (i < data->y)
	{
		(*map)[i] = get_next_line(data->map_fd);
		// free(data->map[i]);
		i++;
	}
	// free(data->map);
	data->y -= 1;
	close(data->map_fd);
}
