/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_adr.c                                        :+:      :+:    :+:   */
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
** %p outputs in flags_adr
** %% outputs in flags_per
** libft functions: ft_puthex
*/

void	flags_adr(va_list args, int *p)
{
	void			*output;
	unsigned long	address;

	output = va_arg(args, void*);
	address = (unsigned long)(output);
	write(1, "0x", 2);
	*p = *p + 2;
	ft_putadr(address, p);
}

void	flags_per(int *p)
{
	*p = *p + 1;
	write(1, "%", 1);
}
