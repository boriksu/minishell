/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2019/09/30 13:32:04 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_hello_all(t_env *all, char **env)
{
	all->bonus = NULL;
	all->line = NULL;
	all->num = 0;
	all->pwd = NULL;
	all->home = NULL;
	all->oldpwd = NULL;
	all->old_env = NULL;
	all->env = ft_copy_env(env);
	all->path = ft_path(all->env);
	ft_home(all);
}

char	**ft_copy_env(char **env)
{
	int		i;
	char	**new;
	int		j;

	i = ft_size_mass(env);
	new = (char **)malloc(sizeof(char*) * (i + 1));
	j = 0;
	while (j < i)
	{
		new[j] = ft_strdup(env[j]);
		j++;
	}
	new[j] = NULL;
	return (new);
}

char	**ft_path(char **mass)
{
	int		i;
	char	**temp;

	i = 0;
	while (mass[i] != NULL)
	{
		if (ft_strncmp(mass[i], "PATH", 5) == 61)
			break ;
		i++;
	}
	if (mass[i] == NULL)
		return (NULL);
	temp = ft_strsplit(mass[i] + 5, ':');
	return (temp);
}

void	ft_home(t_env *all)
{
	int		i;
	int		pwd;
	int		home;

	i = 0;
	pwd = -1;
	home = -1;
	while (all->env[i] != NULL)
	{
		if (ft_strncmp(all->env[i], "PWD", 4) == 61)
			pwd = i;
		else if (ft_strncmp(all->env[i], "HOME", 5) == 61)
			home = i;
		i++;
	}
	all->pwd = pwd < 0 ? NULL : ft_strdup(all->env[pwd] + 4);
	all->oldpwd = pwd < 0 ? NULL : ft_strdup(all->env[pwd] + 4);
	all->home = home < 0 ? NULL : ft_strdup(all->env[home] + 5);
}
