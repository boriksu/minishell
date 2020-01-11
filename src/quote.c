/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2019/10/04 18:33:09 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		ft_find_quote(char *str)
{
	int i;
	int dq;
	int q;

	i = 0;
	dq = 0;
	q = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '"' && q == 0 &&
				((i > 0 && str[i - 1] != '\\') || i == 0))
			dq = dq == 0 ? 2 : 0;
		else if (str[i] == '\'' && dq == 0)
			q = q == 0 ? 1 : 0;
		i++;
	}
	return (q + dq);
}

char	*ft_quote(char *str)
{
	int		k;
	char	*temp;
	char	*temp1;
	char	*new;

	temp1 = ft_strdup(str);
	while ((k = ft_find_quote(temp1)) != 0)
	{
		k == 1 ? ft_putstr("quote> ") : ft_putstr("dquote> ");
		get_next_line(0, &new);
		temp = ft_strjoin(temp1, "\n");
		ft_strdel(&temp1);
		temp1 = ft_strjoin(temp, new);
		ft_strdel(&temp);
		ft_strdel(&new);
	}
	return (temp1);
}
