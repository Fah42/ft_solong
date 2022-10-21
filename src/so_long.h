/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:24:54 by fhadhri           #+#    #+#             */
/*   Updated: 2022/10/21 17:27:56 by fhadhri          ###   ########.fr       */
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

typedef struct s_map
{
	char	**map;
	char	**map_copy;
}	t_map;

typedef struct s_env
{
	int	player;
	int	exit;
	int	collectible;
	int	bad_char;
	int	wall;
	int	collected;
	int	exit_founded;
	int	player_x;
	int	player_y;
}	t_env;

typedef struct s_check_line
{
	int	check_first_line;
	int	check_last_line;
	int	check_first_column;
	int	check_last_column;
}	t_check_line;

typedef struct s_img
{
	char	*player;
	char	*wall;
	char	*collectible;
	char	*floor;
	char	*exit_closed;
	char	*exit_opened;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_data
{
	t_map			*map;
	t_env			*env;
	t_img			*img;
	char			*addr;
	char			*map_path;
	int				line_lenght;
	int				map_fd;
	int				x;
	int				y;
	void			*img_lol;
	void			*mlx;
	void			*mlx_win;
	int				error;
	int				is_path_valid;
	int				player;
	int				wall;
	int				collectible;
	int				exit;
	int				floor;
}	t_data;

int		ft_pathfind(int i, int j, t_map *map, t_env *env);
int		ft_is_square(t_data *data, char **map, t_check_line *check_line);
int		ft_check_bad_char(t_data *data, char **map, t_env *env);
void	ft_get_map_height(t_data *data);
void	ft_fill_map(t_data *data, char ***map);
void	ft_get_map_height2(t_data *data);
void	ft_free_map(t_map *map, t_data *data);
int		ft_manage_error(t_env *env);
int		ft_display_map(t_data *game, t_env *env, t_img *img, t_map *map);
int		ft_move_left(t_data *game);
int		ft_move_right(t_data *game);
int		ft_move_down(t_data *game);
int		ft_move_up(t_data *game);
int		ft_close(t_data *game);
int		key_hook(int keycode, t_data *game);
#endif