/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:40:14 by ccristia          #+#    #+#             */
/*   Updated: 2017/12/10 18:50:46 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	list
{
	int 		map[4][2];
	struct list	*next;
	struct list *back;
}				t_nod;

t_nod		*ft_movetop(int elm[4][2], t_nod *list)
{
	t_nod	*nod;
	int		i;
	int		minx;
	int		miny;

	i = -1;
	minx = 4;
	miny = 4;
	while (++i < 4)
	{
		if (elm[i][0] < minx)
			minx = elm[i][0];
		if (elm[i][1] < miny)
			miny = elm[i][1];
	}
	nod = (t_nod *)malloc(sizeof(t_nod));
	if (nod == NULL)
		return (NULL);
	i = -1;
	while (++i < 4)
	{
		nod->map[i][0] = elm[i][0] - minx;
		nod->map[i][1] = elm[i][1] - miny;
	}
	nod->next = NULL;
	if (list != NULL)
	{
		list->next = nod;
		nod->back = list;
	}
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

t_nod		*ft_checkelm(char *s, t_nod *list)
{
	int 	i;
	int 	v;
	int 	pix;
	int		elm[4][2];
	int		nr;

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
	return (ft_movetop(elm, list));
}

int	ft_read(int mapfile)
{
	t_nod	*list;
	char	buff[22];
	int		i;

	list = NULL;
	while (read(mapfile, &buff, 21))
	{
		buff[21] = '\0';
		if ((list = ft_checkelm(buff, list)) == NULL)
			return (0);
	}
	while (list->back != NULL)
		list = list->back;
	while (list != NULL)
	{
		i = 0;
		while (i < 4)
		{
			printf("x - |%d|, y - |%d|\n", list->map[i][0], list->map[i][1]);
			i++;
		}
		list = list->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	mapfile;
	int a = 9;
	int b = 5;
	int c = 4;
	int d = 3;

	if (argc == 2)
	{
		mapfile = open(argv[1], O_RDONLY);
		if (mapfile)
		{
			if (ft_read(mapfile))
			{
				printf("mapa corecta\n");
			}
			else
				printf("mapa defecta\n");
		}
	}
	mapfile = ((a > b) ? b : a) > ((c > d) ? d : c) ?
		((c > d) ? d : c) : ((a > b) ? b : a);
	printf("numar - |%d|\n", mapfile);
	return (0);
}
