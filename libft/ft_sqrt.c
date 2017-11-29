/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 12:07:17 by mlu               #+#    #+#             */
/*   Updated: 2017/04/08 12:09:51 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_power_calc(int nb)
{
	return (nb * nb);
}

int			ft_sqrt(int nb)
{
	int i;

	i = 0;
	if (nb < 0)
		return (0);
	while (ft_power_calc(i) <= nb)
	{
		if (ft_power_calc(i) == nb)
			return (i);
		i++;
	}
	return (0);
}
