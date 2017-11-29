/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 13:04:52 by mlu               #+#    #+#             */
/*   Updated: 2017/06/06 13:04:53 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*m1;
	unsigned char	*m2;
	size_t			i;

	i = -1;
	m1 = (unsigned char *)s1;
	m2 = (unsigned char *)s2;
	while (++i < n && *(m1 + i) == *(m2 + i))
		;
	if (i == n)
		return (0);
	return (*(m1 + i) - *(m2 + i));
}
