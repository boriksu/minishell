/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:19:26 by dholiday          #+#    #+#             */
/*   Updated: 2019/04/05 18:03:37 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		a = s1[i];
		b = s2[i];
		if (a != b)
			return (a - b);
		else
			i++;
	}
	return (0);
}
