/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:18:57 by fhadhri           #+#    #+#             */
/*   Updated: 2022/10/15 14:04:45 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Todo :
	1 - 
*/
int	main(void)
{
	t_data			game;
	t_env			env;
	t_check_line	check_line;
	t_map			map;

	ft_memset(&env, 0, sizeof(t_env));
	ft_memset(&map, 0, sizeof(t_map));
	ft_memset(&check_line, 0, sizeof(t_check_line));
	game.map_path = "../map/test.ber";
	ft_fill_map(&game, &map.map);
	ft_fill_map(&game, &map.map_copy);
	if (ft_check_bad_char(&game, map.map, &env) >= 1)
	{
		printf("Bad characters used in the map.");
		return (0);
	}
	if (ft_is_square(&game, map.map, &check_line))
	{
		printf("Map is not a square");
		return (0);
	}
	game.error = ft_manage_error(&env);
	if (game.error)
		return (0);
	game.is_path_valid = ft_pathfind(env.player_x, env.player_y, &map, &env);
	if (game.is_path_valid)
	{
		printf("Path is valid");
		ft_free_map(&map, &game);
	}
	else
	{
		printf("Path is not valid");
		ft_free_map(&map, &game);
	}
	return (0);
}
