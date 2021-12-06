/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 18:20:46 by eschmid           #+#    #+#             */
/*   Updated: 2021/07/29 18:46:45 by eschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	stock;

	i = 0;
	while (i <= size - 1)
	{
		stock = tab[i];
		tab[i] = tab[size - 1];
		tab[size - 1] = stock;
		i++;
		size--;
	}
}
/*int main()
{
	int tab[7];

	tab[0] = 0;
	tab[1] = 1;
	tab[2] = 2;
	tab[3] = 3;
	tab[4] = 4;
	tab[5] = 5;
	tab[6] = 6;
	ft_rev_int_tab(tab, 7);
	int i;
	i = 0;
	while (i <= 6)
	{
	printf("%d\n", tab[i]);
	i++;
	}
}*/
