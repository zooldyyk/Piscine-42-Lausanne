#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*tabel;

	if (min >= max)
		return (NULL);
	tabel = malloc(sizeof(int) * (max - min));
	i = 0;
	while (i < max - min)
	{
		tabel[i] = min + i;
		i++;
	}
	return (tabel);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	if (((long)max - (long) min > INT_MAX))
		return (-1);
	*range = ft_range(min, max);
	if (max <= min)
		return (0);
	return (max - min);
}
/*int main ()
{
	int	stock;
	int *range1;
	int **range;
	int	min;
	int	max;
	int	i;

	range = &range1;
	range1 = &stock;

	min = 6;
	max = 50;
	i = 0;

	stock = ft_ultimate_range(range, min, max);
	
	printf("%d\n", stock);
	return (0);
}*/
