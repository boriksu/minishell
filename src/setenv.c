/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2019/10/04 17:33:47 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	**ft_setenv_und(t_env *all, char *line)
{
	char	**mass;
	int		i;
	int		p;

	mass = ft_splitwhitespaces(line);
	i = 0;
	while (mass != NULL && mass[i] != NULL)
		i++;
	p = ft_valid_command_setenv(all, mass, i);
	if (p == 0)
	{
		ft_clean_mass(mass);
		return (NULL);
	}
	return (mass);
}

int		ft_valid_command_setenv(t_env *all, char **mass, int i)
{
	int k;

	if (mass[0][6] != '\0')
		ft_apply(all, NULL, mass);
	else if (i > 3)
		ft_print_error("[minishell]: setenv: Too many arguments.\n");
	else if (i > 1)
	{
		k = 0;
		while (mass[1][k] != '\0')
			if (mass[1][k] == '_' || ft_isalnum(mass[1][k]) == 1)
				k++;
			else
			{
				ft_print_error("[minishell]: setenv: Variable name must ");
				ft_print_error("contain alphanumeric characters.\n");
				return (0);
			}
		return (1);
	}
	else
		return (1);
	return (0);
}

void	ft_change_var(t_env *all, char **temp, int i)
{
	char	*new;
	char	*help;

	new = ft_strdup(temp[1]);
	help = ft_strjoin(new, "=");
	ft_strdel(&new);
	new = ft_strjoin(help, temp[2]);
	ft_strdel(&help);
	ft_strdel(&all->env[i]);
	all->env[i] = new;
	if (ft_strcmp(temp[1], "PATH") == 0)
	{
		ft_clean_mass(all->path);
		all->path = ft_path(all->env);
	}
}

char	**ft_setenv(t_env *all, char *line)
{
	char	**new;
	char	**temp;
	int		j;

	temp = ft_setenv_und(all, line);
	if (temp[1] == NULL)
	{
		ft_print_mass(all->env);
		return (NULL);
	}
	if ((j = ft_check_var(all, temp[1])) >= 0)
	{
		ft_change_var(all, temp, j);
		ft_clean_mass(temp);
		return (NULL);
	}
	j = 0;
	new = ft_make_copy(all->env, &j);
	new[j] = ft_add_new_env(all, temp);
	new[++j] = NULL;
	ft_clean_mass(temp);
	temp = NULL;
	ft_clean_mass(all->path);
	all->path = ft_path(new);
	return (new);
}

char	*ft_add_new_env(t_env *all, char **temp)
{
	char	*new;
	char	*help;

	new = ft_strdup(temp[1]);
	help = ft_strjoin(new, "=");
	ft_strdel(&new);
	if (temp[2] != NULL)
	{
		new = ft_strjoin(help, temp[2]);
		ft_strdel(&help);
		return (new);
	}
	return (help);
}
