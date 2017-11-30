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

int		check_flags(char *str, t_flags *toggle)
{
	int i;

	i = 0;
	while (str[++i] != '\0')
	{
		str[i] == 'r' ? toggle->r = 1 : 0;
		str[i] == 'a' ? toggle->a = 1 : 0;
		str[i] == 'l' ? toggle->l = 1 : 0;
		str[i] == 't' ? toggle->t = 1 : 0;
		str[i] == 'R' ? toggle->R = 1 : 0;
		if (str[i] != 'r' && str[i] != 'a' && str[i] != '1'
			&& str[i] != 'l' && str[i] != 't' && str[i] != 'R')	
		{
			ft_printf("ft_ls: illegal option -- '%c'\n", str[i]);
			ft_printf("Try 'ft_ls --help' for more information.\n");
			return (1);
		}
	}
	return (0);
}

int		item_amount(char *str)
{
	struct dirent	*d;
	DIR				*dir;
	int				i;
	struct stat		items;

	i = 0;
	dir = opendir(str);
	stat(str, &items);
	if (S_ISREG(items.st_mode))
	{
		ft_printf("%s\n", str);
		return (0);
	}
	else if (dir == NULL)
	{
		ft_printf("ft_ls: %s: No such file or directory\n", str);
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
