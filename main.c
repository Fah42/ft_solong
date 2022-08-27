/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:18:57 by fhadhri           #+#    #+#             */
/*   Updated: 2022/08/27 11:29:18 by fhadhri          ###   ########.fr       */
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
	// void	*mlx;
	// void	*mlx_win;
	int		map;
	char	*ligne;

	map = open("path_name.c", O_RDONLY);
	ligne = get_next_line(map);
	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// mlx_loop(mlx);
	return (0);
}
