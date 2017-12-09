/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:40:14 by ccristia          #+#    #+#             */
/*   Updated: 2017/12/09 17:08:00 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int **ft_movetop(int **elm)
{
	int	i;
	int	minx;
	int	miny;

	i = 0;
	minx = 4;
	miny = 4;
	while (i < 4)
	{
		if (elm[i][0] < minx)
			minx = elm[i][0];
		if (elm[i][1] < miny)
			miny = elm[i][1];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		elm[i][0] -= minx;
		elm[i][1] -= miny;
		i++;
	}
	return (elm);
}

int	ft_elemcheck(char *s, int i)
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

int	**ft_checkelm(char *s)
{
	int 	i;
	int 	v;
	int 	pix;
	int				elm[4][2];

	i = 0;
	v = 0;
	pix = 4;
	while (s[i])
	{
		if (s[i] == '#')
		{
			elm[v][0] = i / 5;
			elm[v][1] = i - i / 5 * 5;
			v += ft_elemcheck(s, i);
			pix--;
		}
		else if ((i % 5 == 4 && s[i] != '\n') || (i != 20 && i % 5 != 4 &&
			s[i] != '.') || (i == 20 && s[i] != '\n'))
			return (NULL);
		i++;
	}
	if (pix < 0 || !(v == 6 || v == 8))
		return (NULL);
	return (ft_movetop(elm));
}

int	ft_read(int mapfile)
{
	char	buff[22];

	while (read(mapfile, &buff, 21))
	{
		buff[21] = '\0';
		printf("\n\n");
		if (ft_checkelm(buff) == 0)
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	mapfile;

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
	return (0);
}
