/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlavallo <rlavallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:28:52 by rlavallo          #+#    #+#             */
/*   Updated: 2014/11/11 18:00:16 by rlavallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strcat(char *dest, const char *src)
{
	char	*s;
	int		i;
	int		j;

	if (dest != NULL && src != NULL)
	{
		i = 0;
		s = dest;
		while (s[i] != '\0')
			i++;
		j = 0;
		while (src[j] != '\0')
		{
			s[i] = src[j];
			i++, j++;
		}
		s[i] = '\0';
		return (s);
	}
	return (NULL);
}
