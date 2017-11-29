/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 13:20:27 by mlu               #+#    #+#             */
/*   Updated: 2017/06/05 13:20:31 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_length(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char		*ft_strcat(char *dest, const char *src)
{
	int length;
	int i;

	i = 0;
	length = find_length(dest);
	while (src[i] != '\0')
	{
		dest[i + length] = src[i];
		i++;
	}
	dest[i + length] = '\0';
	return (dest);
}
