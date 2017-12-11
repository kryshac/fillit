/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoritm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:30:17 by ccristia          #+#    #+#             */
/*   Updated: 2017/12/11 15:37:41 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_min_size(int blocks)
{
	int i;

	i = 0;
	while (i * i < blocks * 4)
		i++;
	printf("numar patrat - %d\n", i);
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

char	**ft_malloc_map(int blocks)
{
	char	**map;
	int		mapsize;
	int		i;

	mapsize = ft_min_size(blocks);
	map = (char **)malloc(sizeof(char *) * (mapsize + 1));
	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < blocks)
	{
		map[i] = (char *)malloc(sizeof(char) * mapsize);
		if (map[i] == NULL)
			return (NULL);
		i++;
	}
	ft_setmap_point(map, mapsize);
	return (map);
}

void	ft_printmap(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{

		j = 0;
		while (map[i][j])
			write(1, &map[i][j++], 1);
		write(1, "\n", 1);
		i++;
	}
}

int	ft_algoritm(t_nod *list, int blocks)
{
	char	**map;
	int		i;


	if ((map = ft_malloc_map(blocks)) == NULL)
		return (0);
	ft_printmap(map);
	printf("numar de elemente - %d\n", blocks);
	while (list != NULL)
	{
		i = 0;
		while (i < 4)
		{
			printf("x - |%d|, y - |%d|\n", list->map[i][0], list->map[i][1]);
			i++;
		}
		printf("\n");
		list = list->next;
	}
	return (1);
}
