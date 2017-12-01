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

static int file_type(int mode)
{
	char	c;

	if (S_ISREG(mode))
		c = '-';
	else if (S_ISDIR(mode))
		c = 'd';
	else if (S_ISBLK(mode))
		c = 'b';
	else if (S_ISCHR(mode))
		c = 'c';
	else if (S_ISFIFO(mode))
		c = 'p';
	else if (S_ISLNK(mode))
		c = 'l';
	else if (S_ISSOCK(mode))
		c = 's';
	else
		c = '?';
	return(c);
}

char	*perms(int mode)
{
	static const char *rwx[] = {"---", "--x", "-w-", "-wx",
		"r--", "r-x", "rw-", "rwx"};
	static char bits[11];

	bits[0] = file_type(mode);
	ft_strcpy(&bits[1], rwx[(mode >> 6)& 7]);
	ft_strcpy(&bits[4], rwx[(mode >> 3)& 7]);
	ft_strcpy(&bits[7], rwx[(mode & 7)]);
	if (mode & S_ISUID)
		bits[3] = (mode & S_IXUSR) ? 's' : 'S';
	if (mode & S_ISGID)
		bits[6] = (mode & S_IXGRP) ? 's' : 'l';
	if (mode & S_ISVTX)
		bits[9] = (mode & S_IXOTH) ? 't' : 'T';
	bits[10] = '\0';
	return(bits);
}

void	print_spacing(t_flags *toggle, char *dir)
{
	if (dir != NULL)
	{
		while (toggle->i-- > 0)
			ft_putstr(" ");
	}
}

void	print_date_name(t_flags *toggle, char *str, char *mtime)
{
	toggle->i = 3;
	while (++toggle->i < 16)
		write(1, &mtime[toggle->i], 1);
	ft_printf(" %s\n", str);
}

void	print_l(char *str, char *dir, char *file, t_flags *toggle)
{
	struct stat		items;
	struct passwd	user;
	struct group	group;
	char			*bits;
	char			*mtime;

	// if (dir != NULL)
	// {
		file = ft_strjoin(dir, "/");
		file = ft_strjoin(file, str);
	// }
	// else
	// 	file = str;
	stat(file, &items);
	bits = perms(items.st_mode);
	user = *getpwuid(items.st_uid);
	group = *getgrgid(items.st_gid);
	ft_printf("%s  ", bits);
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
	ft_printf("%llu ", items.st_size);
	print_date_name(toggle, str, ctime(&items.st_mtime));
}
