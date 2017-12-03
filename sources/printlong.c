/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlong.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/11/28 17:43:16 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

void		print_xattr(t_flags *toggle, struct stat timer, char *mtime)
{
	toggle->i = 19;
	write(1, " ", 1);
	while (++toggle->i < 24)
		write(1, &mtime[toggle->i], 1);
}

void		print_date_name(t_flags *toggle, char *str,
					struct stat timer, char *file)
{
	char			buf[1024];
	ssize_t			len;
	char			*mtime;

	ft_printf("%llu ", timer.st_size);
	mtime = ctime(&timer.st_mtime);
	toggle->i = 3;
	while (++toggle->i < 11)
		write(1, &mtime[toggle->i], 1);
	if (time(NULL) - timer.st_mtimespec.tv_sec >= 15724800)
		print_xattr(toggle, timer, mtime);
	else
	{
		toggle->i = 10;
		while (++toggle->i < 16)
			write(1, &mtime[toggle->i], 1);
	}
	if ((len = readlink(file, buf, sizeof(buf) - 1)) != -1)
	{
		buf[len] = '\0';
		str = ft_strjoin(str, " -> ");
		str = ft_strjoin(str, buf);
	}
	ft_printf(" %s\n", str);
}

void		print_l_f(char *str, char *file, t_flags *toggle)
{
	struct stat		items;
	struct passwd	user;
	struct group	group;
	char			*bits;
	char			*mtime;

	lstat(str, &items);
	bits = perms(items.st_mode);
	user = *getpwuid(items.st_uid);
	group = *getgrgid(items.st_gid);
	ft_printf("%s", bits);
	suffix(file);
	if ((toggle->i = (toggle->fnlinks - ft_numlen(items.st_nlink))) > 0)
		print_spacing(toggle, str);
	ft_printf("%i ", items.st_nlink);
	if ((toggle->i = (toggle->fuid - ft_strlen(user.pw_name))) > 0)
		print_spacing(toggle, str);
	ft_printf("%s  ", user.pw_name);
	if ((toggle->i = (toggle->fgid - ft_strlen(group.gr_name))) > 0)
		print_spacing(toggle, str);
	ft_printf("%s ", group.gr_name);
	if ((toggle->i = (toggle->fsize - ft_numullen(items.st_size))) > 0)
		print_spacing(toggle, str);
	ft_printf("%llu ", items.st_size);
	print_date_name(toggle, str, items, file);
}

void		set_file(char *str, char *dir, char **file)
{
	if (dir != NULL)
	{
		*file = ft_strjoin(dir, "/");
		*file = ft_strjoin(*file, str);
	}
	else
		*file = str;
}

void		print_l(char *str, char *dir, char *file, t_flags *toggle)
{
	struct stat		items;
	struct passwd	user;
	struct group	group;
	char			*bits;
	char			*mtime;

	set_file(str, dir, &file);
	lstat(file, &items);
	bits = perms(items.st_mode);
	user = *getpwuid(items.st_uid);
	group = *getgrgid(items.st_gid);
	ft_printf("%s", bits);
	suffix(file);
	if ((toggle->i = (toggle->nlinks - ft_numlen(items.st_nlink))) > 0)
		print_spacing(toggle, dir);
	ft_printf("%i ", items.st_nlink);
	if ((toggle->i = (toggle->uid - ft_strlen(user.pw_name))) > 0)
		print_spacing(toggle, dir);
	ft_printf("%s  ", user.pw_name);
	if ((toggle->i = (toggle->gid - ft_strlen(group.gr_name))) > 0)
		print_spacing(toggle, dir);
	ft_printf("%s ", group.gr_name);
	if ((toggle->i = (toggle->size - ft_numullen(items.st_size))) > 0)
		print_spacing(toggle, dir);
	print_date_name(toggle, str, items, file);
}
