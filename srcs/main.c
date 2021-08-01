/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleger <fleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:37:09 by fleger            #+#    #+#             */
/*   Updated: 2019/09/18 23:24:34 by fleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int			mi(int haut_gauche, int haut, int gauche)
{
	int min;

	min = haut_gauche;
	if (haut < haut_gauche)
		min = haut;
	if (gauche < min)
		min = gauche;
	return (min);
}

t_sol		result_upd(t_sol result, t_sol pos, int **ta)
{
	result.size = ta[pos.y][pos.x];
	result.x = pos.x + 1;
	result.y = pos.y + 1;
	return (result);
}

int			**forestofifs(t_sol pos, t_map info, int **ta)
{
	if (pos.letter2[0] == info.obstacle && (pos.y == 0 || pos.x == 0))
		ta[pos.y][pos.x] = 0;
	else if (pos.letter2[0] == info.vide && (pos.y == 0 || pos.x == 0))
		ta[pos.y][pos.x] = 1;
	else if (pos.letter2[0] == info.vide)
		ta[pos.y][pos.x] = mi(ta[pos.y - 1][pos.x],
		ta[pos.y - 1][pos.x - 1], ta[pos.y][pos.x - 1]) + 1;
	else if (pos.letter2[0] == info.obstacle)
		ta[pos.y][pos.x] = 0;
	else if ((pos.letter2[0] != info.obstacle) &&
			(pos.letter2[0] != info.plein) &&
			(pos.letter2[0] != info.vide) && (pos.letter2[0] != '\n'))
		errorreturn();
	return (ta);
}

t_sol		convert(int **ta, t_map info)
{
	t_sol	pos;
	t_sol	result;

	result.size = 0;
	pos.y = -1;
	if ((info.error = open(info.adress, O_RDONLY)) == -1)
		return (result);
	while (pos.letter2[0] != '\n')
		read(info.error, pos.letter2, 1);
	while (++pos.y < info.hauteur)
	{
		pos.x = 0;
		while (pos.x < info.largeur)
		{
			read(info.error, pos.letter2, 1);
			ta = forestofifs(pos, info, ta);
			if (ta[pos.y][pos.x] > result.size)
				result = result_upd(result, pos, ta);
			if (pos.letter2[0] != '\n')
				pos.x++;
		}
	}
	close(info.error);
	return (result);
}

int			main(int ac, char **av)
{
	t_map	info;
	int		i;
	int		**tab;
	t_sol	sol;

	if (ac != 2)
		errorreturn();
	i = 0;
	info.adress = av[1];
	info = mapinit(info);
	tab = malloc(sizeof(int *) * (info.hauteur));
	while (i < info.hauteur)
		tab[i++] = malloc(sizeof(int *) * (info.largeur + 1));
	sol = convert(tab, info);
	if (sol.size == 0)
		errorreturn();
	printsol(info, sol);
	free(tab);
}
