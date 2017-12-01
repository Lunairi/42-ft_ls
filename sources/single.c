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
	if (toggle->t == 1)
		time_sort_recursive(list, i, toggle, str);
	else
		sort_recursive(list, i, toggle, str);
	free(list);
	closedir(dir);
	return (0);
}

int		parse_single(char *flag, char *search)
{
	t_flags *toggle;

	toggle = ft_memalloc(sizeof(t_flags));
	if(flag[0] == '-')
		if (check_flags(flag, toggle))
			return (0);
	ls_single(search, toggle);
	free(toggle);
	return (0);
}
