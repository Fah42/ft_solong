/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:24:54 by fhadhri           #+#    #+#             */
/*   Updated: 2022/08/29 12:10:46 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_data
{
	void	*img;
	char	*addr;
	char	*map_path;
	int		bits_per_pixel;
	int		line_lenght;
	void	*mlx;
	void	*mlx_win;
	int		map_fd;
	char	*ligne;
	int		i;
	int		x;
	int		y;
	char	**map;
}			t_data;



# include "minilibx-linux/mlx.h"
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "Get-Next-Line/get_next_line.h"
# include <stdlib.h>

#endif