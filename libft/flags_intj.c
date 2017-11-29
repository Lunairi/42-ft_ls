/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_intj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/11/18 17:43:16 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Helps to handle j conversions
*/

void	flags_uhexj(va_list args, int *p)
{
	uintmax_t output;

	output = (uintmax_t)va_arg(args, void*);
	ft_putuhex((unsigned int)output, p);
}

void	flags_hexj(va_list args, int *p)
{
	uintmax_t output;

	output = (uintmax_t)va_arg(args, void*);
	ft_puthex((unsigned int)output, p);
}

void	flags_octj(va_list args, int *p)
{
	uintmax_t output;

	output = (uintmax_t)va_arg(args, void*);
	ft_putoct((unsigned int)output, p);
}

void	flags_uintj(va_list args, int *p)
{
	uintmax_t output;

	output = (uintmax_t)va_arg(args, void*);
	ft_putull((unsigned long long)output, p);
}

void	flags_intj(va_list args, int *p)
{
	intmax_t output;

	output = (intmax_t)va_arg(args, void*);
	ft_putnbrf((int)output, p);
}
