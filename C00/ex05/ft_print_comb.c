/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:44:21 by eschmid           #+#    #+#             */
/*   Updated: 2021/07/12 17:50:13 by eschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char centaine, char dixaine, char unite)
{
	write (1, &centaine, 1);
	write (1, &dixaine, 1);
	write (1, &unite, 1);
	if (centaine != '7' || dixaine != '8' || unite != '9')
	{
		write (1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	ac;
	char	bd;
	char	cu;

	ac = '0';
	while (ac <= '7')
	{
		bd = ac + 1;
		while (bd <= '8')
		{
			cu = bd + 1;
			while (cu <= '9')
			{
				putchar (ac, bd, cu);
				cu++;
			}
			bd++;
		}
		ac++;
	}
}
