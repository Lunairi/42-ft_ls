/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_intz.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/11/18 17:43:16 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Helps to deal with z conversions
*/

void	flags_uhexz(va_list args, int *p)
{
	size_t output;

	output = (size_t)va_arg(args, void*);
	ft_putuhex((unsigned int)output, p);
}

void	flags_hexz(va_list args, int *p)
{
	size_t output;

	output = (size_t)va_arg(args, void*);
	ft_puthex((unsigned int)output, p);
}

void	flags_octz(va_list args, int *p)
{
	size_t output;

	output = (size_t)va_arg(args, void*);
	ft_putoct((unsigned int)output, p);
}

void	flags_uintz(va_list args, int *p)
{
	size_t output;

	output = (size_t)va_arg(args, void*);
	ft_putull((unsigned long long)output, p);
}

void	flags_intz(va_list args, int *p)
{
	ssize_t output;

	output = (ssize_t)va_arg(args, void*);
	ft_putnbrf((int)output, p);
}
