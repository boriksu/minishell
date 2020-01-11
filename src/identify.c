/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2019/10/04 16:37:37 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		ft_iden(t_env *all)
{
	char	**temp;
	char	*new;
	int		s;

	s = 1;
	if (ft_strncmp(all->line, "echo", 4) == 0)
		ft_echo(all);
	else if (ft_strncmp(all->line, "env", 3) == 0)
		ft_env(all);
	else if (ft_strncmp(all->line, "cd", 2) == 0)
		ft_cd(all);
	else if ((s = ft_strncmp(all->line, "setenv", 6)) == 0
					|| ft_strncmp(all->line, "unsetenv", 8) == 0)
	{
		temp = s == 0 ? ft_setenv(all, all->line) : ft_unsetenv(all);
		if (temp == NULL)
			return (1);
		ft_clean_mass(all->env);
		all->env = temp;
		temp = NULL;
	}
	else
		ft_apply(all, all->line, NULL);
	return (1);
}

char	*ft_delete_first_quote(char *str)
{
	int		i;
	char	*new;
	int		dq;
	int		q;
	int		j;

	ft_help_iniz(&i, &j, &q, &dq);
	new = ft_strnew(ft_strlen(str) + 1);
	while (str[i] != '\0')
	{
		if (str[i] == ' ' && q == 0 && dq == 0)
			break ;
		else if (str[i] == '"' && q == 0)
			dq = dq == 0 ? 2 : 0;
		else if (str[i] == '\'' && dq == 0)
			q = q == 0 ? 1 : 0;
		else
		{
			new[j] = str[i];
			j++;
		}
		i++;
	}
	ft_strcpy(new + j, str + i);
	return (new);
}

void	ft_help_iniz(int *i, int *j, int *q, int *dq)
{
	*dq = 0;
	*q = 0;
	*j = 0;
	*i = 0;
}
