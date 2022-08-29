/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:18:57 by fhadhri           #+#    #+#             */
/*   Updated: 2022/08/29 13:48:35 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_map_height(t_data *data)
{	
	(*data).map_fd = open(data->map_path, O_RDONLY);
	data->ligne = "";
	while (data->ligne != NULL)
	{
		data->ligne = get_next_line(data->map_fd);
		printf("%s", data->ligne);
		data->y++;
		free(data->ligne);
	}
	close(data->map_fd);
}

void	ft_fill_map(t_data *data)
{
	ft_get_map_height(data);
	data->map = malloc(sizeof(data->map) * data->y + 1);
	if (!data->map)
		return ;
	data->map[data->y + 1] = NULL;
}

int	main(void)
{
	t_data	game;

	game.map_path = "map/test.ber";
	ft_fill_map(&game);
	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// mlx_loop(mlx);
	return (0);
}
