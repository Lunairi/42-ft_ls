/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/11/18 17:43:16 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Completed: s d i o u x c X %% p + space # h hh ll l
** In Progress: precision 0 j z
*/

/*
** This function is using ternary to help parse the current char that
** was passed from the printf function previously so the flag/modifier
** can be performed in the respective flags_ function
*/

void	parse_hh(va_list args, int *p, const char *str, int *i)
{
	*i = *i + 2;
	str[*i] == 'd' ? flags_inthh(args, p) : 0;
	str[*i] == 'i' ? flags_inthh(args, p) : 0;
	str[*i] == 'u' ? flags_uinthh(args, p) : 0;
	str[*i] == 'o' ? flags_octhh(args, p) : 0;
	str[*i] == 'x' ? flags_hexhh(args, p) : 0;
	str[*i] == 'X' ? flags_uhexhh(args, p) : 0;
}

void	parse_h(va_list args, int *p, const char *str, int *i)
{
	*i = *i + 1;
	str[*i] == 'd' ? flags_inth(args, p) : 0;
	str[*i] == 'i' ? flags_inth(args, p) : 0;
	str[*i] == 'u' ? flags_uinth(args, p) : 0;
	str[*i] == 'o' ? flags_octh(args, p) : 0;
	str[*i] == 'x' ? flags_hexh(args, p) : 0;
	str[*i] == 'X' ? flags_uhexh(args, p) : 0;
}

void	parse_flagsc(int *i, const char *str, va_list args, int *p)
{
	str[*i] == 'j' ? parse_j(args, p, str, i) : 0;
	str[*i] == 'z' ? parse_z(args, p, str, i) : 0;
	str[*i] == 'O' ? parse_l(args, p, str, i) : 0;
	str[*i] == '#' ? flags_hash(args, p, str, i) : 0;
	str[*i] == '0' ? parse_zero(i, str, args, p) : 0;
	str[*i] > '0' && str[*i] <= '9' ? parse_rightalign(i, str, args, p) : 0;
	str[*i] == '-' ? parse_leftalign(i, str, args, p) : 0;
	str[*i] == ' ' ? flags_ws(args, p, str, i) : 0;
	str[*i] == '+' ? flags_plus(args, p, str, i) : 0;
}

void	parse_flags(int *i, const char *str, va_list args, int *p)
{
	*i = *i + 1;
	str[*i] == 'd' ? flags_int(args, p) : 0;
	str[*i] == 'i' ? flags_int(args, p) : 0;
	str[*i] == 'u' ? flags_uint(args, p) : 0;
	str[*i] == 'o' ? flags_oct(args, p) : 0;
	str[*i] == 's' ? flags_str(args, p) : 0;
	str[*i] == 'x' ? flags_hex(args, p) : 0;
	str[*i] == 'X' ? flags_uhex(args, p) : 0;
	str[*i] == 'c' ? flags_char(args, p) : 0;
	str[*i] == 'p' ? flags_adr(args, p) : 0;
	str[*i] == '%' ? flags_per(p) : 0;
	str[*i] == 'C' || str[*i] == 'S' ? flags_wchar(args, p, str, i) : 0;
	str[*i] == 'l' && str[*i + 1] == 's' ? flags_wchar(args, p, str, i) : 0;
	str[*i] == 'l' && str[*i + 1] == 'c' ? flags_wchar(args, p, str, i) : 0;
	str[*i] == 'h' && str[*i + 1] == 'h' ? parse_hh(args, p, str, i) : 0;
	str[*i] == 'h' && str[*i + 1] != 'h' ? parse_h(args, p, str, i) : 0;
	str[*i] == 'l' && str[*i + 1] == 'l' ? parse_ll(args, p, str, i) : 0;
	str[*i] == 'l' && str[*i + 1] != 'l' ? parse_l(args, p, str, i) : 0;
	str[*i] == 'D' || str[*i + 1] == 'U' ? parse_l(args, p, str, i) : 0;
	parse_flagsc(i, str, args, p);
}
