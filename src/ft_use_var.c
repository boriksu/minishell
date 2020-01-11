/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_use_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2019/09/30 17:21:30 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	*ft_use_var(t_env *all, char *str)
{
	char	*op;
	char	*new;
	int		i;
	int		l;

	i = ft_strlen(str);
	op = ft_strnew(i);
	op = ft_strcpy(op, str + 1);
	if ((l = ft_check_var(all, op)) >= 0)
	{
		ft_strdel(&op);
		new = ft_strdup(all->env[l] + i);
	}
	else
	{
		ft_strdel(&op);
		return (NULL);
	}
	return (new);
}
