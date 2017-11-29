/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 13:28:11 by mlu               #+#    #+#             */
/*   Updated: 2017/04/11 13:34:34 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlength(const char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char		*ft_strstr(const char *big, const char *little)
{
	int x;
	int y;
	int string;
	int find;

	x = 0;
	string = ft_strlength(big);
	find = ft_strlength(little);
	if (find == 0)
		return ((char*)big);
	while (x < string - find + 1)
	{
		y = 0;
		while (y < find)
		{
			if (big[x + y] != little[y])
				break ;
			if (y == find - 1)
				return ((char*)big + x);
			y++;
		}
		x++;
	}
	return (0);
}
