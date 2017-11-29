/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 12:46:51 by mlu               #+#    #+#             */
/*   Updated: 2017/06/06 12:46:52 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putuhex(unsigned int n, int *p)
{
	if (n > 15)
	{
		ft_putuhex((n / 16), p);
		ft_putuhex((n % 16), p);
	}
	else if (n < 10)
	{
		*p = *p + 1;
		ft_putchar(n + '0');
	}
	else
	{
		*p = *p + 1;
		n == 10 ? ft_putchar('A') : 0;
		n == 11 ? ft_putchar('B') : 0;
		n == 12 ? ft_putchar('C') : 0;
		n == 13 ? ft_putchar('D') : 0;
		n == 14 ? ft_putchar('E') : 0;
		n == 15 ? ft_putchar('F') : 0;
	}
}
