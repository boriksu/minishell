/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_for_echo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2019/10/04 20:35:59 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		ft_print_without(t_env *all, t_echo_f *echo, char *str1)
{
	int i;
	int space;
	int dq;
	int q;
	int k;

	ft_help_iniz(&i, &space, &dq, &q);
	while (str1[i] != '\0')
	{
		if ((k = ft_dollar_tilda(all, str1, &i, &space) == 0))
			continue ;
		else if (k == 1)
			return (1);
		else if (ft_print_quote(str1[i], &q, &dq) == 1 && i++)
			continue ;
		else if (str1[i] == '\\' && str1[i + 1] == '"')
			i++;
		else if (ft_check_space(str1[i], q + dq, &space) == 1 && i++)
			continue ;
		ft_putchar(str1[i]);
		i++;
	}
	ft_putchar('\n');
	return (1);
}

int		ft_dollar_tilda(t_env *all, char *str1, int *i, int *space)
{
	if (str1[*i] == '$')
	{
		ft_print_var(all, str1, i);
		*space = 0;
		return (0);
	}
	else if (str1[*i] == '~')
	{
		ft_print_tilda(all, str1, i);
		if (str1[*i] == '\0')
			return (1);
		else
			return (0);
	}
	return (2);
}

void	ft_print_tilda(t_env *all, char *str, int *i)
{
	if (str[*i + 1] == ' ' || str[*i + 1] == '/' || str[*i + 1] == '\0')
	{
		ft_putstr(all->home);
		*i = *i + 1;
	}
	else if (str[*i + 1] == '~')
		while (str[*i] == '~')
		{
			ft_putchar(str[*i]);
			*i = *i + 1;
		}
	else
	{
		ft_print_error("[minishell]: no such user or named directory: ");
		*i = *i + 1;
		while (str[*i] != ' ' && str[*i] != '\0')
		{
			ft_put_error(str[*i]);
			*i = *i + 1;
		}
		while (str[*i] != '\0')
			*i = *i + 1;
		ft_put_error('\n');
	}
}

int		ft_print_quote(char str1, int *q, int *dq)
{
	if (str1 == '"' && *q == 0)
	{
		*dq = *dq == 0 ? 2 : 0;
		return (1);
	}
	else if (str1 == '\'' && *dq == 0)
	{
		*q = *q == 0 ? 1 : 0;
		return (1);
	}
	return (0);
}

int		ft_check_space(char str1, int qdq, int *space)
{
	if ((str1 == ' ' || (str1 >= 9 && str1 <= 13)) && qdq == 0 && *space == 1)
		return (1);
	else if ((str1 == ' ' || (str1 >= 9 && str1 <= 13))
								&& qdq == 0 && *space == 0)
		*space = 1;
	else
		*space = 0;
	return (0);
}
