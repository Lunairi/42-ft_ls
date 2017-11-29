/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_palign.c                                     :+:      :+:    :+:   */
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

int		g_palign;

void	ft_putpspace(int s, int size, int *p)
{
	int count;

	count = 0;
	if (s > size)
	{
		count = s - size;
		while (--count >= 0)
		{
			write(1, " ", 1);
			*p = *p + 1;
		}
	}
}

void	flag_rpaligna(const char *str, void *check, int *i, int *p)
{
	unsigned long	address;

	if (str[*i] == 'c' || str[*i] == '%')
	{
		ft_putpspace(g_palign, 1, p);
		*p = *p + 1;
		if (str[*i] == 'c')
			ft_putchar((char)check);
		else
			write(1, "%", 1);
	}
	else if (str[*i] == 'p')
	{
		ft_putpspace(g_palign, 14, p);
		address = (unsigned long)(check);
		write(1, "0x7ff", 5);
		*p = *p + 5;
		ft_putadr(address, p);
	}
}

void	flag_rpalign(const char *str, va_list args, int *i, int *p)
{
	void			*check;

	check = va_arg(args, void*);
	if (str[*i] == 'd' || str[*i] == 'i')
	{
		ft_putpspace(g_palign, ft_numlen((int)check), p);
		ft_putnbrf((int)check, p);
	}
	else if (str[*i] == 'u' || str[*i] == 'o'
		|| str[*i] == 'x' || str[*i] == 'X')
	{
		ft_putpspace(g_palign, ft_numulen((unsigned int)check), p);
		ft_putnbrf((unsigned int)check, p);
	}
	else if (str[*i] == 's')
	{
		ft_putpspace(g_palign, ft_strlen((char*)check), p);
		ft_putstrf((char*)check, p);
	}
	else
		flag_rpaligna(str, check, i, p);
}

void	parse_rightpalign(int *i, const char *str, va_list args, int *p)
{
	int count;

	count = *p;
	g_palign = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		if (str[*i] >= '0' && str[*i] <= '9')
			g_palign = g_palign * 10 + (str[*i] - '0');
		*i = *i + 2;
	}
	flag_rpalign(str, args, i, p);
}

void	parse_leftpalign(int *i, const char *str, va_list args, int *p)
{
	int count;
	int check;

	count = *p + 1;
	g_palign = 0;
	check = 0;
	*i = *i + 1;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		g_palign = g_palign * 10 + (str[*i] - '0');
		*i = *i + 1;
	}
	*i = *i - 1;
	*p = *p + 1;
	write(1, "+", 1);
	parse_flags(i, str, args, p);
	if (g_palign > (*p - count))
	{
		check = g_palign - (*p - count);
		while (--check > 0)
		{
			write(1, " ", 1);
			*p = *p + 1;
		}
	}
}
