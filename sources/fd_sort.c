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

void	file_dir_sort(char **search, int exist, t_flags *toggle, int i)
{
	struct stat	item1;
	struct stat	item2;
	int			count;

	count = 0;
	while (i < exist)
	{
		if (search[i + 1] != NULL)
		{
			stat(search[i], &item1);
			stat(search[i + 1], &item2);
			if (mode_compare(item1.st_mode, item2.st_mode, toggle) < 0)
			{
				swap_item(&search[i], &search[i + 1]);
				count = 1;
			}
			else
				i++;
		}
		else
			i++;
	}
	if (count != 0)
		file_dir_sort(search, exist, toggle, 0);
}

void	file_dir_alpha_sort(char **search, int exist, t_flags *toggle, int i)
{
	struct stat	item1;
	struct stat	item2;
	int			count;

	count = 0;
	while (i < exist)
	{
		if (search[i + 1] != NULL)
		{
			stat(search[i], &item1);
			stat(search[i + 1], &item2);
			if (mode_compare(item1.st_mode, item2.st_mode, toggle) == 0)
			{
				if (alpha_sort_fd(search, i, toggle))
					count = 1;
				i++;
			}
			else
				i++;
		}
		else
			i++;
	}
	if (count != 0)
		file_dir_alpha_sort(search, exist, toggle, 0);
}

void	file_dir_time_sort(char **search, int exist, t_flags *toggle, int i)
{
	struct stat	item1;
	struct stat	item2;
	int			count;

	count = 0;
	while (i < exist)
	{
		if (search[i + 1] != NULL)
		{
			stat(search[i], &item1);
			stat(search[i + 1], &item2);
			if (mode_compare(item1.st_mode, item2.st_mode, toggle) == 0)
			{
				if (time_sort_fd(search, i, toggle))
					count = 1;
				i++;
			}
			else
				i++;
		}
		else
			i++;
	}
	if (count != 0)
		file_dir_time_sort(search, exist, toggle, 0);
}

void	sort_file_dir(char **search, int exist, t_flags *toggle)
{
	int i;

	i = -1;
	toggle->exist = exist;
	if (toggle->re == 1)
		file_dir_recursion(search, toggle, -1, exist);
	while (++i < toggle->exist)
	{
		if (search[i][0] != '.' && toggle->a == 0)
			grab_format_file(search[i], 0, toggle);
		if (toggle->a == 1)
			grab_format_file(search[i], 0, toggle);
	}
	sort_hub(search, toggle->exist, toggle, 0);
	i = 0;
	while (i < toggle->exist)
	{
		if (toggle->l == 1)
			ls_long(search[i], toggle, 0, 0);
		else
			ls_single(search[i], toggle);
		i++;
	}
}
