/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:15:06 by fhadhri           #+#    #+#             */
/*   Updated: 2022/10/11 15:43:19 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_pathfind(int i, int j, t_data *data, t_env *env)
{
	printf("[%i]", env->exit_founded);
	if (env->exit_founded >= 1 && env->collectible == env->collected)
		return (1);
	if (data->map_copy[i][j] == 'E')
	{
		data->map_copy[i][j] = '1';
		env->exit_founded++;
	}
	if (data->map_copy[i][j] == 'C')
	{
			env->collected++;
			data->map_copy[i][j] = '0';
	}	
	if (data->map_copy[i][j] == '0')
	{
		data->map_copy[i][j] = '1';
		return (ft_pathfind(i, j + 1, data, env)
			|| ft_pathfind(i + 1, j, data, env)
	 		|| ft_pathfind(i, j - 1, data, env)
			|| ft_pathfind(i - 1, j, data, env));
	}
	return (0);
}
