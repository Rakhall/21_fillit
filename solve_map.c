/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:08:57 by sstannis          #+#    #+#             */
/*   Updated: 2019/02/23 15:02:05 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*create_map(int size)
{
	char	*map;
	int		len;
	int		i;

	i = 0;
	len = size * size;
	map = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		map[i] = '.';
		i++;
	}
	map[i] = '\0';
	return (map);
}

int		put_tetr(t_tetr *tetrino, char *map, int index, int putdel)
{
	int		crd[4];
	int		i;
	int		j;
	int		size;

	size = ft_sqrt(ft_strlen(map));
	j = -1;
	crd[0] = index % size;
	crd[1] = index / size;
	while (++j < 4)
	{
		crd[2] = crd[0] + tetrino->x[j];
		crd[3] = crd[1] + tetrino->y[j];
		i = crd[3] * size + crd[2];
		if (crd[2] < 0 || crd[3] < 0 || crd[2] > size - 1 || crd[3] > size - 1)
			return (0);
		if ((putdel && map[i] != '.') || (!putdel && map[i] != tetrino->letter))
			return (0);
		if (putdel)
			map[i] = tetrino->letter;
		else
			map[i] = '.';
	}
	return (1);
}

int		solver(char *map, t_tetr *tetrino, int map_size)
{
	int		i;

	i = 0;
	if (!tetrino)
		return (1);
	while (i < (map_size * map_size))
	{
		if (put_tetr(tetrino, map, i, 1))
		{
			if (solver(map, tetrino->next, map_size))
			{
				return (1);
			}
		}
		put_tetr(tetrino, map, i, 0);
		i++;
	}
	return (0);
}

char	*solve_map(int count, t_tetr *tetrino)
{
	char	*map;
	int		size;

	size = 1;
	while ((size * size) < (count * 4))
		size++;
	map = create_map(size);
	while (!solver(map, tetrino, size))
	{
		size++;
		free(map);
		map = create_map(size);
	}
	return (map);
}
