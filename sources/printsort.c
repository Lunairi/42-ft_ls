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

void	print_long(char **list, int size, t_flags *toggle, char *dir)
{
	int i;

	i = -1;
	reset_data(toggle);
	while (++i < size)
	{
		if (list[i][0] != '.' && toggle->a == 0)
			grab_format_long(list[i], dir, 0, toggle);
		if (toggle->a == 1)
			grab_format_long(list[i], dir, 0, toggle);
	}
	if (toggle->r == 1)
		i = size - 1;
	else
		i = 0;
	print_info_mode(list[i], dir, toggle);
	while (i < size)
	{
		if (list[i][0] != '.' && toggle->a == 0) // will not print hidden files
			print_l_hub(list[i], dir, 0, toggle);
		if (toggle->a == 1) // will print hidden files
			print_l_hub(list[i], dir, 0, toggle);
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
			if (time_compare(list[i + 1], list[i], dir) < 0)
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
