/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:15:06 by fhadhri           #+#    #+#             */
/*   Updated: 2022/10/14 12:51:52 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_pathfind(int i, int j, t_map *map, t_env *env)
{
	if (env->exit_founded >= 1 && env->collectible == env->collected)
		return (1);
	if (map->map_copy[i][j] == 'P')
	{
		map->map_copy[i][j] = '0';
	}
	if (map->map_copy[i][j] == 'E')
	{
		map->map_copy[i][j] = '0';
		env->exit_founded++;
	}
	if (map->map_copy[i][j] == 'C')
	{
			env->collected++;
			map->map_copy[i][j] = '0';
	}	
	if (map->map_copy[i][j] == '0')
	{
		map->map_copy[i][j] = '1';
		return (ft_pathfind(i, j + 1, map, env)
			|| ft_pathfind(i + 1, j, map, env)
			|| ft_pathfind(i, j - 1, map, env)
			|| ft_pathfind(i - 1, j, map, env));
	}
	return (0);
}
