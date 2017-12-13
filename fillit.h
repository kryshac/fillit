/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccristia <ccristia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 19:18:28 by ccristia          #+#    #+#             */
/*   Updated: 2017/12/13 01:45:33 by ccristia         ###   ########.fr       */
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
	struct s_list	*back;
}					t_nod;
int					ft_min_2d_array(int *elm, int x, int y, int col);
int					ft_algoritm(t_nod *list, int blocks);
void				ft_print_map(char **map);
void				ft_putchar(char c);
void				ft_remove_elm(t_nod *list, char **map);
#endif
