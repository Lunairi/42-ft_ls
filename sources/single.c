/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/11/28 17:43:16 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

// void	check_flags(char *str, t_flags *toggle)
// {
// 	int i;
// }

int		ls_single(char *str, t_flags *toggle)
{
	struct dirent	*d;
	DIR				*dir;
	char			**list;
	int				i;
	int				item;

	i = 0;
	if (!(item = item_amount(str))) // if return 0 it means directory couldn't open
		return (0);
	list = (char**)ft_memalloc(sizeof(char*) * item);
	dir = opendir(str);
	while ((d = readdir(dir)))
	{
		list[i] = d->d_name;
		i++;
	}
	sort_recursive(list, i, toggle);
	free(list);
	closedir(dir);
	return (0);
}

int		parse_single(char *flag, char *search)
{
	t_flags *toggle;

	if(flag[0] == '-')
	{
		if (flag[1] != 'r' && flag[1] != 'a' && flag[1] != '1' && flag[1] != 'l')	
		{
			ft_printf("ls: invalid option -- '%c'\n", flag[1]);
			ft_printf("Try 'ft_ls --help' for more information.\n");
			return (0);
		}
	}
	toggle = ft_memalloc(sizeof(t_flags));
	flag[0] == '-' && flag[1] == 'r' ? toggle->r = 1 : 0;
	flag[0] == '-' && flag[1] == 'a' ? toggle->a = 1 : 0;
	flag[0] == '-' && flag[1] == 'l' ? toggle->l = 1 : 0;
	ls_single(search, toggle);
	free(toggle);
	return (0);
}
