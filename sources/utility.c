/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/11/28 17:43:16 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

int		item_amount(char *str)
{
	struct dirent	*d;
	DIR				*dir;
	int				i;

	i = 0;
	dir = opendir(str);
	if (dir == NULL)
	{
		// need to discern between dir and file for display or error, will do later
		ft_printf("ft_ls: cannot access '%s': No such file or directory\n", str);
		return (0);
	}
	while ((d = readdir(dir)))
		i++;
	closedir(dir);
	return (i + 1);
}

void	swap_item(char **one, char **two)
{
	char *tmp;

	tmp = *one;
	*one = *two;
	*two = tmp;
}
