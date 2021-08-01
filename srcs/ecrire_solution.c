/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ecrire_solution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleger <fleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:54:56 by smarty            #+#    #+#             */
/*   Updated: 2019/09/18 22:33:32 by fleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		selectout(t_map map, t_sol sol, t_sol pos)
{
	if (pos.letter == map.obstacle)
		ft_putchar(map.obstacle);
	else if ((pos.x > (sol.x - 1 - sol.size)) && (pos.x <= sol.x - 1)
			&& (pos.y > (sol.y - 1 - sol.size)) && (pos.y <= sol.y - 1))
		ft_putchar(map.plein);
	else if (pos.letter == '\n')
		ft_putchar('\n');
	else
		ft_putchar(map.vide);
}

t_map		printsol(t_map map, t_sol sol)
{
	char	letter[1];
	t_sol	pos;

	if ((map.error = open(map.adress, O_RDONLY)) == -1)
		return (map);
	while (letter[0] != '\n')
		read(map.error, letter, 1);
	pos.x = 0;
	pos.y = 0;
	while (pos.y < map.hauteur)
	{
		read(map.error, letter, 1);
		pos.letter = letter[0];
		selectout(map, sol, pos);
		pos.x++;
		if (letter[0] == '\n')
		{
			pos.x = 0;
			pos.y++;
		}
	}
	close(map.error);
	return (map);
}
