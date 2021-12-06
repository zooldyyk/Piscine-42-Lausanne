/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft.h                                                 :::      ::::::::   */
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

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_trad {
	char	*str;
	char	*text;
}	t_trad;

int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strncpy(char *dest, char *src, unsigned int n);

void	ft_count_lines(int fd, int *nblines);
void	ft_count_char_lines(int fd, int **char_lines, int nblines);
void	ft_store_text(int fd, char ***text, int *char_lines, int nblines);
void	ft_parse_file(char **text, t_trad **dict, int nblines);

void	ft_prep_nb(char *output, char c0, char c1, char c2);
char	*ft_pow_ten(int pow);
int		ft_print(char *tree, t_trad *dict, int nblines, int rest);
void	ft_print2(char *tree, t_trad *dict, int nblines, char *send);
void	ft_print3(char *tree, t_trad *dict, int nblines, char *send);

void	ft_array_free(void **tofree, int size);
t_trad	*ft_parse(char *filename, int *nblines);
char	*ft_trim_input(char *input);
char	*ft_search_value(char *search, t_trad *dict, int nblines);
int		ft_split_number(char *input, t_trad *dict, int nblines);

#endif
