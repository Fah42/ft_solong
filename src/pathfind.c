/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:15:06 by fhadhri           #+#    #+#             */
/*   Updated: 2022/10/10 15:29:57 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_pathfind(int i, int j, t_data *data)
{
	i = 1;
	j = 1;

	ft_fill_map2(data);
	if (data->map_copy[i + 1][j + 1] == 'E')
		return (1);
	if (data->map_copy[i][j] == '0')
	{
		data->map_copy[i][j] = '0';
		if (ft_pathfind(i, j + 1, &data) == '0')
			return (1);
		if (ft_pathfind(i + 1, j, &data) == '0')
			return (1);
		data->map_copy[i][j] = '1';
	}
	return (0);
}
