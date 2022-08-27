/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:32:08 by fhadhri           #+#    #+#             */
/*   Updated: 2022/05/19 15:01:07 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nombre_de_mots(char const *s, const char c)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			word++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (word);
}

char	**free_propre(int i, char **tab)
{
	i--;
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}

char	*ft_put_inside(const char *s, char c)
{
	int		i;
	char	*mot;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	mot = (char *)malloc(sizeof(char) * i + 1);
	if (!mot)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		mot[i] = s[i];
		i++;
	}
	mot[i] = '\0';
	return (mot);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		nombre_de_tab;
	char	**tab;

	i = 0;
	nombre_de_tab = 0;
	tab = malloc(sizeof(char *) * (ft_nombre_de_mots(s, c) + 1));
	if (tab == 0)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			tab[nombre_de_tab] = ft_put_inside(s + i, c);
			if (tab[nombre_de_tab] == NULL)
				return (free_propre(nombre_de_tab, tab));
			nombre_de_tab++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	tab[nombre_de_tab] = 0;
	return (tab);
}
