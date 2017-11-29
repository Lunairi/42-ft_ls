/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_inth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/11/18 17:43:16 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Helps to handle h conversions
*/

void	flags_uhexh(va_list args, int *p)
{
	unsigned short output;

	output = (unsigned short)va_arg(args, void*);
	ft_putuhex((unsigned int)output, p);
}

void	flags_hexh(va_list args, int *p)
{
	unsigned short output;

	output = (unsigned short)va_arg(args, void*);
	ft_puthex((unsigned int)output, p);
}

void	flags_octh(va_list args, int *p)
{
	unsigned short output;

	output = (unsigned short)va_arg(args, void*);
	ft_putoct((unsigned int)output, p);
}

void	flags_uinth(va_list args, int *p)
{
	unsigned short output;

	output = (unsigned short)va_arg(args, void*);
	ft_putunbr((unsigned int)output, p);
}

void	flags_inth(va_list args, int *p)
{
	short output;

	output = (unsigned short)va_arg(args, void*);
	ft_putnbrf((int)output, p);
}
