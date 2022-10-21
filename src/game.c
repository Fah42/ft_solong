/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:36:30 by fhadhri           #+#    #+#             */
/*   Updated: 2022/10/21 17:35:28 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_mouvement(t_data *game, t_env *env, t_map *map)
{
    if (map->map[env->player_x][env->player_y] == 'E')
    {
        mlx_destroy_window(game->mlx, game->mlx_win);
        exit(0);
    }
    if (map->map[env->player_x][env->player_y] == 'C')
    {
        map->map[env->player_x][env->player_y] = '0';
        env->collectible--;
    }
    if (env->collectible == 0)
    {

    }
}

int	key_hook(int keycode, t_data *game)
{
	if (keycode == 65307)
		ft_close(game);
	else if (keycode == 65361)
		ft_move_left(game);
	else if (keycode == 65362)
		ft_move_up(game);
	else if (keycode == 65363)
		ft_move_right(game);
	else if (keycode == 65364)
		ft_move_down(game);
	return (0);
}
