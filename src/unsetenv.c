/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2019/10/01 12:53:42 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	**ft_unsetenv(t_env *all)
{
	char	**new;
	int		i;
	int		k;
	int		j;

	k = ft_change_path(all);
	i = ft_size_mass(all->env);
	if (i - k <= 0)
		return (NULL);
	new = (char **)malloc(sizeof(char*) * (i - k + 1));
	j = 0;
	i = 0;
	while (all->env[i] != NULL)
	{
		if (all->env[i][0] != '\0')
		{
			new[j] = ft_strdup(all->env[i]);
			j++;
		}
		i++;
	}
	new[j] = NULL;
	return (new);
}

int		ft_change_path(t_env *all)
{
	char	**temp;
	int		i;
	int		k;
	int		line;

	i = 1;
	k = 0;
	temp = ft_splitwhitespaces(all->line);
	while (temp[i] != NULL)
	{
		if (ft_strcmp(temp[i], "PATH") == 0)
		{
			ft_clean_mass(all->path);
			all->path = NULL;
		}
		if ((line = ft_check_var(all, temp[i])) != -1)
		{
			all->env[line][0] = '\0';
			k++;
		}
		i++;
	}
	ft_clean_mass(temp);
	return (k);
}
