/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lire_ecrire.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:43:48 by smarty            #+#    #+#             */
/*   Updated: 2019/09/18 23:19:39 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_map		readheader(int i, t_map map)
{
	int		j;
	char	letter[1];
	char	*header;

	j = 0;
	if (!(header = malloc(sizeof(header) * i + 1)))
	{
		map.error = -1;
		return (map);
	}
	open(map.adress, O_RDONLY);
	while (letter[0] != '\n')
	{
		read(map.error, letter, 1);
		header[j] = letter[0];
		j++;
	}
	map.plein = header[i - 2];
	map.obstacle = header[i - 3];
	map.vide = header[i - 4];
	header[i - 4] = '\0';
	map.hauteur = ft_atoi(header);
	free(header);
	map.error = close(map.error);
	return (map);
}

void		errorreturn(void)
{
	write(1, "map error", 9);
	ft_putchar('\n');
	exit(0);
}

t_map		mapinit(t_map map)
{
	char	letter[1];
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((map.error = open(map.adress, O_RDONLY)) == -1)
		return (map);
	while (letter[0] != '\n')
	{
		read(map.error, letter, 1);
		i++;
	}
	read(map.error, letter, 1);
	while (letter[0] != '\n')
	{
		read(map.error, letter, 1);
		j++;
	}
	if (i < 4)
		errorreturn();
	map.largeur = j;
	close(map.error);
	return (readheader(i, map));
}
