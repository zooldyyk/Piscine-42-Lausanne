/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 17:03:43 by eschmid           #+#    #+#             */
/*   Updated: 2021/07/12 17:09:16 by eschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{	
	char	alphabet;

	alphabet = 'a';
	while (alphabet <= 'z')
	{	
		write (1, &alphabet, 1);
		alphabet++;
	}
}
