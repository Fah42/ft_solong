/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:24:54 by fhadhri           #+#    #+#             */
/*   Updated: 2022/10/07 16:32:18 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "Libft/libft.h"
# include <stdlib.h>

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

int	ft_strlen_ret(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}
#endif