/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2019/10/04 20:35:28 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_echo_init(t_echo_f *echo)
{
	echo->dash = 0;
	echo->e = 0;
	echo->ee = 0;
	echo->n = 0;
}

void	ft_echo(t_env *all)
{
	int			i;
	t_echo_f	echo;

	i = 0;
	if (all->line[4] == '\0')
		ft_putchar('\n');
	else
	{
		ft_echo_init(&echo);
		ft_echo_str(all, &echo, all->line + 4);
	}
}

void	ft_echo_str(t_env *all, t_echo_f *echo, char *str)
{
	int i;
	int ans;
	int flag;

	flag = 1;
	i = 0;
	if (str[0] != ' ')
		ft_apply(all, all->line, NULL);
	else
	{
		ft_bye_space(str, &i);
		if ((flag = ft_find_flag(all, echo, str + i)) == 0)
			ft_print_without(all, echo, str + i);
	}
}

int		ft_find_flag(t_env *all, t_echo_f *echo, char *str)
{
	char	*ch;
	int		i;
	int		k;

	ch = str;
	i = 0;
	if (str[0] != '-')
		return (0);
	else
		while (str[i] != '\0')
		{
			if ((k = ft_search_f(echo, str[i])) == 1)
				i++;
			else if (k == 3)
			{
				if (ft_find_flag_help(echo, &str, &ch, &i) == 0)
					break ;
			}
			else if (k == 0)
				break ;
		}
	if (str[i] == '\0')
		return (ft_printf("\n"));
	return (ft_print_without(all, echo, ch));
}

int		ft_find_flag_help(t_echo_f *echo, char **str, char **ch, int *i)
{
	if (*str[*i - 1] == '-')
	{
		ft_bye_space(*str, i);
		*ch = *str + *i;
		return (0);
	}
	else
	{
		ft_bye_space(*str, i);
		echo->dash = 0;
		*ch = *str + *i;
	}
	return (1);
}
