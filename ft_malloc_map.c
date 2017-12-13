/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 19:16:10 by ccristia          #+#    #+#             */
/*   Updated: 2017/12/13 19:18:44 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
