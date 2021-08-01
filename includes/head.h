/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleger <fleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:00:24 by fleger            #+#    #+#             */
/*   Updated: 2019/09/18 22:51:33 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_map
{
	int		hauteur;
	int		largeur;
	char	vide;
	char	obstacle;
	char	plein;
	char	*adress;
	int		error;
}				t_map;

typedef struct	s_sol
{
	int		x;
	int		y;
	int		size;
	char	letter;
	char	letter2[1];

}				t_sol;

t_sol			result_upd(t_sol result, t_sol pos, int **ta);
t_sol			convert(int **tab, t_map info);
void			ft_putchar(char c);
void			errorreturn(void);
int				**forestofifs(t_sol pos, t_map info, int **ta);
int				minimum(int haut_gauche, int haut, int gauche);
t_map			printsol(t_map map, t_sol sol);
void			selectout(t_map map, t_sol sol, t_sol pos);
int				sub_sign(char *substr);
int				ft_atoi(char *str);
t_map			mapinit(t_map map);
t_map			readheader(int i, t_map map);
#endif
