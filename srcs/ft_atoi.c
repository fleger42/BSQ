/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:17:07 by smarty            #+#    #+#             */
/*   Updated: 2019/09/06 11:28:55 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		sub_sign(char *substr)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while ((substr[i] == '-') || (substr[i] == '+'))
	{
		if (substr[i] == '-')
			count++;
		i++;
	}
	if (count % 2 == 1)
		return (-1);
	return (1);
}

int		ft_atoi(char *str)
{
	int i;
	int nombre;
	int chiffre;
	int signe;

	chiffre = 0;
	nombre = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	signe = sub_sign(&str[i]);
	while ((str[i] == '-') || (str[i] == '+'))
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		chiffre = str[i] - 48;
		nombre = nombre * 10 + chiffre;
		i++;
	}
	nombre = nombre * signe;
	return (nombre);
}
