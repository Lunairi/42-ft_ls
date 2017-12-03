/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/11/28 17:43:16 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

int		item_long(char *str, t_flags *toggle)
{
	struct dirent	*d;
	DIR				*dir;
	int				i;
	struct stat		items;

	i = 0;
	dir = opendir(str);
	stat(str, &items);
	if (S_ISREG(items.st_mode))
		return (-1);
	else if (dir == NULL && (!(S_ISREG(items.st_mode))))
	{
		ft_printf("ft_ls: %s: No such file or directory\n", str);
		return (0);
	}
	else if (S_ISDIR(items.st_mode))
	{
		while ((d = readdir(dir)))
			i++;
		closedir(dir);
	}
	return (i + 1);
}

void	sort_recursion(char **list, int size, t_flags *toggle, char *dir)
{
	if (toggle->t == 1)
		time_sort_recursive(list, size, toggle, dir);
	else
		sort_recursive(list, size, toggle, dir);
}

int		ls_long(char *str, t_flags *toggle, int i, int item)
{
	struct dirent	*d;
	DIR				*dir;
	char			**list;

	if ((item = item_long(str, toggle)) == 0)
		return (0);
	if (item == -1)
	{
		list = ft_memalloc(sizeof(char*));
		list[i] = str;
		print_long(list, 1, toggle, 0);
	}
	else
	{
		list = ft_memalloc(sizeof(char*) * item);
		dir = opendir(str);
		while ((d = readdir(dir)))
			list[i++] = d->d_name;
		sort_recursion(list, i, toggle, str);
		closedir(dir);
	}
	free(list);
	return (0);
}
