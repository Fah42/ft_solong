/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:24:54 by fhadhri           #+#    #+#             */
/*   Updated: 2022/10/08 22:49:24 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h> /* write, close, read */
# include <fcntl.h> /* open */
# include <stdlib.h> /* malloc, free, exit */
# include <stdio.h> /* perror */
# include <string.h> /* strerror */
# include "../minilibx-linux/mlx.h"
# include "../Libft/libft.h"

typedef struct s_data
{
	char	*addr;
	char	*map_path;
	char	*ligne;
	char	**map;
	char	**map_test;
	int		bits_per_pixel;
	int		line_lenght;
	int		map_fd;
	int		map_fd2;
	int		i;
	int		x;
	int		y;
	void	*mlx;
	void	*mlx_win;
	void	*img;
}			t_data;

typedef struct s_env
{
	int	player;
	int	exit;
	int	collectible;
	int	bad_char;
	int wall;
}	t_env;


#endif