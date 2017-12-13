/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:40:14 by ccristia          #+#    #+#             */
/*   Updated: 2017/12/13 01:33:08 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_nod	*ft_movetop(int elm[4][2], t_nod *list, char c)
{
	t_nod	*nod;
	int		i;

	nod = (t_nod *)malloc(sizeof(t_nod));
	if (nod == NULL)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		nod->map[i][0] = elm[i][0] - ft_min_2d_array((int *)elm, 4, 2, 0);
		nod->map[i][1] = elm[i][1] - ft_min_2d_array((int *)elm, 4, 2, 1);
		nod->c = c;
		i++;
	}
	nod->next = NULL;
	if (list != NULL)
	{
		list->next = nod;
		nod->back = list;
	}
	else
		nod->back = NULL;
	return (nod);
}

int		ft_elemcheck(char *s, int i)
{
	int v;

	v = 0;
	if (i != 0 && s[i - 1] == '#')
		v++;
	if (s[i + 1] == '#')
		v++;
	if (i > 4 && s[i - 5] == '#')
		v++;
	if (i < 15 && s[i + 5] == '#')
		v++;
	return (v);
}

t_nod	*ft_checkelm(char *s, t_nod *list, char c)
{
	int	i;
	int	v;
	int	pix;
	int	elm[4][2];
	int	nr;

	i = -1;
	v = 0;
	pix = 4;
	nr = 0;
	while (s[++i])
	{
		if (s[i] == '#')
		{
			elm[nr][0] = i / 5;
			elm[nr++][1] = i - i / 5 * 5;
			v += ft_elemcheck(s, i);
			pix--;
		}
		else if (((i % 5 == 4 && s[i] != '\n') || (i != 20 && i % 5 != 4 &&
			s[i] != '.') || (i == 20 && s[i] != '\n')) || (i == 20 &&
				(pix < 0 || !(v == 6 || v == 8))))
			return (NULL);
	}
	return (ft_movetop(elm, list, c));
}

t_nod	*ft_read(int mapfile)
{
	t_nod	*list;
	char	buff[22];
	char	c;

	list = NULL;
	c = 'A';
	while (read(mapfile, &buff, 21))
	{
		buff[21] = '\0';
		if ((list = ft_checkelm(buff, list, c)) == NULL)
			return (NULL);
		else
			c++;
	}
	return (list);
}

int		main(int argc, char **argv)
{
	t_nod	*list;
	int		blocks;
	int		mapfile;

	if (argc == 2)
	{
		mapfile = open(argv[1], O_RDONLY);
		if (mapfile)
		{
			if ((list = ft_read(mapfile)) != NULL)
			{
				blocks = 1;
				while (list->back != NULL)
				{
					list = list->back;
					blocks++;
				}
				if (!ft_algoritm(list, blocks))
					printf("eroare\n");
			}
			else
				printf("mapa defecta\n");
		}
	}
	return (0);
}
