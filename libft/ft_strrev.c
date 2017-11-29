/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 12:49:42 by mlu               #+#    #+#             */
/*   Updated: 2017/04/07 13:01:56 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlength(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

char		*ft_strrev(char *str)
{
	int		length;
	int		i;
	char	temp;

	length = (ft_strlength(str) - 1);
	i = 0;
	while (i <= length / 2)
	{
		temp = str[i];
		str[i] = str[length - i];
		str[length - 1] = temp;
		i++;
	}
	return (str);
}
