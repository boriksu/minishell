/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2019/09/30 16:51:51 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_cd(t_env *all)
{
	int		i;
	char	**cd;
	char	*temp;

	cd = ft_splitwhitespaces(all->line);
	if (cd == NULL)
		ft_putstr("error_cd");
	i = ft_size_mass(cd);
	if (i > 2)
		ft_print_error("[minishell]: cd: Too many arguments.\n");
	else if (i == 1)
		ft_replace(all, all->home);
	else if (ft_strcmp(cd[1], "~") == 0)
		ft_replace(all, all->home);
	else if (ft_strcmp(cd[1], "--") == 0)
		ft_replace(all, all->home);
	else if (ft_strcmp(cd[1], "-") == 0)
	{
		temp = ft_strdup(all->oldpwd);
		ft_replace(all, temp);
		ft_strdel(&temp);
	}
	else
		ft_check_other_places(all, cd[1]);
	ft_clean_mass(cd);
}

void	ft_check_other_places(t_env *all, char *str)
{
	char	*place;
	char	*temp;
	DIR		*k;

	if (str[0] == '~' && str[1] != '~')
	{
		place = ft_strdup(all->home);
		temp = ft_strjoin(place, str + 1);
		ft_strdel(&place);
	}
	else
		temp = ft_strdup(str);
	if ((k = opendir(temp)) == NULL)
	{
		ft_print_error("[minishell]: cd: no such file or directory: ");
		ft_print_error(temp);
		ft_put_error('\n');
	}
	else
	{
		closedir(k);
		ft_replace(all, temp);
	}
	ft_strdel(&temp);
}

void	ft_replace(t_env *all, char *place)
{
	ft_strdel(&all->oldpwd);
	all->oldpwd = getcwd(all->oldpwd, 500);
	chdir(place);
	ft_strdel(&all->pwd);
	all->pwd = getcwd(all->pwd, 500);
	ft_replace_pwd(all);
}

void	ft_replace_pwd(t_env *all)
{
	int		i;
	char	*temp;

	i = ft_check_var(all, "OLDPWD");
	if (i != -1)
	{
		ft_strdel(&all->env[i]);
		temp = ft_strnew(8);
		temp = ft_strcpy(temp, "OLDPWD=");
		all->env[i] = ft_strjoin(temp, all->oldpwd);
		ft_strdel(&temp);
	}
	i = ft_check_var(all, "PWD");
	if (i != -1)
	{
		ft_strdel(&all->env[i]);
		temp = ft_strnew(5);
		temp = ft_strcpy(temp, "PWD=");
		all->env[i] = ft_strjoin(temp, all->pwd);
		ft_strdel(&temp);
	}
}
