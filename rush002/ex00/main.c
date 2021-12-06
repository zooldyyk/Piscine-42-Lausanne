/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                               :::      ::::::::   */
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

void	ft_array_free(void **tofree, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tofree[i]);
		i++;
	}
	free(tofree);
}

int	ft_error(char type)
{
	if (type == 'd')
		ft_putstr("Dict Error\n");
	else
		ft_putstr("Error\n");
	return (0);
}

void	manage_2_args(char **av, t_trad **dict, char **input, int *nblines)
{
	*dict = ft_parse("numbers.dict", nblines);
	*input = av[1];
}

void	manage_3_args(char **av, t_trad **dict, char **input, int *nblines)
{
	*dict = ft_parse(av[1], nblines);
	*input = av[2];
}

int	main(int argc, char **argv)
{
	char	*input;
	t_trad	*dict;
	int		nblines;

	if (argc == 2)
		manage_2_args(argv, &dict, &input, &nblines);
	else if (argc == 3)
		manage_3_args(argv, &dict, &input, &nblines);
	else
		return (ft_error('e'));
	if (dict == NULL)
		return (ft_error('d'));
	input = ft_trim_input(input);
	if (input == NULL)
		return (ft_error('e'));
	if (!ft_split_number(input, dict, nblines))
		return (ft_error('d'));
	return (0);
}
