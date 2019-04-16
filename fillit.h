/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 18:48:12 by sstannis          #+#    #+#             */
/*   Updated: 2019/02/15 20:38:44 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 21

# include "libft/includes/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# define ABSOL(number) ((number) > 0 ? (number):-(number))
# define E(p) if (p) { ft_putstr("error\n"); exit(0); }

typedef struct			s_tetr
{
	char				x[4];
	char				y[4];
	char				letter;
	struct s_tetr		*next;
}						t_tetr;

int						main(int argc, char **argv);
int						ft_validate(t_tetr *tetrino, int tet_num);
int						ft_checkblock(t_tetr *tmp);
void					ft_checkconnect(t_tetr *tmp, int *flag,
		int st, int *con_num);
void					print_map(const char *str);
t_tetr					*ft_open(int fd, int *tet_num);
int						ft_newtetr(t_tetr **tetrino, char *buff, char letter);
int						ft_checkbuff(char *buff);
void					ft_tetradd(t_tetr **start, t_tetr *new);
t_tetr					*ft_create(char sym);
char					*solve_map(int count, t_tetr *tetrino);
int						solver(char *map, t_tetr *tetrino, int map_size);
int						put_tetr(t_tetr *tetrino, char *map,
		int index, int putdel);
char					*create_map(int size);
int						find_square(int counter);

#endif
