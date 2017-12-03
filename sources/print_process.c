/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/11/28 17:43:16 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

void	print_l_hub(char *str, char *dir, char *file, t_flags *toggle)
{
	struct stat		items;

	if (dir != NULL)
		file = dir;
	else
		file = str;
	stat(file, &items);
	if (S_ISREG(items.st_mode))
		print_l_f(str, 0, toggle);
	else if (S_ISDIR(items.st_mode))
		print_l(str, dir, 0, toggle);
	else
		print_l(str, dir, 0, toggle);
}

int		time_check(char *file1, char *file2, char *one, char *two)
{
	struct stat		mtime1;
	struct stat		mtime2;

	lstat(file1, &mtime1);
	lstat(file2, &mtime2);
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

int		time_compare(char *one, char *two, char *dir)
{
	struct stat		mtime1;
	struct stat		mtime2;
	char			*file1;
	char			*file2;

	if (dir != NULL)
	{
		file1 = ft_strjoin(dir, "/");
		file1 = ft_strjoin(file1, one);
		file2 = ft_strjoin(dir, "/");
		file2 = ft_strjoin(file2, two);
	}
	else
	{
		file1 = one;
		file2 = two;
	}
	lstat(file1, &mtime1);
	lstat(file2, &mtime2);
	return (time_check(file1, file2, one, two));
}

void	suffix(char *path)
{
	acl_t			acl;
	acl_entry_t		dummy;

	acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
	{
		acl_free(acl);
		acl = 0;
	}
	if (listxattr(path, 0, 0, 0) > 0)
		write(1, "@  ", 3);
	else if (acl != 0)
		write(1, "+  ", 3);
	else
		write(1, "   ", 3);
}

void	print_spacing(t_flags *toggle, char *dir)
{
	if (dir != NULL)
	{
		while (toggle->i-- > 0)
			ft_putstr(" ");
	}
}
