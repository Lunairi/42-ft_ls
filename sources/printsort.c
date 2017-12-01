/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/11/28 17:43:16 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

void	long_data(char *str, char *dir, char *file, t_flags *toggle)
{
	struct stat		items;
	struct passwd	user;
	struct group	group;

    file = ft_strjoin(dir, "/");
    file = ft_strjoin(file, str);
	stat(file, &items);
	toggle->blocks = toggle->blocks + items.st_blocks;
	user = *getpwuid(items.st_uid);
	if (ft_strlen(user.pw_name) > toggle->uid)
		toggle->uid = ft_strlen(user.pw_name);
	group = *getgrgid(items.st_gid);
	if (ft_strlen(group.gr_name) > toggle->gid)
		toggle->gid = ft_strlen(group.gr_name);
	if (ft_numullen(items.st_size) > toggle->size)
		toggle->size = ft_numullen(items.st_size);
	if (ft_numlen(items.st_nlink) > toggle->nlinks)
		toggle->nlinks = ft_numlen(items.st_nlink);
}

void	print_long(char **list, int size, t_flags *toggle, char *dir)
{
	int i;

	i = -1;
	while (++i < size)
	{
		if (list[i][0] != '.' && toggle->a == 0)
			long_data(list[i], dir, 0, toggle);
		if (toggle->a == 1)
			long_data(list[i], dir, 0, toggle);
	}
	if (toggle->r == 1)
		i = size - 1;
	else
		i = 0;
	ft_printf("total %lli\n", toggle->blocks);
	while (i < size)
	{
		if (list[i][0] != '.' && toggle->a == 0) // will not print hidden files
			print_l(list[i], dir, 0, toggle);
		if (toggle->a == 1) // will print hidden files
			print_l(list[i], dir, 0, toggle);
		if (toggle->r == 1)
			i--;
		else
			i++;
		if (i == -1) // really not needed but lazy way of handling r reverse counting down without two print function
			i = size;
	}
}

void	print_list(char **list, int size, t_flags *toggle)
{
	int i;

	if (toggle->r == 1)
		i = size - 1;
	else
		i = 0;
	while (i < size)
	{
		if (list[i][0] != '.' && toggle->a == 0) // will not print hidden files
			ft_printf("%s\n", list[i]);
		if (toggle->a == 1) // will print hidden files
			ft_printf("%s\n", list[i]);
		if (toggle->r == 1)
			i--;
		else
			i++;
		if (i == -1) // really not needed but lazy way of handling r reverse counting down without two print function
			i = size;
	}
}

int		time_compare(char *one, char *two)
{
	struct stat		mtime1;
	struct stat		mtime2;

	stat(one, &mtime1);
	stat(two, &mtime2);
	if (mtime1.st_mtime > mtime2.st_mtime)
		return (-1);
	if (mtime1.st_mtime == mtime2.st_mtime)
	{
		if (mtime1.st_mtimespec.tv_nsec > mtime2.st_mtimespec.tv_nsec)
			return (-1);
		else if (mtime1.st_mtimespec.tv_nsec == mtime2.st_mtimespec.tv_nsec)
			return (ft_strcmp(two, one));
	}
	return (0);

}

void	time_sort_recursive(char **list, int size, t_flags *toggle, char *dir)
{
	int 	i;
	int		count;

	i = 0;
	count = 0;
	while (i < size)
	{
		if ((list[i + 1] != NULL))
		{
			if (time_compare(list[i + 1], list[i]) < 0)
			{
				swap_item(&list[i], &list[i + 1]);
				count = 1;
			}
			else
				i++;
		}
		else
			i++;
	}
	if (count == 0 && toggle->l == 1)
		print_long(list, size, toggle, dir);
	else if (count == 0)
		print_list(list, size, toggle);
	else
		time_sort_recursive(list, size, toggle, dir);
}

void	sort_recursive(char **list, int size, t_flags *toggle, char *dir)
{
	int 	i;
	int		count;

	i = 0;
	count = 0;
	while (i < size)
	{
		if ((list[i + 1] != NULL))
		{
			if (ft_strcmp(list[i + 1], list[i]) < 0)
			{
				swap_item(&list[i], &list[i + 1]);
				count = 1;
			}
			else
				i++;
		}
		else
			i++;
	}
	if (count == 0 && toggle->l == 1)
		print_long(list, size, toggle, dir);
	else if (count == 0)
		print_list(list, size, toggle);
	else
		sort_recursive(list, size, toggle, dir);
}
