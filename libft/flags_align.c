/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_align.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/11/18 17:43:16 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Handles width field
*/

int		g_align;

void	ft_putspace(int s, int size, int *p)
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

void	flag_raligna(const char *str, void *check, int *i, int *p)
{
	unsigned long	address;

	if (str[*i] == 'c' || str[*i] == '%')
	{
		ft_putspace(g_align, 1, p);
		*p = *p + 1;
		if (str[*i] == 'c')
			ft_putchar((char)check);
		else
			write(1, "%", 1);
	}
	else if (str[*i] == 'p')
	{
		ft_putspace(g_align, 14, p);
		address = (unsigned long)(check);
		write(1, "0x7ff", 5);
		*p = *p + 5;
		ft_putadr(address, p);
	}
}

void	flag_ralign(const char *str, va_list args, int *i, int *p)
{
	void			*check;

	check = va_arg(args, void*);
	if (str[*i] == 'd' || str[*i] == 'i')
	{
		ft_putspace(g_align, ft_numlen((int)check), p);
		ft_putnbrf((int)check, p);
	}
	else if (str[*i] == 'u' || str[*i] == 'o'
		|| str[*i] == 'x' || str[*i] == 'X')
	{
		ft_putspace(g_align, ft_numulen((unsigned int)check), p);
		ft_putnbrf((unsigned int)check, p);
	}
	else if (str[*i] == 's')
	{
		ft_putspace(g_align, ft_strlen((char*)check), p);
		ft_putstrf((char*)check, p);
	}
	else
		flag_raligna(str, check, i, p);
}

void	parse_rightalign(int *i, const char *str, va_list args, int *p)
{
	int count;

	count = *p;
	g_align = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		if (str[*i] >= '0' && str[*i] <= '9')
			g_align = g_align * 10 + (str[*i] - '0');
		*i = *i + 1;
	}
	flag_ralign(str, args, i, p);
}

void	parse_leftalign(int *i, const char *str, va_list args, int *p)
{
	int count;
	int check;

	count = *p;
	g_align = 0;
	check = 0;
	*i = *i + 1;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		g_align = g_align * 10 + (str[*i] - '0');
		*i = *i + 1;
	}
	*i = *i - 1;
	parse_flags(i, str, args, p);
	if (g_align > (*p - count))
	{
		check = g_align - (*p - count);
		while (--check >= 0)
		{
			write(1, " ", 1);
			*p = *p + 1;
		}
	}
}
