/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2019/10/05 13:18:49 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		main(int argc, char **argv, char **env)
{
	t_env	all;
	char	*op;

	ft_hello_all(&all, env);
	while (1)
	{
		ft_putstr(ANSI_COLOR_YELLOW "[minishell] $> " ANSI_COLOR_RESET);
		if (get_next_line(0, &op) == 0)
			break ;
		if (ft_process_op(&all, op) < 0)
			break ;
		ft_strdel(&op);
	}
	ft_bye_all(&all);
	ft_strdel(&op);
	return (0);
}

int		ft_process_op(t_env *all, char *op)
{
	char	*new;
	int		i;
	int		k;

	k = 1;
	if (ft_only_space(op) == 0)
	{
		new = ft_quote(op);
		all->bonus = ft_find_point_comma(new);
		i = 0;
		while (all->bonus != NULL && all->bonus[i] != NULL)
		{
			if ((k = ft_process_b(all, all->bonus[i])) == -9)
				break ;
			i++;
		}
		ft_strdel(&new);
		ft_clean_mass(all->bonus);
		all->bonus = NULL;
	}
	return (k);
}

int		ft_process_b(t_env *all, char *str)
{
	if (ft_only_space(str) != 0)
		return (0);
	all->line = ft_delete_first_quote(str);
	if (ft_strncmp(all->line, "exit ", 5) == 0 ||
				ft_strcmp(all->line, "exit") == 0)
		return (-9);
	ft_iden(all);
	ft_strdel(&all->line);
	return (1);
}

void	ft_bye_all(t_env *all)
{
	ft_clean_mass(all->env);
	ft_clean_mass(all->path);
	all->env = NULL;
	all->path = NULL;
	ft_strdel(&all->line);
	ft_strdel(&all->oldpwd);
	ft_strdel(&all->pwd);
	ft_strdel(&all->home);
}

int		ft_size_mass(char **mass)
{
	int i;

	i = 0;
	if (mass != NULL)
		while (mass[i] != NULL)
			i++;
	return (i);
}
