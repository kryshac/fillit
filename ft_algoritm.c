/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoritm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:30:17 by ccristia          #+#    #+#             */
/*   Updated: 2017/12/13 01:45:00 by ccristia         ###   ########.fr       */
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

int		ft_check_exist(t_nod *lis, char **ma, int rn, int co, int max)
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
	ma[rn + lis->map[0][0]][co + lis->map[0][1]] = lis->c;
	ma[rn + lis->map[1][0]][co + lis->map[1][1]] = lis->c;
	ma[rn + lis->map[2][0]][co + lis->map[2][1]] = lis->c;
	ma[rn + lis->map[3][0]][co + lis->map[3][1]] = lis->c;
	return (1);
}

// int		ft_test(t_nod *list, char **map, int max)
// {
// 	int 	rnd;
// 	int		col;
//
// 	rnd = 0;
// 	while (rnd < max)
// 	{
// 		col = 0;
// 		while (col < max)
// 		{
// 			if (map[rnd][col] == '.' && ft_check_exist(list, map, rnd, col, max))
// 			{
// 				if (list->next)
// 					list = list->next;
// 				else
// 					return (0);
// 			}
// 			col++;
// 		}
// 		rnd++;
// 	}
// 	return (1);
// }

void	ft_print_elm(t_nod *list)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if ((list->map[0][0] == i && list->map[0][1] == j) ||
				(list->map[1][0] == i && list->map[1][1] == j) ||
				(list->map[2][0] == i && list->map[2][1] == j) ||
				(list->map[3][0] == i && list->map[3][1] == j))
				printf("#");
			else
				printf(" ");
			j++;
		}
		printf("\n");
		i++;
	}
}

int		ft_test(t_nod *list, char **map, int rnd, int col, int max)
{
	int irnd;
	int icol;

	irnd = rnd;
	icol = col;
	while (irnd < max)
	{
		while (icol < max)
		{
			if (map[irnd][icol] == '.' &&
				ft_check_exist(list, map, irnd, icol, max))
			 	return (1);
			icol++;
		}
		icol = 0;
		irnd++;
	}
	return (0);
}

int	ft_retry(t_nod *list, char **map, int max)
{
	int	rnd;
	int	col;

	rnd = 0;
	while (rnd < max)
	{
		col = 0;
		while (col < max)
		{
			if (ft_test(list, map, rnd, col, max))
			{
				if (list->next == NULL)
					return (1);
				else if (ft_retry(list->next, map, max))
					return (1);
				else
					ft_remove_elm(list, map);
			}
			col++;
		}
		rnd++;
	}
	return (0);
}

int	ft_algoritm(t_nod *list, int blocks)
{
	char	**map;
	int		mapsize;

	mapsize = ft_min_size(blocks);
	if ((map = ft_malloc_map(mapsize)) == NULL)
	 	return (0);
	ft_retry(list, map, mapsize);
	ft_print_map(map);
	return (1);
}
