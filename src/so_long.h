/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:24:54 by fhadhri           #+#    #+#             */
/*   Updated: 2022/10/11 12:47:42 by fhadhri          ###   ########.fr       */
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
	char	*ligne_copy;
	char	**map;
	char	**map_copy;
	int		bits_per_pixel;
	int		line_lenght;
	int		map_fd;
	int		map_fd2;
	int		i;
	int		x;
	int		y;
	int		yy;
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

int		ft_pathfind(int i, int j, t_data *data, t_env *env);
int		ft_is_square(t_data *data);
int		ft_check_bad_char(t_data *data, t_env *env);
void	ft_get_map_height(t_data *data);
void	ft_fill_map(t_data *data);
void	ft_get_map_height2(t_data *data);
void	ft_fill_map2(t_data *data);
#endif