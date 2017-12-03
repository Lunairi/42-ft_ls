/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/11/28 17:43:16 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

int		alpha_sort_fd(char **search, int i, t_flags *toggle)
{
	if (search[i + 1] == NULL)
		return (0);
	if (toggle->r == 1)
	{
		if (ft_strcmp(search[i + 1], search[i]) < 0)
		{
			swap_item(&search[i], &search[i + 1]);
			return (1);
		}
	}
	else
	{
		if (ft_strcmp(search[i + 1], search[i]) < 0)
		{
			swap_item(&search[i], &search[i + 1]);
			return (1);
		}
	}
	return (0);
}

int		time_sort_fd(char **search, int i, t_flags *toggle)
{
	int ret;

	if (search[i + 1] == NULL)
		return (1);
	ret = time_compare(search[i + 1], search[i], 0);
	if (ret == -1)
	{
		swap_item(&search[i + 1], &search[i]);
		return (1);
	}
	else
		return (0);
}

void	revert_file_list(char **search, t_flags *toggle, int x, int y)
{
	char *tmp;

	y--;
	while (x < y)
	{
		tmp = search[x];
		search[x] = search[y];
		search[y] = tmp;
		x++;
		y--;
	}
}

void	file_dir_reverse_sort(char **search, int exist, t_flags *toggle, int i)
{
	struct stat	items;
	int			count;

	count = 0;
	while (i < exist)
	{
		if (search[i + 1] != NULL)
		{
			stat(search[i], &items);
			if (S_ISREG(items.st_mode))
			{
				toggle->total++;
				i++;
			}
			else
				i++;
		}
		else
			i++;
	}
	revert_file_list(search, toggle, 0, toggle->total);
}
