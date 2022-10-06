/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:18:57 by fhadhri           #+#    #+#             */
/*   Updated: 2022/10/06 14:24:59 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* 0 pour un emplacement vide,
1 pour un mur,
C pour un item à collecter (C pour collectible),
E pour une sortie (E pour exit),
P pour la position de départ du personnage */

/* 1 : creer une fonction qui compte le nombre d'item, de sortie et de Player DONE
2 : verifier les valeurs de map afin qu'elle n'est pas de caractere invalide. TODO */

void	ft_count_pec(t_data *data, t_env *env)
{
	int	i;
	int	j;

	i = 0;
	env->collectible = 0;
	env->exit = 0;
	env->player = 0;
	env->bad_char = 0;
	if (!data->map)
		return ;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				env->collectible++;
			else if (data->map[i][j] == 'E')
				env->exit++;
			else if (data->map[i][j] == 'P')
				env->player++;
			else if (data->map[i][j] == '0' || data->map[i][j] == '1' || data->map[i][j] == '\n')
				env->osef++;
			else
				env->bad_char++;
			j++;
		}
		i++;
	}
	printf("[%i], [%i], [%i], [%i]", env->player, env->exit, env->collectible, env->bad_char);
}

void	ft_get_map_height(t_data *data)
{
	int	fd;

	data->y = 0;
	fd = open(data->map_path, O_RDONLY);
	data->ligne = "";
	while (data->ligne != NULL)
	{
		data->ligne = get_next_line(fd);
		data->y++;
		free(data->ligne);
	}
	data->y -= 1;
	close(fd);
}

// ajouter dans la fonction fill map remplacer les \n par des \0 TODO
void	ft_fill_map(t_data *data)
{
	int	i;

	i = 0;
	ft_get_map_height(data);
	data->map = malloc(sizeof(data->map) * data->y + 1);
	if (!data->map)
		return ;
	data->map[data->y + 1] = NULL;
	data->map_fd = open(data->map_path, O_RDONLY);
	while (i < data->y)
	{
		data->map[i] = get_next_line(data->map_fd);
		printf("%s", data->map[i]);
		// free(data->map[i]);
		i++;
	}
	// free(data->map);
	data->y -= 1;
	close(data->map_fd);
}

int	main(void)
{
	t_data	game;
	t_env	env;

	game.map_path = "map/test.ber";
	ft_fill_map(&game);
	ft_count_pec(&game, &env);
	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// mlx_loop(mlx);
	return (0);
}
