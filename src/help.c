/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2019/10/04 20:31:26 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_bye_space(char *str, int *i)
{
	while ((str[*i] == ' ' || (str[*i] >= 9 &&
			str[*i] <= 13)) && str[*i] != '\0')
		*i = *i + 1;
}

int		ft_only_space(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\t' && str[i] != '\n' && str[i] != '\v' &&
			str[i] != '\f' && str[i] != '\r' && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

char	**ft_find_point_comma(char *str)
{
	int		i;
	int		k;
	int		j;
	char	*temp;
	char	**mass;

	temp = ft_change_semicolon(str);
	mass = ft_strsplit(temp, ';');
	i = 0;
	k = 0;
	while (mass[i] != NULL)
	{
		j = 0;
		while (mass[i][j] != '\0')
		{
			if (mass[i][j] != str[k] && mass[i][j] == '+' && str[k] == ';')
				mass[i][j] = ';';
			j++;
			k++;
		}
		k++;
		i++;
	}
	ft_strdel(&temp);
	return (mass);
}

char	*ft_change_semicolon(char *str)
{
	int		i;
	int		q;
	int		dq;
	char	*temp;

	temp = ft_strdup(str);
	i = 0;
	q = 0;
	dq = 0;
	while (temp[i] != '\0')
	{
		if (temp[i] == '"' && q == 0)
			dq = dq == 0 ? 2 : 0;
		if (temp[i] == '\'' & dq == 0)
			q = q == 0 ? 1 : 0;
		if (temp[i] == ';' && q + dq != 0)
			temp[i] = '+';
		i++;
	}
	return (temp);
}
