/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:08:05 by dholiday          #+#    #+#             */
/*   Updated: 2019/05/22 17:58:46 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	sy;
	unsigned char	*str;

	sy = c;
	str = b;
	i = 0;
	while (i < (int)len)
	{
		str[i] = sy;
		i++;
	}
	return (b);
}
