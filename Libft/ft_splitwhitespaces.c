/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitwhitespaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:52:18 by dholiday          #+#    #+#             */
/*   Updated: 2019/10/04 20:05:34 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int		del_w(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
	return (0);
}

static	int		ft_sum_w_w(char const *d, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (d[i] != '\0')
	{
		if ((d[i] != c && d[i] != '\t' && d[i] != '\n'
			&& d[i] != '\v' && d[i] != '\f' && d[i] != '\r'))
		{
			while (d[i] != c && d[i] != '\t' && d[i] != '\n' &&
			d[i] != '\v' && d[i] != '\f' && d[i] != '\r' && d[i] != '\0')
				i++;
			k++;
		}
		else
			i++;
	}
	return (k);
}

static int		slovo_w(char **s, char const *d, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (d[i] != '\0')
	{
		j = 0;
		if ((d[i] != c && d[i] != '\t' && d[i] != '\n'
			&& d[i] != '\v' && d[i] != '\f' && d[i] != '\r'))
		{
			while (d[i] != c && d[i] != '\t' && d[i] != '\n' && d[i] != '\v'
			&& d[i] != '\f' && d[i] != '\r' && d[i++] != '\0')
				j++;
			s[k] = (char*)malloc(sizeof(**s) * (j + 1));
			if (!(s[k]))
				return (del_w(s, k));
			k++;
		}
		else
			i++;
	}
	return (1);
}

static void		record_w(char **s, char const *d, char c)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = 0;
	while (d[i] != '\0')
	{
		j = -1;
		if (d[i] != c && d[i] != '\t' && d[i] != '\n' && d[i] != '\v' &&
			d[i] != '\f' && d[i] != '\r')
		{
			while (d[i] != c && d[i] != '\t' && d[i] != '\n' && d[i] != '\v' &&
			d[i] != '\f' && d[i] != '\r' && d[i] != '\0')
				s[k][++j] = d[i++];
			s[k][++j] = '\0';
			k++;
		}
		else
			i++;
	}
	s[k] = 0;
}

char			**ft_splitwhitespaces(char const *str)
{
	int		sum;
	char	**s;
	int		i;
	char	c;

	i = 0;
	c = ' ';
	if (!(str))
		return (NULL);
	sum = ft_sum_w_w(str, c);
	s = (char**)malloc(sizeof(*s) * (sum + 1));
	if (!(s))
		return (NULL);
	if (!(slovo_w(s, str, c)))
		return (NULL);
	record_w(s, str, c);
	return (s);
}
