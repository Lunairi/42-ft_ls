/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_inthh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/11/18 17:43:16 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Flags address
** Helps to handle hh conversions
*/

void	flags_uhexhh(va_list args, int *p)
{
	unsigned char output;

	output = (unsigned char)va_arg(args, void*);
	ft_putuhex((unsigned int)output, p);
}

void	flags_hexhh(va_list args, int *p)
{
	unsigned char output;

	output = (unsigned char)va_arg(args, void*);
	ft_puthex((unsigned int)output, p);
}

void	flags_octhh(va_list args, int *p)
{
	unsigned char output;

	output = (unsigned char)va_arg(args, void*);
	ft_putoct((unsigned int)output, p);
}

void	flags_uinthh(va_list args, int *p)
{
	unsigned char output;

	output = (unsigned char)va_arg(args, void*);
	ft_putunbr((unsigned int)output, p);
}

void	flags_inthh(va_list args, int *p)
{
	short output;

	output = (char)va_arg(args, void*);
	ft_putnbrf((int)output, p);
}
