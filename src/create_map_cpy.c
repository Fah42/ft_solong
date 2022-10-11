/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_cpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:07:15 by fhadhri           #+#    #+#             */
/*   Updated: 2022/10/11 17:52:10 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_map_height2(t_data *data)
{
	int	fd;

	data->yy = 0;
	fd = open(data->map_path, O_RDONLY);
	data->ligne_copy = "";
	while (data->ligne_copy != NULL)
	{
		data->ligne_copy = get_next_line(fd);
		data->yy++;
		free(data->ligne_copy);
	}
	data->yy -= 1;
	close(fd);
}

void	ft_fill_map2(t_data *data)
{
	int	i;

	i = 0;
	ft_get_map_height2(data);
	data->map_copy = ft_calloc(sizeof(data->map_copy) , (data->yy + 2));
	if (!data->map_copy)
		return ;
	data->map_copy[data->yy + 1] = NULL;
	data->map_fd2 = open(data->map_path, O_RDONLY);
	while (i < data->yy)
	{
		data->map_copy[i] = get_next_line(data->map_fd2);
		// free(data->map[i]);
		i++;
	}
	// free(data->map);
	data->yy -= 1;
	close(data->map_fd2);
}
