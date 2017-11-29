/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_spc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/11/18 17:43:16 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Handles whitespace, plus and hash
*/

void	flags_ws(va_list args, int *p, const char *str, int *i)
{
	int output;

	if (str[*i + 1] == 'd' || str[*i + 1] == 'i')
	{
		output = va_arg(args, int);
		if (output >= 0)
		{
			*p = *p + 1;
			write(1, " ", 1);
		}
		*i = *i + 1;
		ft_putnbrf(output, p);
	}
	else
		parse_flags(i, str, args, p);
}

void	norm_plus(int *p)
{
	*p = *p + 1;
	write(1, "+", 1);
}

void	flags_plus(va_list args, int *p, const char *str, int *i)
{
	int output;

	if (str[*i + 1] == 'd' || str[*i + 1] == 'i')
	{
		output = va_arg(args, int);
		if (output >= 0)
			norm_plus(p);
		*i = *i + 1;
		ft_putnbrf(output, p);
	}
	else if (str[*i + 1] == '0')
	{
		norm_plus(p);
		*i = *i + 1;
		parse_pzero(i, str, args, p);
	}
	else if (str[*i + 1] == '-')
		parse_leftpalign(i, str, args, p);
	else if (str[*i + 1] > '0' || str[*i + 1] <= '9')
		parse_rightpalign(i, str, args, p);
	else
		parse_flags(i, str, args, p);
}

void	flags_hash(va_list args, int *p, const char *str, int *i)
{
	unsigned int output;

	if (str[*i + 1] == 'o')
	{
		*i = *i + 1;
		output = va_arg(args, unsigned int);
		*p = *p + 1;
		write(1, "0", 1);
		if (output != 0)
			ft_putoct(output, p);
	}
	else if (str[*i + 1] == 'x')
	{
		*p = *p + 2;
		write(1, "0x", 2);
		parse_flags(i, str, args, p);
	}
	else if (str[*i + 1] == 'X')
	{
		*p = *p + 2;
		write(1, "0X", 2);
		parse_flags(i, str, args, p);
	}
}
