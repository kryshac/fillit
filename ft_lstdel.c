/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 19:21:20 by ccristia          #+#    #+#             */
/*   Updated: 2017/12/13 19:25:18 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_lstdel(t_nod *alst)
{
	t_nod	*pnt;
	t_nod	*tmp;

	pnt = alst;
	while (pnt)
	{
		tmp = pnt->next;
		free(pnt);
		pnt = tmp;
	}
	alst = NULL;
}
