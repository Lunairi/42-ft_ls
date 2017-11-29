/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 13:04:43 by mlu               #+#    #+#             */
/*   Updated: 2017/06/06 13:04:44 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*arg;
	size_t		i;

	arg = (const char *)s;
	i = -1;
	while (++i < n)
		if (*(arg + i) == (char)c)
			return ((void *)arg + i);
	return (NULL);
}
