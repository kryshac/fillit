/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoritm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:30:17 by ccristia          #+#    #+#             */
/*   Updated: 2017/12/11 21:49:17 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_min_size(int blocks)
{
	int i;

	i = 0;
	while (i * i < blocks * 4)
		i++;
	return (i);
}

void	ft_setmap_point(char **map, int mapsize)
{
	int	i;
	int	j;

	i = 0;
	while (i < mapsize)
	{
		j = 0;
		while (j < mapsize)
			map[i][j++] = '.';
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
}

char	**ft_malloc_map(int mapsize)
{
	char	**map;
	int		i;

	map = (char **)malloc(sizeof(char *) * (mapsize + 1));
	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < mapsize)
	{
		map[i] = (char *)malloc(sizeof(char) * (mapsize + 1));
		if (map[i] == NULL)
			return (NULL);
		i++;
	}
	ft_setmap_point(map, mapsize);
	return (map);
}

void	ft_printmap(char **map, int max)
{
	int	i;
	int	j;

	i = 0;
	while (i < max)
	{

		j = 0;
		while (j < max)
			write(1, &map[i][j++], 1);
		write(1, "\n", 1);
		i++;
	}
}

int		ft_check_exist(t_nod *lis, char **ma, int rn, int co, int max, char abc)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (rn + lis->map[i][0] >= max)
			return (0);
		if (co + lis->map[i][1] >= max)
			return (0);
		if (ma[rn + lis->map[i][0]][co + lis->map[i][1]] != '.')
			return (0);
		i++;
	}
	ma[rn + lis->map[0][0]][co + lis->map[0][1]] = abc;
	ma[rn + lis->map[1][0]][co + lis->map[1][1]] = abc;
	ma[rn + lis->map[2][0]][co + lis->map[2][1]] = abc;
	ma[rn + lis->map[3][0]][co + lis->map[3][1]] = abc;
	return (1);
}

int		ft_test(t_nod *list, char **map, int max)
{
	char	abc;
	int 	rnd;
	int		col;

	rnd = 0;
	abc = 'A';
	while (rnd < max)
	{
		col = 0;
		while (col < max)
		{
			if (map[rnd][col] == '.' && ft_check_exist(list, map, rnd, col, max, abc))
			{
				if (list->next)
				{
					abc++;
					list = list->next;
				}
				else
					return (0);
			}
			col++;
		}
		rnd++;
	}
	return (1);
}

int	ft_algoritm(t_nod *list, int blocks)
{
	char	**map;
	int		mapsize;
	// int		i;

	mapsize = ft_min_size(blocks);
	printf("numar - |%d|\n", mapsize);
	if ((map = ft_malloc_map(mapsize + 2)) == NULL)
	 	return (0);
	ft_test(list, map, mapsize);
	ft_printmap(map, mapsize);
	// printf("numar de elemente - %d\n", blocks);
	// while (list != NULL)
	// {
	// 	i = 0;
	// 	while (i < 4)
	// 	{
	// 		printf("x - |%d|, y - |%d|\n", list->map[i][0], list->map[i][1]);
	// 		i++;
	// 	}
	// 	printf("\n");
	// 	list = list->next;
	// }
	return (1);
}
