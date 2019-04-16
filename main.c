/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 11:45:17 by sstannis          #+#    #+#             */
/*   Updated: 2019/02/23 15:03:10 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(const char *str)
{
	int		i;
	int		size;
	int		column;

	i = ft_strlen(str);
	size = ft_sqrt(i);
	column = 0;
	i = 0;
	while (i < size)
	{
		while (column < size)
		{
			ft_putchar(str[i * size + column]);
			column++;
		}
		if (str[i * size + column] != '\0')
			ft_putchar('\n');
		column = 0;
		i++;
	}
	ft_putchar('\n');
}

void	ft_checkconnect(t_tetr *tmp, int *flag, int st, int *con_num)
{
	int		i;

	*con_num = *con_num + 1;
	i = 0;
	flag[st] = 1;
	while (i < 4)
	{
		if (!flag[i] && (ABSOL(tmp->x[st] - tmp->x[i])
					+ ABSOL(tmp->y[st] - tmp->y[i])) == 1)
			ft_checkconnect(tmp, flag, i, con_num);
		i++;
	}
}

int		ft_checkblock(t_tetr *tmp)
{
	int		con_num;
	int		flag[4];
	int		i;

	i = 0;
	con_num = 0;
	while (i < 4)
	{
		flag[i] = 0;
		i++;
	}
	ft_checkconnect(tmp, flag, 0, &con_num);
	if (con_num != 4)
		return (0);
	return (1);
}

int		ft_validate(t_tetr *tetrino, int tet_num)
{
	t_tetr	*tmp;

	if (tet_num < 1 || tet_num > 26)
		E(1);
	tmp = tetrino;
	while (tmp)
	{
		if (!(ft_checkblock(tmp)))
			E(1);
		tmp = tmp->next;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	char	*map;
	t_tetr	*tetrino;
	int		fd;
	int		count;

	if (argc != 2)
	{
		ft_putstr("usage:fillit [tetraminos_file]\n");
		exit(0);
	}
	else
	{
		if ((fd = open(argv[1], O_RDONLY)) < 0)
			E(1);
		if ((tetrino = ft_open(fd, &count)))
		{
			if (ft_validate(tetrino, count))
				map = solve_map(count, tetrino);
		}
		else
			E(1);
	}
	print_map(map);
	exit(0);
}
