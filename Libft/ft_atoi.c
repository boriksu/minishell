/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 11:27:21 by dholiday          #+#    #+#             */
/*   Updated: 2019/04/17 14:49:00 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	flow(const char *str)
{
	int i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int					i;
	int					c;
	unsigned long long	b;
	int					k;

	b = 0;
	k = 1;
	i = flow(str);
	if (str[i] == '-')
	{
		i++;
		k = -1;
	}
	else if (str[i] == '+')
		i++;
	while ((c = str[i++]) > 47 && c < 58)
	{
		b = b * 10 + (c + 2) % 10;
		if (b >= 9223372036854775807 && k == 1)
			return (-1);
		else if (b > 9223372036854775807 && k == -1)
			return (0);
	}
	return (b * k);
}
