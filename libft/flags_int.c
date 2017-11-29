/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/11/18 17:43:16 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Flags Signed Decimal Integers
** %d and %i outputs in flags_int
** %o outputs in flags_oct
** %u outputs in flags_uint
** %x outputs in flags_hex
** libft functions: ft_puthex, ft_putoct, ft_putunbr, ft_putnbr
*/

void	flags_uhex(va_list args, int *p)
{
	unsigned int output;

	output = va_arg(args, unsigned int);
	ft_putuhex(output, p);
}

void	flags_hex(va_list args, int *p)
{
	unsigned int output;

	output = va_arg(args, unsigned int);
	ft_puthex(output, p);
}

void	flags_oct(va_list args, int *p)
{
	unsigned int output;

	output = va_arg(args, unsigned int);
	ft_putoct(output, p);
}

void	flags_uint(va_list args, int *p)
{
	unsigned int output;

	output = va_arg(args, unsigned int);
	ft_putunbr(output, p);
}

void	flags_int(va_list args, int *p)
{
	int output;

	output = va_arg(args, int);
	ft_putnbrf(output, p);
}
