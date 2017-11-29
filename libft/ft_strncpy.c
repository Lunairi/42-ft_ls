/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 12:06:55 by mlu               #+#    #+#             */
/*   Updated: 2017/06/05 12:08:33 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	unsigned int i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		if (src[i] == '\0')
			break ;
		i++;
	}
	i++;
	while (i < len)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
