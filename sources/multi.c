/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi.c                                            :+:      :+:    :+:   */
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

int		ls_long(char *str, t_flags *toggle)
{
	struct dirent	*d;
	DIR				*dir;
	char			**list;
	int				i;
	int				item;

	i = 0;
	if ((item = item_long(str, toggle)) == 0)
		return (0);	if (item == -1)
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
		{
			list[i] = d->d_name;
			i++;
		}
		if (toggle->t == 1)
			time_sort_recursive(list, i, toggle, str);
		else
			sort_recursive(list, i, toggle, str);
		closedir(dir);
	}
	free(list);
	return (0);
}

int		parse_multi(int ac, char **av)
{
	t_flags	*toggle;
	char	**search;
	int 	i;
	int		exist;

	search = (char**)ft_memalloc(sizeof(char*) * (ac - 1));
	toggle = ft_memalloc(sizeof(t_flags));
	i = 1;
	exist = 0;
	while (av[i])
	{
		if(av[i][0] == '-')
			if (check_flags(av[i], toggle))
				return (0);
		if (av[i][0] != '-')
		{
			search[exist] = av[i];
			exist++;
		}
		i++;
	}
	if (exist == 0)
	{
		search[exist] = ".";
		exist++;
	}
	i = 0;
	while (i < exist)
	{
		if (exist > 1) // temporary, doesn't work properly with file and dir
			ft_printf("%s:\n", search[i]);
		if (toggle->l == 1)
			ls_long(search[i], toggle);
		else
			ls_single(search[i], toggle); 
		i++;
		if (i < exist) // temp for new line
			write(1, "\n", 1);
	}
	free(search);
	free(toggle);
	return (0);
}
