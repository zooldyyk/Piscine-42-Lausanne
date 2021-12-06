/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   print.c                                              :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*   By: bbourcy <marvin@42lausanne.ch>           +#+#+#+#+#+   +#+           */
/*   By: jjaqueme <marvin@42lausanne.ch>               #+#    #+#             */
/*                                                    ###   ########.fr       */
/*   Created: 2021/07/24 10:00:00 by team                                     */
/*   Updated: 2021/07/25 19:00:00 by team                                     */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_pow_ten(int pow)
{
	char	*tab;
	int		index;

	tab = malloc(sizeof(char) * (pow + 2));
	index = 1;
	tab[0] = '1';
	while (index <= pow)
	{
		tab[index] = '0';
		index++;
	}
	tab[index] = '\0';
	return (tab);
}

void	ft_prep_nb(char *output, char c0, char c1, char c2)
{
	output[0] = c0;
	output[1] = c1;
	output[2] = c2;
}

int	ft_print(char *tree, t_trad *dict, int nblines, int rest)
{
	char	*send;
	char	*test;

	test = ft_search_value(ft_pow_ten(rest), dict, nblines);
	if (test == NULL)
		return (0);
	send = malloc(sizeof(char) * 3);
	if (tree[0] != '0' && tree[0] != 0)
	{
		ft_prep_nb(send, tree[0], '\0', '\0');
		ft_putstr(ft_search_value(send, dict, nblines));
		ft_putstr(" ");
		ft_putstr(ft_search_value("100", dict, nblines));
		if (tree[1] != '0' || tree[2] != '0')
			ft_putstr(" ");
	}
	ft_print2(tree, dict, nblines, send);
	ft_print3(tree, dict, nblines, send);
	if (rest != 0)
	{
		ft_putstr(" ");
		ft_putstr(test);
	}
	free(send);
	return (1);
}

void	ft_print2(char *tree, t_trad *dict, int nblines, char *send)
{
	if (tree[1] != '0' && tree[1] != 0)
	{
		if (tree[1] == '1')
		{
			ft_prep_nb(send, tree[1], tree[2], '\0');
			ft_putstr(ft_search_value(send, dict, nblines));
		}
		else
		{
			ft_prep_nb(send, tree[1], '0', '\0');
			ft_putstr(ft_search_value(send, dict, nblines));
			if (tree[2] != '0' && tree[2] != 0)
				ft_putstr(" ");
		}
	}
}

void	ft_print3(char *tree, t_trad *dict, int nblines, char *send)
{
	if (tree[1] != '1' && tree[2] != '0' && tree[2] != 0)
	{
		ft_prep_nb(send, tree[2], '\0', '\0');
		ft_putstr(ft_search_value(send, dict, nblines));
	}
}
