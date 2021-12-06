/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:38:07 by eschmid           #+#    #+#             */
/*   Updated: 2021/07/28 18:17:30 by eschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*char ft_putstr(char *str)
{
	int	i;

	i = 0;

	while(str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (*str);
}*/
char	*ft_strdup(char *src)
{
	int		stock;
	char	*str;
	char	*stock1;
	int		i;

	i = 0;
	stock1 = src;
	stock = ft_strlen(src);
	str = malloc(sizeof(char) * stock + 1);
	while (i != stock)
	{
		str[i] = stock1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*int main (int argc, char **argv)
{
	if (argc != 2)
		return (0);
	ft_putstr(ft_strdup(argv[1]));
	return (0);
}*/
