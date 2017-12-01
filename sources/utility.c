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

void	reset_data(t_flags *toggle)
{
	toggle->blocks = 0;
	toggle->nlinks = 0;
	toggle->uid = 0;
	toggle->gid = 0;
	toggle->size = 0;
	toggle->i = -1;
}

void	grab_format_long(char *str, char *dir, char *file, t_flags *toggle)
{
	struct stat		items;
	struct passwd	user;
	struct group	group;

	if (dir != NULL)
	{
		file = ft_strjoin(dir, "/");
		file = ft_strjoin(file, str);
	}
	else
		file = str;
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


int		item_amount(char *str, t_flags *toggle)
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
		// if (toggle->l == 1)
		// 	print_long(&str, 1, toggle, NULL);
		// else
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
