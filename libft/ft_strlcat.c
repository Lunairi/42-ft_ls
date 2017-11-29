/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 12:06:55 by mlu               #+#    #+#             */
/*   Updated: 2017/06/05 12:08:33 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dest;
	const char	*str;
	size_t		i;
	size_t		len;

	dest = dst;
	str = src;
	i = size;
	while (i-- != 0 && *dest != '\0')
		dest++;
	len = dest - dst;
	i = size - len;
	if (i == 0)
		return (len + ft_strlen(str));
	while (*str != '\0')
	{
		if (i != 1)
		{
			*dest++ = *str;
			i--;
		}
		str++;
	}
	*dest = '\0';
	return (len + (str - src));
}
