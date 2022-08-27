/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:18:57 by fhadhri           #+#    #+#             */
/*   Updated: 2022/08/27 15:56:05 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}			t_data;


int	main(void)
{
	int		map_fd;
	char	*ligne;
	int		i;
	int		x;
	int		y;
	// void	*mlx;
	// void	*mlx_win;

	i = 0;
	x = 0;
	y = 0;
	map_fd = open("map/test.ber", O_RDONLY);
	ligne = get_next_line(map_fd);
	while (1)
	{
		if (ligne[i])
		{
			printf("%c", ligne[i]);
			i++;
		}
		else if (ligne == NULL)
			break ;
		else
			ligne = get_next_line(map_fd);
	}
	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// mlx_loop(mlx);
	return (0);
}
