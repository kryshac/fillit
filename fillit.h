/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 19:18:28 by ccristia          #+#    #+#             */
/*   Updated: 2017/12/13 19:24:59 by ccristia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_list
{
	int				map[4][2];
	char			c;
	struct s_list	*next;
}					t_nod;
int					ft_min_2d_array(int *elm, int x, int y, int col);
int					ft_algoritm(t_nod *list, int blocks);
void				ft_print_map(char **map);
void				ft_putchar(char c);
void				ft_remove_elm(t_nod *list, char **map);
void				ft_free_map(char **map);
void				ft_print_elm(t_nod *list);
char				**ft_malloc_map(int mapsize);
int					ft_min_size(int blocks);
void				ft_lstdel(t_nod *alst);
#endif
