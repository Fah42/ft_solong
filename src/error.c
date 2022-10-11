/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:57:22 by fhadhri           #+#    #+#             */
/*   Updated: 2022/10/11 17:55:54 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_manage_error(t_env *env)
{
	if (env->player == 0)
	{
		printf("No player found\n");
		return (1);
	}
	if (env->exit == 0)
	{
		printf("No exit found\n");
		return (1);
	}
	if (env->collectible == 0)
	{
		printf("No collectible found\n");
		return (1);
	}
	if (env->player > 1)
	{
		printf("Too many players\n");
		return (1);
	}
	if (env->exit > 1)
	{
		printf("Too many exits\n");
		return (1);
	}
	return (0);
}
