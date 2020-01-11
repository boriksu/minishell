/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2019/09/30 17:21:06 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_env(t_env *all)
{
	int i;

	i = 0;
	if (all->line[3] != '\0' && all->line[3] != ' ')
		ft_apply(all, all->line, NULL);
	else
		ft_env_opt(all);
}

void	ft_env_opt(t_env *all)
{
	char	**mass;
	int		i;

	mass = ft_splitwhitespaces(all->line);
	i = ft_size_mass(mass);
	if (i == 1)
		ft_print_mass(all->env);
	else
	{
		if (ft_strchr(all->line, '=') == NULL)
			ft_apply(all, all->line + 3, NULL);
		else
		{
			all->old_env = ft_copy_env(all->env);
			ft_env_analyze(all, mass);
			ft_refresh_env(all);
		}
	}
	ft_clean_mass(mass);
}

void	ft_env_analyze(t_env *all, char **mass)
{
	int		i;
	char	*t;
	char	*new_join;
	char	**temp;

	i = 1;
	while (mass[i] != NULL && (t = ft_strchr(mass[i], '=')) != NULL)
	{
		if (ft_strcmp(mass[i], "=") == 0)
		{
			ft_print_error("[minishell]: env: =: Invalid argument.\n");
			ft_refresh_env(all);
			return ;
		}
		t[0] = ' ';
		new_join = ft_strjoin("setenv ", mass[i]);
		temp = ft_setenv(all, new_join);
		ft_strdel(&new_join);
		i++;
		if (temp == NULL)
			continue ;
		ft_clean_mass(all->env);
		all->env = temp;
	}
	mass[i] == NULL ? ft_print_mass(all->env) : ft_apply(all, NULL, mass + i);
}

void	ft_refresh_env(t_env *all)
{
	ft_clean_mass(all->env);
	all->env = all->old_env;
	ft_clean_mass(all->path);
	all->path = ft_path(all->env);
	all->old_env = NULL;
}
