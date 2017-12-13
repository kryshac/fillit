/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_elm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:56:38 by ccristia          #+#    #+#             */
/*   Updated: 2017/12/13 18:56:55 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
