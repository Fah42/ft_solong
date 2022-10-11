/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:15:06 by fhadhri           #+#    #+#             */
/*   Updated: 2022/10/11 13:01:55 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_pathfind(int i, int j, t_data *data, t_env *env)
{
	int	collect;

	collect = 0;
	if (data->map_copy[i][j] == 'E' && env->collectible == collect)
	{
		data->map_copy[i][j] = '1';
		return (1);
	}	
	if (data->map_copy[i][j] == '0')
	{
		if (data->map_copy[i][j] == 'C')
		collect++;
		data->map_copy[i][j] = '1';
		return (ft_pathfind(i, j + 1, data, env)
			+ ft_pathfind(i + 1, j, data, env)
			+ ft_pathfind(i, j - 1, data, env)
			+ ft_pathfind(i - 1, j, data, env));
	}
	return (0);
}
