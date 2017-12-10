/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_2d_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 20:29:47 by ccristia          #+#    #+#             */
/*   Updated: 2017/12/10 20:30:20 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_min_2d_array(int *elm, int x, int y, int col)
{
	int	i;
	int	min;

	i = 0;
	min = 4;
	while (i < x)
	{
		if (*(elm + i * y + col) < min)
			min = *(elm + i * y + col);
		i++;
	}
	return (min);
}
