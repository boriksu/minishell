/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2019/10/04 20:36:18 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_print_mass(char **mass)
{
	int i;

	i = 0;
	if (mass != NULL)
	{
		while (mass[i] != NULL)
		{
			ft_putendl(mass[i]);
			i++;
		}
	}
}

void	ft_print_not_command(char *str)
{
	int i;
	int ans;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i] != '\0' && str[i] != ' ')
	{
		ft_put_error(str[i]);
		i++;
	}
	ft_put_error('\n');
}

void	ft_print_error(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_put_error(str[i]);
		i++;
	}
}

void	ft_put_error(char c)
{
	write(2, &c, 1);
}

void	ft_print_var(t_env *all, char *str, int *i)
{
	int		st;
	char	*op;
	int		l;

	*i = *i + 1;
	st = *i;
	if (str[*i] == '$')
	{
		ft_printf("%d", getpid());
		*i = *i + 1;
		return ;
	}
	while (str[*i] != ' ' && str[*i] != '\0' && str[*i] != '$' &&
								str[*i] != '"' && str[*i] != '\'')
		*i = *i + 1;
	if (*i - st == 0)
		ft_putchar(str[st - 1]);
	else
	{
		op = ft_strnew(*i - st + 1);
		op = ft_strncpy(op, str + st, *i - st);
		if ((l = ft_check_var(all, op)) >= 0)
			ft_putstr(all->env[l] + ft_strlen(op) + 1);
		ft_strdel(&op);
	}
}
