/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 22:43:32 by fhadhri           #+#    #+#             */
/*   Updated: 2022/10/08 22:50:51 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_is_square(t_data *data)
{
	int	i;
	int	j;
	int check_first_line;
	int check_last_line;
	int check_first_column;
	int check_last_column;

	i = 0;
	j = 0;
	check_first_line = 0;
	check_last_line = 0;
	check_first_column = 0;
	check_last_column = 0;
	data->x = ft_strlen_ret(data->map[0]) - 1;
	if (!data->map)
		return 2;
	while (data->map[i])
	{
		j = 0;
		while(data->map[i][j])
		{
			if (i == 0 && (data->map[i][j] == '1' || data->map[i][j] == '\n'))
				check_first_line++;
			if (i == data->y && (data->map[i][j] == '1' || data->map[i][j] == '\n'))
				check_last_line++;
			if (j == 0 && (data->map[i][j] == '1'))
				check_first_column++;
			if (j == data->x && (data->map[i][j] == '1' || data->map[i][j] == '\n'))
				check_last_column++;
			j++;
		}
		i++;
	}
	printf("checkfirstline = [%i]\n", check_first_line);
	printf("checklastline = [%i]\n", check_last_line);
	printf("checkfirstcol = [%i]\n", check_first_column);
	printf("checklastcol = [%i]\n", check_last_column);
	if (check_first_line != check_last_line)
		return (1);
	if (check_first_column != check_last_column)
		return (1);
	return (0);
}

int ft_check_bad_char(t_data *data, t_env *env)
{
	int	i;
	int	j;

	i = 0;
	if (!data->map)
		return 1;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (i == 0 && (data->map[i][j] != '1' && data->map[i][j] != '\n'))
				return (1);
			if (i == data->y && (data->map[i][j] != '1' && data->map[i][j] != '\n'))
				return (1);
			if (data->map[i][j] == 'C')
				env->collectible++;
			else if (data->map[i][j] == 'E')
				env->exit++;
			else if (data->map[i][j] == 'P')
				env->player++;
			else if (data->map[i][j] == '0' || data->map[i][j] == '1' || data->map[i][j] == '\n')
				env->wall++;
			else
				env->bad_char++;
			j++;
		}
		i++;
	}
	printf("\n\nNombre de player : [%i]\nNombre de sortie : [%i]\nNombre de collectible : [%i] \nCaracteres incorrect : [%i] \n\n", env->player, env->exit, env->collectible, env->bad_char);
	return (0);
}

void	ft_get_map_height(t_data *data)
{
	int	fd;

	data->y = 0;
	fd = open(data->map_path, O_RDONLY);
	data->ligne = "";
	while (data->ligne != NULL)
	{
		data->ligne = get_next_line(fd);
		data->y++;
		free(data->ligne);
	}
	data->y -= 1;
	close(fd);
}

void	ft_fill_map(t_data *data)
{
	int	i;

	i = 0;
	ft_get_map_height(data);
	data->map = malloc(sizeof(data->map) * data->y + 1);
	if (!data->map)
		return ;
	data->map[data->y + 1] = NULL;
	data->map_fd = open(data->map_path, O_RDONLY);
	while (i < data->y)
	{
		data->map[i] = get_next_line(data->map_fd);
		printf("%s", data->map[i]);
		// free(data->map[i]);
		i++;
	}
	// free(data->map);
	data->y -= 1;
	close(data->map_fd);
}
