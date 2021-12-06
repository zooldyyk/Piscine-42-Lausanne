/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 13:02:36 by eschmid           #+#    #+#             */
/*   Updated: 2021/07/16 10:19:52 by eschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
	{	
		return (1);
	}
	while (str[i] != '\0')
	{
		if (str[i] > 90 && str[i] < 97)
		{
			return (0);
		}
		if (str[i] < 'A' || str[i] > 'z')
		{
			return (0);
		}
		i++;
	}
	return (1);
}
