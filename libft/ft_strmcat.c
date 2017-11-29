/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 12:06:55 by mlu               #+#    #+#             */
/*   Updated: 2017/06/05 12:08:33 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strmcat(char *s1, char *s2, unsigned int *size, unsigned int buf)
{
	unsigned int l;
	unsigned int i;

	i = 0;
	if (((*size) > buf) && ((*size) % buf == 0))
		if (s1[*size - buf])
			i = *size - buf;
	l = 0;
	while (s1[i])
		i++;
	while (s2[l] && (l < buf))
	{
		s1[i] = s2[l];
		i++;
		l++;
	}
	while (l-- > 0)
		s2[l] = '\0';
	s1[i] = '\0';
}
