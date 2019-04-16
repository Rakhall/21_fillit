/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrino.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 21:10:16 by sstannis          #+#    #+#             */
/*   Updated: 2019/02/15 20:40:07 by mroland-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetr	*ft_create(char sym)
{
	t_tetr		*new;

	if ((new = (t_tetr*)malloc(sizeof(t_tetr))))
	{
		new->next = NULL;
		new->letter = sym;
	}
	return (new);
}

void	ft_tetradd(t_tetr **start, t_tetr *new)
{
	t_tetr	*tmp;

	if (*start == NULL)
		*start = new;
	else
	{
		tmp = *start;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

int		ft_checkbuff(char *buff)
{
	int		endl;
	int		dot;
	int		shrp;
	int		i;

	endl = 0;
	dot = 0;
	shrp = 0;
	i = -1;
	while (buff[++i])
	{
		if (buff[i] != '\n' && buff[i] != '.' && buff[i] != '#')
			return (0);
		endl += buff[i] == '\n' ? 1 : 0;
		dot += buff[i] == '.' ? 1 : 0;
		shrp += buff[i] == '#' ? 1 : 0;
	}
	if (dot != 12 || shrp != 4 || (buff[i - 1] != '\n' && buff[i - 2] != '\n')
			|| endl < 4 || endl > 5 || buff[0] == '\n')
	{
		return (0);
	}
	return (1);
}

int		ft_newtetr(t_tetr **tetrino, char *buff, char letter)
{
	int		m_iter;
	int		j;
	t_tetr	*cur_tet;
	int		cor[2];

	j = -1;
	m_iter = 0;
	if (!(cur_tet = ft_create(letter)))
		return (0);
	while (*buff)
	{
		if (*buff == '#')
		{
			if (!++j)
			{
				cor[0] = m_iter % 4;
				cor[1] = m_iter / 4;
			}
			cur_tet->x[j] = m_iter % 4 - cor[0];
			cur_tet->y[j] = m_iter / 4 - cor[1];
		}
		m_iter = *buff++ == '\n' ? m_iter : m_iter + 1;
	}
	ft_tetradd(tetrino, cur_tet);
	return (1);
}

t_tetr	*ft_open(int fd, int *tet_num)
{
	t_tetr	*tetrino;
	char	buff[BUFF_SIZE + 1];
	int		ret;
	int		last_buff;
	int		i;

	i = 0;
	tetrino = NULL;
	last_buff = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		last_buff = ret;
		if (ret < 20 || !(ft_checkbuff(buff)))
			return (0);
		if (!(ft_newtetr(&tetrino, buff, (i + 65))))
			return (0);
		*tet_num = ++i;
	}
	if (last_buff >= BUFF_SIZE)
		return (0);
	close(fd);
	return (tetrino);
}
