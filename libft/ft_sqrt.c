/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:40:10 by sstannis          #+#    #+#             */
/*   Updated: 2018/11/21 15:40:14 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t		ft_sqrt(size_t nb)
{
	size_t c;

	c = 1;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	else
	{
		while (c < nb)
		{
			if (c * c == nb)
				return (c);
			c++;
		}
	}
	return (0);
}
