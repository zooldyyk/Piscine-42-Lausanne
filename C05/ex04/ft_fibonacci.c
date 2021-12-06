/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 20:05:49 by eschmid           #+#    #+#             */
/*   Updated: 2021/07/21 17:41:36 by eschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0 || index == 1)
		return (index);
	else
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
/*int main()
{
	printf("fibo index -3 = %d\n", ft_fibonacci(-3));
	printf("fibo index 1 = %d\n", ft_fibonacci(1));
	printf("fibo index 2 = %d\n", ft_fibonacci(2));
	printf("fibo index 5 = %d\n", ft_fibonacci(5));
	printf("fibo index 10 = %d\n", ft_fibonacci(10));
	printf("fibo index 15 = %d\n", ft_fibonacci(15));
	printf("fibo index 25 = %d\n", ft_fibonacci(25));
}*/
