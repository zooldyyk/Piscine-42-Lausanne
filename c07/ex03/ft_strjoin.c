/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 15:27:42 by eschmid           #+#    #+#             */
/*   Updated: 2021/07/25 16:50:19 by eschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}*/
char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		a;
	int		c;
	char	*new_str;

	new_str = malloc(sizeof(strs));
	i = 0;
	c = 0;
	while (i < size)
	{
		a = 0;
		while (strs[i][a] != '\0')
		{
			new_str[c++] = strs[i][a++];
		}
		a = 0;
		while (sep[a] != '\0' && i != size - 1)
		{
			new_str[c++] = sep[a++];
		}	
		i++;
	}
	new_str[c] = '\0';
	return (new_str);
}
/*int main ()
{
	char *strs[3];

	strs[2] = "GIGI";
	strs[0] = "PETE MOI";
	strs[1] = "LE CUL";
	ft_putstr(ft_strjoin(3, strs, " "));
}*/
