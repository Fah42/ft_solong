/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:18:57 by fhadhri           #+#    #+#             */
/*   Updated: 2022/10/11 12:47:26 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* 0 pour un emplacement vide,
1 pour un mur,
C pour un item à collecter (C pour collectible),
E pour une sortie (E pour exit),
P pour la position de départ du personnage */

/* 1 : creer une fonction qui compte le nombre d'item, de sortie et de Player DONE
2 : verifier les valeurs de map afin qu'elle n'est pas de caractere invalide. DONE */

int	main(void)
{
	t_data	game;
	t_env	env;

	env.collectible = 0;
	env.exit = 0;
	env.player = 0;
	env.bad_char = 0;
	game.map_path = "../map/test.ber";
	ft_fill_map(&game);
	ft_fill_map2(&game);
	printf("valeur de retour de bad_char : [%i]\n", ft_check_bad_char(&game, &env));
	printf("valeur de retour de is_square : [%i]\n", ft_is_square(&game));
	printf("FIN DE LA PARTIE 1\n");
	printf("DEBUT DE PATHFINDING\n");
	printf("MA MAP EST VALIDE ? %i\n", ft_pathfind(1, 1, &game, &env));
	return (0);
}
