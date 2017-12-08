#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int		map[104][4][2];

int ft_checkmap(int mapfile)
{
	char	buff;
	int		row;
	int		col;
	int		newl;

	row = 0;
	col = 0;
	newl = 0;
	while (read(mapfile, &buff, 1))
	{
		if (buff == '\n' && newl == 1)
			newl = 0;
		else if (buff == '#')
		{
			map[row][col][0] = col;
			map[row][col++][1] = row % 4;
		}
		else if (buff == '.')
			col++;
		else if (buff == '\n' && col != 0)
		{
			if (col != 4)
				return (0);
			col = 0;
			row++;
			if (row % 4 == 0)
				newl = 1;
		}
		else
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
			if (ft_checkmap(mapfile))
			{
				for (int i = 0; i < 16; i++)
				{
					for (int j= 0; j < 4; j++)
					{
						printf("%dx%d ", map[i][j][0], map[i][j][1]);
					}
					if ((i + 1) % 4 == 0)
						printf("\n");
					printf("\n");
				}
			}
			else
				printf("mapa defecta\n");
		}
	}
	return (0);
}
