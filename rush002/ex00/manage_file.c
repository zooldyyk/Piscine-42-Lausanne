/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   manage_file.c                                        :::      ::::::::   */
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

void	ft_count_lines(int fd, int *nblines)
{
	char	temp;	
	int		flag;

	*nblines = 0;
	flag = 0;
	while (read(fd, &temp, 1))
	{
		if (temp == '\n' && flag == 1)
		{
			flag = 0;
			(*nblines)++;
		}
		else if (temp != '\n')
		{
			flag = 1;
		}
	}
}

void	ft_count_char_lines(int fd, int **char_lines, int nblines)
{
	int		i;
	int		j;
	int		flag;
	char	temp;

	*char_lines = malloc(sizeof(int) * nblines);
	i = 0;
	j = 0;
	flag = 0;
	while (read(fd, &temp, 1))
	{
		j++;
		if (temp == '\n' && flag == 1)
		{
			flag = 0;
			*(*char_lines + i) = j;
			j = 0;
			i++;
		}
		else if (temp != '\n')
		{
			flag = 1;
		}
	}
}

void	ft_store_text2(char ***text, char temp, int **ind, int *flag)
{
	if (temp == '\n' && *flag == 1)
	{
		*flag = 0;
		*(*(*text + (*ind)[0]) + (*ind)[1]) = '\0';
		(*ind)[1] = 0;
		(*ind)[0]++;
	}
	else if (temp != '\n')
	{
		*flag = 1;
		*(*(*text + (*ind)[0]) + (*ind)[1]) = temp;
		(*ind)[1]++;
	}
}

void	ft_store_text(int fd, char ***text, int *char_lines, int nblines)
{
	int		*ind;
	int		flag;
	char	temp;

	ind = malloc(sizeof(int) * 2);
	*text = malloc(sizeof(char *) * nblines);
	ind[0] = 0;
	while (ind[0] < nblines)
	{	
		*(*text + ind[0]) = malloc(sizeof(char) * (char_lines[ind[0]] + 1));
		ind[0]++;
	}
	ind[0] = 0;
	ind[1] = 0;
	flag = 0;
	while (read(fd, &temp, 1))
	{
		ft_store_text2(text, temp, &ind, &flag);
	}
	free(ind);
}

void	ft_parse_file(char **text, t_trad **dict, int nblines)
{
	t_trad	*new_trad;
	int		i;
	int		j;

	*dict = malloc(sizeof(t_trad) * nblines);
	i = 0;
	while (i < nblines)
	{
		new_trad = malloc(sizeof(t_trad));
		j = 0;
		while (text[i][j] >= '0' && text[i][j] <= '9')
			j++;
		new_trad->str = malloc(sizeof(char) * (j + 1));
		ft_strncpy(new_trad->str, (*(text + i)), j);
		new_trad->str[j] = '\0';
		while (text[i][j] != ':')
			j++;
		j++;
		while (text[i][j] == ' ')
			j++;
		new_trad->text = malloc(sizeof(char) * ft_strlen(&text[i][j]));
		ft_strncpy(new_trad->text, &text[i][j], ft_strlen(&text[i][j]) + 1);
		(*dict)[i] = *new_trad;
		i++;
	}
}
