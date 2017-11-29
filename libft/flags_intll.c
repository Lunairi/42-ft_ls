/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_intll.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/11/18 17:43:16 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Helps to process ll conversions
*/

void	flags_uhexll(va_list args, int *p)
{
	unsigned long long output;

	output = (unsigned long long)va_arg(args, void*);
	ft_putuhex((unsigned int)output, p);
}

void	flags_hexll(va_list args, int *p)
{
	unsigned long long output;

	output = (unsigned long long)va_arg(args, void*);
	ft_puthex((unsigned int)output, p);
}

void	flags_octll(va_list args, int *p)
{
	unsigned long long output;

	output = (unsigned long long)va_arg(args, void*);
	ft_putoct((unsigned int)output, p);
}

void	flags_uintll(va_list args, int *p)
{
	unsigned long long output;

	output = (unsigned long long)va_arg(args, void*);
	ft_putull((unsigned long long)output, p);
}

void	flags_intll(va_list args, int *p)
{
	long long output;

	output = (long long)va_arg(args, void*);
	ft_putnbrf((int)output, p);
}
