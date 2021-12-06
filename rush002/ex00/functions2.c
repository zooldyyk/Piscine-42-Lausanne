/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   functions2.c                                         :::      ::::::::   */
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

t_trad	*ft_parse(char *filename, int *nblines)
{
	t_trad	*res;
	int		fd;
	int		*char_lines;
	char	**text;

	fd = open(filename, O_RDONLY);
	if (fd != -1)
	{
		ft_count_lines(fd, nblines);
		close(fd);
		fd = open(filename, O_RDONLY);
		ft_count_char_lines(fd, &char_lines, *nblines);
		close(fd);
		fd = open(filename, O_RDONLY);
		ft_store_text(fd, &text, char_lines, *nblines);
		close(fd);
		ft_parse_file(text, &res, *nblines);
		free(char_lines);
		ft_array_free((void *)text, *nblines);
		return (res);
	}
	else
		return (NULL);
}

char	*ft_trim_input(char *input)
{
	int		i;
	int		input_start;
	char	*output;

	i = 0;
	input_start = -1;
	while (i < ft_strlen(input))
	{
		if (input[i] < '0' || input[i] > '9')
		{
			return (NULL);
		}
		if (input_start == -1 && (input[i] != '0' || i == ft_strlen(input) - 1))
		{
			input_start = i;
		}
		i++;
	}
	if (input_start == -1)
		return (NULL);
	output = malloc(ft_strlen(input + input_start));
	ft_strncpy(output, (input + input_start),
		ft_strlen(input + input_start) + 1);
	return (output);
}

char	*ft_search_value(char *search, t_trad *dict, int nblines)
{
	int	i;

	i = 0;
	while (i < nblines)
	{
		if (ft_strcmp(dict[i].str, search) == 0)
		{
			return (dict[i].text);
		}
		i++;
	}
	return (NULL);
}

int	ft_split_number(char *input, t_trad *dict, int nblines)
{
	int		i;
	int		j;
	char	*tree;

	if (ft_strcmp(input, "0"))
	{
		i = (3 - (ft_strlen(input) % 3)) % 3;
		j = 0;
		tree = malloc(sizeof(char) * 3);
		while (j < ft_strlen(input))
		{
			while (i < 3)
				tree[i++] = input[j++];
			i = 0;
			if (!ft_print(tree, dict, nblines, ft_strlen(input + j)))
				return (0);
			if (j < ft_strlen(input))
				ft_putstr(" ");
		}
		free(tree);
	}
	else
		ft_putstr(ft_search_value("0", dict, nblines));
	ft_putstr("\n");
	return (1);
}
