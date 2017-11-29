/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 13:04:35 by mlu               #+#    #+#             */
/*   Updated: 2017/06/06 13:04:36 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;
	size_t	i;

	i = -1;
	s = (char *)src;
	d = (char *)dst;
	if (s < d)
		while ((int)(--len) >= 0)
			*(d + len) = *(s + len);
	else
		while (++i < len)
			*(d + i) = *(s + i);
	return (dst);
}
