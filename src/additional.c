/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2019/10/04 17:35:05 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	**ft_make_copy(char **env, int *j)
{
	char	**new;
	int		i;

	i = ft_size_mass(env);
	new = (char **)malloc(sizeof(char*) * (i + 2));
	while (*j < i)
	{
		new[*j] = ft_strdup(env[*j]);
		*j = *j + 1;
	}
	return (new);
}

int		ft_check_var(t_env *all, char *str)
{
	int i;

	i = 0;
	while (all->env[i] != NULL)
	{
		if (ft_strncmp(all->env[i], str, ft_strlen(str) + 1) == 61)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_print_output(char *str, char *str1)
{
	ft_print_error(str);
	ft_print_not_command(str1);
}

int		ft_search_f(t_echo_f *echo, char c)
{
	if (c == 'e' && echo->dash == 1)
		echo->e = 1;
	else if (c == 'E' && echo->dash == 1)
		echo->ee = 1;
	else if (c == 'n' && echo->dash == 1)
		echo->n = 1;
	else if (c == '-' && echo->dash == 0)
		echo->dash = 1;
	else if (c == ' ')
		return (3);
	else
		return (0);
	return (1);
}
