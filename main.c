/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:40:14 by ccristia          #+#    #+#             */
/*   Updated: 2017/12/16 17:26:41 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_nod	*ft_movetop(int elm[4][2], t_nod *list)
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
		i++;
	}
	nod->next = NULL;
	if (list != NULL)
	{
		list->next = nod;
		nod->c = list->c + 1;
	}
	else
		nod->c = 'A';
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

t_nod	*ft_checkelm(char *s, t_nod *list)
{
	int	i;
	int	vec;
	int	pix;
	int	elm[4][2];
	int	nr;

	i = -1;
	pix = 4;
	nr = 0;
	vec = 0;
	while (s[++i])
	{
		if (s[i] == '#')
		{
			elm[nr][0] = i / 5;
			elm[nr++][1] = i - i / 5 * 5;
			vec += ft_elemcheck(s, i);
			pix--;
		}
		if ((i % 5 == 4 && s[i] != '\n') ||
			(i != 20 && i % 5 != 4 && (s[i] != '.' && s[i] != '#')) ||
			pix < 0 || (i == 19 && !(vec == 6 || vec == 8)))
			return (NULL);
	}
	return (ft_movetop(elm, list));
}

int		ft_read(int mapfile)
{
	t_nod	*list;
	t_nod	*start;
	char	buff[21];
	int		blocks;
	char	c;

	list = NULL;
	start = NULL;
	c = ' ';
	blocks = 0;
	while (read(mapfile, &buff, 20))
	{
		c = ' ';
		buff[20] = '\0';
		if ((list = ft_checkelm(buff, list)) == NULL)
			return (0);
		if (start == NULL)
			start = list;
		blocks++;
		if (ft_setzero(buff) && read(mapfile, &c, 1) && c != '\n')
			return (0);
	}
	if (c == '\n' || blocks == 0 || !ft_algoritm(start, blocks))
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	int		mapfile;

	if (argc == 2)
	{
		mapfile = open(argv[1], O_RDONLY);
		if (mapfile)
		{
			if (ft_read(mapfile) == 0)
				ft_putstr("error\n");
		}
	}
	return (0);
}
