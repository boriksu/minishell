/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 20:25:26 by dholiday          #+#    #+#             */
/*   Updated: 2019/04/25 13:21:58 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strdup(const char *src)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (src[i] != '\0')
		i++;
	str = (char*)malloc(i + 1);
	if (!(str))
		return (0);
	j = 0;
	while (j < i)
	{
		str[j] = src[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
