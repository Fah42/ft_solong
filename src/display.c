/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:18:15 by fhadhri           #+#    #+#             */
/*   Updated: 2022/10/21 08:42:04 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_display(t_data *game, t_data *img, t_env *env)
{
	game->img = mlx_xpm_file_to_image(game->mlx, img->player_img_path, &img->img_width, &img->img_height);
	game->player = mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, env->player_y * 100, env->player_x * 100);
	return (0);
}
