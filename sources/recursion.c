/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/11/28 17:43:16 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

int		rname(char *d)
{
	if ((ft_strcmp(d, "..") != 0) && (ft_strcmp(d, ".") != 0))
		return (1);
	return (0);
}

void	dir_recursion(char **search, t_flags *toggle, int i)
{
	struct stat		items;
	struct dirent	*d;
	DIR				*dir;
	char			*file;

	dir = opendir(search[i]);
	while (dir != NULL && (d = readdir(dir)))
	{
		if ((toggle->a == 1) ||
				(d->d_name[0] != '.' && toggle->a == 0))
		{
			file = ft_strjoin(search[i], "/");
			file = ft_strjoin(file, d->d_name);
			if (lstat(file, &items) == 0)
			{
				if (S_ISDIR(items.st_mode) && rname(d->d_name))
				{
					search[toggle->exist++] = file;
					dir_recursion(search, toggle, (toggle->exist - 1));
				}
			}
			else
				ft_printf("Error %s: %s\n", file, strerror(errno));
		}
	}
}

void	file_dir_recursion(char **search, t_flags *toggle, int i, int exist)
{
	struct stat		items;
	struct dirent	*d;
	DIR				*dir;

	while (++i < exist)
	{
		lstat(search[i], &items);
		if (S_ISDIR(items.st_mode))
		{
			dir_recursion(search, toggle, i);
		}
	}
}
