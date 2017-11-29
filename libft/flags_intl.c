/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_intl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/11/18 17:43:16 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Helps to handle l conversions
*/

void	flags_uhexl(va_list args, int *p)
{
	unsigned long output;

	output = (unsigned long)va_arg(args, void*);
	ft_putuhex((unsigned int)output, p);
}

void	flags_hexl(va_list args, int *p)
{
	unsigned long output;

	output = (unsigned long)va_arg(args, void*);
	ft_puthex((unsigned int)output, p);
}

void	flags_octl(va_list args, int *p)
{
	unsigned long output;

	output = (unsigned long)va_arg(args, void*);
	ft_putoct((unsigned int)output, p);
}

void	flags_uintl(va_list args, int *p)
{
	unsigned long output;

	output = (unsigned long)va_arg(args, void*);
	ft_putull((unsigned long long)output, p);
}

void	flags_intl(va_list args, int *p)
{
	long output;

	output = (long)va_arg(args, void*);
	ft_putld((long)output, p);
}
