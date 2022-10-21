/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:18:15 by fhadhri           #+#    #+#             */
/*   Updated: 2022/10/21 17:29:58 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_display_map(t_data *game, t_env *env, t_img *img, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= game->y)
	{
		while (j <= game->x)
		{
			if (map->map[i][j] == '1')
			{
				game->img_lol = mlx_xpm_file_to_image(game->mlx, img->wall, &img->img_width, &img->img_height);
				printf("adresse de game_img %p\n", game->img_lol);
				game->wall = mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_lol, j * 64, i * 64);
			}
			else if (map->map[i][j] == '0')
			{
				game->img_lol = mlx_xpm_file_to_image(game->mlx, img->floor, &img->img_width, &img->img_height);
				game->floor = mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_lol, j * 64, i * 64);
			}
			else if (map->map[i][j] == 'C')
			{
				game->img_lol = mlx_xpm_file_to_image(game->mlx, img->collectible, &img->img_width, &img->img_height);
				game->collectible = mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_lol, j * 64, i * 64);
			}
			else if (map->map[i][j] == 'E')
			{
				game->img_lol = mlx_xpm_file_to_image(game->mlx, img->exit_closed, &img->img_width, &img->img_height);
				game->exit = mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_lol, j * 64, i * 64);
			}
			else if (map->map[i][j] == 'P')
			{
				game->img_lol = mlx_xpm_file_to_image(game->mlx, img->player, &img->img_width, &img->img_height);
				game->player = mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_lol, env->player_y * 64, env->player_x * 64);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}