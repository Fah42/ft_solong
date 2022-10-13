/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:18:57 by fhadhri           #+#    #+#             */
/*   Updated: 2022/10/11 19:09:38 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Todo :
 dans ft_pathfind :
	1 - Determiner la position du joueur
	2 - la transformer en int pour l'envoyer a la fonction pathfind
dans ft_check_bad_char et ft_check_map :
	1 - renvoyer le code erreur pour chaque erreur [Done]
	2 - gerer les erreurs dans le main [Done]

*/
int	main(void)
{
	t_data	game;
	t_env	env;

	ft_memset(&env, 0, sizeof(t_env));
	game.map_path = "../map/test.ber";
	ft_fill_map(&game);
	ft_fill_map2(&game);
	if (ft_check_bad_char(&game, &env) >= 1)
	{
		printf("Bad characters used in the map.");
		return (0);
	}
	if (ft_is_square(&game))
	{
		printf("Map is not a square");
		return (0);
	}
	game.error = ft_manage_error(&env);
	if (game.error)
		return (0);
	game.is_path_valid = ft_pathfind(2, 2, &game, &env);
	if (game.is_path_valid)
		printf("Path is valid");
	else
		printf("Path is not valid");
	return (0);
}
