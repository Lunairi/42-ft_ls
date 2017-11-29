/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 13:48:43 by mlu               #+#    #+#             */
/*   Updated: 2017/04/11 17:32:29 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putadr(unsigned long n, int *p)
{
	if (n > 15)
	{
		ft_putadr((n / 16), p);
		ft_putadr((n % 16), p);
	}
	else if (n < 10)
	{
		*p = *p + 1;
		ft_putchar(n + '0');
	}
	else
	{
		*p = *p + 1;
		n == 10 ? ft_putchar('a') : 0;
		n == 11 ? ft_putchar('b') : 0;
		n == 12 ? ft_putchar('c') : 0;
		n == 13 ? ft_putchar('d') : 0;
		n == 14 ? ft_putchar('e') : 0;
		n == 15 ? ft_putchar('f') : 0;
	}
}
