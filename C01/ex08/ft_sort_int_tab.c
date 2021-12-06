/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 18:37:25 by eschmid           #+#    #+#             */
/*   Updated: 2021/07/29 19:40:49 by eschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab( int *tab, int size)
{
	int	i;
	int	stock;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			stock = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = stock;
			i = -1;
		}
		i++;
	}
}
/*int main ()
{
	int tab[7];

	tab[0] = 0;
	tab[1] = 1;
	tab[2] = 7;
	tab[3] = 4;
	tab[4] = 5;
	tab[5] = 8;
	tab[6] = 2;
	ft_sort_int_tab(tab, 7);
	int i;
	i = 0;
	while (i <= 6)
	{
		printf("%d\n", tab[i]);
		i++;
	
	}
}*/
