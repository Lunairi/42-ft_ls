/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 11:57:20 by mlu               #+#    #+#             */
/*   Updated: 2017/06/05 12:06:34 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strdup(const char *s1)
{
	size_t		size;
	size_t		i;
	char		*newstr;

	size = ft_strlen(s1);
	newstr = (char*)malloc(size + 1);
	if (!newstr)
		return (0);
	i = -1;
	while (++i < size)
		newstr[i] = *(s1 + i);
	newstr[size] = '\0';
	return (newstr);
}
