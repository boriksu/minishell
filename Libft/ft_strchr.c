/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:09:02 by dholiday          #+#    #+#             */
/*   Updated: 2019/04/05 16:28:57 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char*)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char*)&s[i]);
	else
		return (NULL);
}
