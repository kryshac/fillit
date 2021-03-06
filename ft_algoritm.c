/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoritm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:30:17 by ccristia          #+#    #+#             */
/*   Updated: 2017/12/16 17:39:10 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_check_exist(t_nod *lis, char **ma, int vec[2], int max)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (vec[0] + lis->map[i][0] >= max)
			return (0);
		if (vec[1] + lis->map[i][1] >= max)
			return (0);
		if (ma[vec[0] + lis->map[i][0]][vec[1] + lis->map[i][1]] != '.')
			return (0);
		i++;
	}
	ma[vec[0] + lis->map[0][0]][vec[1] + lis->map[0][1]] = lis->c;
	ma[vec[0] + lis->map[1][0]][vec[1] + lis->map[1][1]] = lis->c;
	ma[vec[0] + lis->map[2][0]][vec[1] + lis->map[2][1]] = lis->c;
	ma[vec[0] + lis->map[3][0]][vec[1] + lis->map[3][1]] = lis->c;
	return (1);
}

int	ft_backtraking(t_nod *list, char **map, int max)
{
	int	vec[2];

	vec[0] = 0;
	while (vec[0] < max)
	{
		vec[1] = 0;
		while (vec[1] < max)
		{
			if (ft_check_exist(list, map, vec, max))
			{
				if (list->next == NULL)
					return (1);
				else if (ft_backtraking(list->next, map, max))
					return (1);
				else
					ft_remove_elm(list, map);
			}
			vec[1]++;
		}
		vec[0]++;
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
	while (ft_backtraking(list, map, mapsize) == 0)
	{
		ft_free_map(map);
		mapsize++;
		if ((map = ft_malloc_map(mapsize)) == NULL)
			return (0);
	}
	ft_print_map(map);
	ft_free_map(map);
	ft_lstdel(list);
	return (1);
}
