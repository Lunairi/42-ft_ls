/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/11/28 17:43:16 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

void	sort_hub(char **search, int exist, t_flags *toggle, int i)
{
	file_dir_sort(search, toggle->exist, toggle, 0);
	file_dir_alpha_sort(search, toggle->exist, toggle, 0);
	if (toggle->t == 1)
		file_dir_time_sort(search, toggle->exist, toggle, 0);
	if (toggle->r == 1)
		file_dir_reverse_sort(search, toggle->exist, toggle, 0);
}

void	print_info_mode(char *str, char *dir, t_flags *toggle)
{
	struct stat		items;
	char			*file;

	if (dir == NULL)
		file = str;
	else
		file = dir;
	stat(file, &items);
	if (S_ISDIR(items.st_mode) && toggle->exist > 1)
	{
		if (toggle->file == 0)
			toggle->file = 1;
		else
			write(1, "\n", 1);
		ft_printf("%s:\n", dir);
		if (toggle->l == 1 && toggle->blocks > 0)
			ft_printf("total %lli\n", toggle->blocks);
	}
	if (S_ISDIR(items.st_mode) && toggle->exist <= 1)
		ft_printf("total %lli\n", toggle->blocks);
}

void	grab_format_file(char *str, char *file, t_flags *toggle)
{
	struct stat		items;
	struct passwd	user;
	struct group	group;

	stat(str, &items);
	if (S_ISREG(items.st_mode))
	{
		user = *getpwuid(items.st_uid);
		if (ft_strlen(user.pw_name) > toggle->fuid)
			toggle->fuid = ft_strlen(user.pw_name);
		group = *getgrgid(items.st_gid);
		if (ft_strlen(group.gr_name) > toggle->fgid)
			toggle->fgid = ft_strlen(group.gr_name);
		if (ft_numullen(items.st_size) > toggle->fsize)
			toggle->fsize = ft_numullen(items.st_size);
		if (ft_numlen(items.st_nlink) > toggle->fnlinks)
			toggle->fnlinks = ft_numlen(items.st_nlink);
	}
}

int		mode_compare(int one, int two, t_flags *toggle)
{
	int a;
	int b;

	a = 0;
	b = 0;
	if (S_ISREG(one))
	{
		toggle->file = 1;
		a = 1;
	}
	if (S_ISREG(two))
	{
		toggle->file = 1;
		b = 1;
	}
	return (a - b);
}
