/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:57:03 by fhadhri           #+#    #+#             */
/*   Updated: 2022/10/24 18:36:57 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_left(t_data *game)
{
	printf("player pos dans ft_move_left pos = %i \n", game->env->player_x);
	if (game->map->map[game->env->player_x][game->env->player_y - 1] == '1')
		return (0);
	else if (game->map->map[game->env->player_x][game->env->player_y - 1] == 'E')
		return (0);
	else if (game->map->map[game->env->player_x][game->env->player_y] == 'E'
			&& game->env->collected_ig == game->env->collectible)
		ft_close(game);
	else
	{
		game->map->map[game->env->player_x][game->env->player_y] = '0';
		game->env->player_y--;
		game->map->map[game->env->player_x][game->env->player_y] = 'P';
		ft_display_map(game, game->env, game->img, game->map);
		printf("%p\n", game->img);
	}
	return (0);
}

int	ft_move_right(t_data *game)
{
	if (game->map->map[game->env->player_x][game->env->player_y + 1] == '1')
		return (0);
	else if (game->map->map[game->env->player_x][game->env->player_y + 1] == 'E')
		return (0);
	else if (game->map->map[game->env->player_x][game->env->player_y + 1] == 'E'
			&& game->env->collected_ig == game->env->collectible)
		ft_close(game);
	else
	{
		game->map->map[game->env->player_x][game->env->player_y] = '0';
		game->env->player_y++;
		game->map->map[game->env->player_x][game->env->player_y] = 'P';
		ft_display_map(game, game->env, game->img, game->map);
	}
	return (0);
}

int	ft_move_up(t_data *game)
{
	if (game->map->map[game->env->player_x - 1][game->env->player_y] == '1')
		return (0);
	else if (game->map->map[game->env->player_x - 1][game->env->player_y] == 'E')
		return (0);
	else if (game->map->map[game->env->player_x - 1][game->env->player_y] == 'E'
			&& game->env->collected_ig == game->env->collectible)
		ft_close(game);
	else
	{
		game->map->map[game->env->player_x][game->env->player_y] = '0';
		game->env->player_x--;
		game->map->map[game->env->player_x][game->env->player_y] = 'P';
		ft_display_map(game, game->env, game->img, game->map);
	}
	return (0);
}

int	ft_move_down(t_data *game)
{
	if (game->map->map[game->env->player_x + 1][game->env->player_y] == '1')
		return (0);
	else if (game->map->map[game->env->player_x + 1][game->env->player_y] == 'E')
		return (0);
	else if (game->map->map[game->env->player_x + 1][game->env->player_y] == 'E'
			&& game->env->collected_ig == game->env->collectible)
		ft_close(game);
	else
	{
		game->map->map[game->env->player_x][game->env->player_y] = '0';
		game->env->player_x++;
		game->map->map[game->env->player_x][game->env->player_y] = 'P';
		ft_display_map(game, game->env, game->img, game->map);
	}
	return (0);
}

int	ft_close(t_data *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(1);
}
