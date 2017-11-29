/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/11/18 17:43:16 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Handles zero modifier
*/

int		g_alignz;

void	ft_putspacez(int s, int size, int *p)
{
	int count;

	count = 0;
	if (s > size)
	{
		count = s - size;
		while (--count >= 0)
		{
			write(1, "0", 1);
			*p = *p + 1;
		}
	}
}

void	flag_ralignz(const char *str, va_list args, int *i, int *p)
{
	void			*check;

	check = va_arg(args, void*);
	if (str[*i] == 'd' || str[*i] == 'i')
	{
		ft_putspacez(g_alignz, ft_numlen((int)check), p);
		ft_putnbrf((int)check, p);
	}
}

void	parse_zero(int *i, const char *str, va_list args, int *p)
{
	int count;

	count = *p;
	g_alignz = 0;
	if (str[*i + 1] == '+')
	{
		*i = *i + 1;
		flags_plus(args, p, str, i);
	}
	else
	{
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			if (str[*i] >= '0' && str[*i] <= '9')
				g_alignz = g_alignz * 10 + (str[*i] - '0');
			*i = *i + 1;
		}
		flag_ralignz(str, args, i, p);
	}
}

void	flag_pralignz(const char *str, va_list args, int *i, int *p)
{
	void			*check;

	check = va_arg(args, void*);
	g_alignz = g_alignz - 1;
	if (str[*i] == 'd' || str[*i] == 'i')
	{
		ft_putspacez(g_alignz, ft_numlen((int)check), p);
		ft_putnbrf((int)check, p);
	}
}

void	parse_pzero(int *i, const char *str, va_list args, int *p)
{
	int count;

	count = *p;
	g_alignz = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		if (str[*i] >= '0' && str[*i] <= '9')
			g_alignz = g_alignz * 10 + (str[*i] - '0');
		*i = *i + 1;
	}
	flag_pralignz(str, args, i, p);
}
