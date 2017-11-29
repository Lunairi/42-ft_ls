/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/11/18 17:43:16 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Flags String Of Characters
** %s outputs in flags_str
** %c outputs in flags_char
** Also handles wchars
** libft functions: ft_putchar, ft_putstr
*/

void	flags_char(va_list args, int *p)
{
	char output;

	output = (char)va_arg(args, int);
	*p = *p + 1;
	ft_putchar(output);
}

void	flags_str(va_list args, int *p)
{
	char *output;

	output = va_arg(args, char*);
	if (output != NULL)
		ft_putstrf(output, p);
	else
	{
		*p = *p + 6;
		write(1, "(null)", 6);
	}
}

void	flags_wchar(va_list args, int *p, const char *str, int *i)
{
	void	*output;

	if (str[*i] == 'C' || str[*i + 1] == 'c')
	{
		if (str[*i] == 'l')
			*i = *i + 1;
		output = va_arg(args, void*);
		*p = *p + 1;
		ft_putchar((char)output);
	}
	else if (str[*i] == 'S' || str[*i + 1] == 's')
	{
		if (str[*i] == 'l')
			*i = *i + 1;
		output = va_arg(args, wchar_t*);
		if (output != NULL)
			ft_putwstrf(output, p);
	}
}
