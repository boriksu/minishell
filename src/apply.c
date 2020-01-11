/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2019/10/04 17:34:24 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_apply(t_env *all, char *line, char **mass1)
{
	char	**mass;
	char	*temp;

	mass = mass1 != NULL ? mass1 : ft_splitwhitespaces(line);
	if (ft_process_mass(all, mass, mass1) == 1)
		return ;
	if (access(mass[0], F_OK) != -1)
		ft_check_directly(all, mass);
	else if (all->path != NULL)
		ft_check_via_path(all, mass);
	else
		ft_print_output("[minishell]: command not found: ", mass[0]);
	if (mass1 == NULL)
		ft_clean_mass(mass);
}

int		ft_process_mass(t_env *all, char **mass, char **mass1)
{
	char *temp;

	if (mass[0][0] == '$' && mass[0][1] != '\0')
	{
		if ((temp = ft_use_var(all, mass[0])) == NULL)
		{
			if (mass1 == NULL)
				ft_clean_mass(mass);
			return (1);
		}
		else
		{
			ft_strdel(&mass[0]);
			mass[0] = temp;
		}
	}
	return (0);
}

void	ft_check_directly(t_env *all, char **mass)
{
	struct stat	buf;
	char		*strr;
	pid_t		f_s;

	stat(mass[0], &buf);
	strr = ft_conv_octal(buf.st_mode);
	if (ft_atoi(strr) / 10000 != 10)
		ft_print_output("[minishell]: permission denied: ", mass[0]);
	else if (access(mass[0], X_OK) == -1)
		ft_print_output("[minishell]: permission denied: ", mass[0]);
	else
		ft_fork_exec(all, mass[0], mass);
	ft_strdel(&strr);
}

void	ft_check_via_path(t_env *all, char **mass)
{
	int		i;
	char	*path;
	char	*path1;

	i = 0;
	while (all->path[i] != NULL)
	{
		path = ft_strjoin(all->path[i], "/");
		path1 = ft_strjoin(path, mass[0]);
		ft_strdel(&path);
		if (access(path1, F_OK) != -1)
		{
			if (access(path1, X_OK) != -1)
				ft_fork_exec(all, path1, mass);
			else
				ft_print_output("[minishell]: permission denied: ", mass[0]);
			ft_strdel(&path1);
			return ;
		}
		ft_strdel(&path1);
		i++;
	}
	ft_print_output("[minishell]: command not found: ", mass[0]);
}

void	ft_fork_exec(t_env *all, char *str, char **mass)
{
	pid_t	f_s;

	f_s = fork();
	if (f_s == 0)
		execve(str, mass, all->env);
	wait(&f_s);
}
