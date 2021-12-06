/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:04:53 by eschmid           #+#    #+#             */
/*   Updated: 2021/07/25 16:53:14 by eschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*tabel;

	if (min >= max)
		return (NULL);
	tabel = malloc(sizeof(int) * (max - min));
	i = 0;
	while (i < max - min)
	{
		tabel[i] = min + i;
		i++;
	}
	return (tabel);
}
/*int main ()
{
	int	*stock;
	int	min;
	int	max;
	int	i;

	min = 0;
	max = 50;
	i = 0;

	stock = ft_range(min, max);
	while ( i < max - min)
	{
		printf("%d\n", stock[i]);
		i++;
	}
	return (0);
}*/
