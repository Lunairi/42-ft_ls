/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/11/28 17:43:16 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

void	help_ls()
{
	ft_printf("Usage: ft_ls [OPTION]... [FILE]...\n");
	ft_printf("List information about the FILEs (the current directory by default).\n");
	ft_printf("Mandatory arguments to long options are mandatory for short options too.\n");
  	ft_printf("-a, --all                  do not ignore entries starting with .\n");
	ft_printf("-l                         use a long listing format\n");
	ft_printf("-r, --reverse              reverse order while sorting\n");
	ft_printf("-R, --recursive            list subdirectories recursively\n");
	ft_printf("-t                         sort by modification time, newest first\n");
	ft_printf("-1                         list one file per line\n");
	ft_printf("--help                     display this help and exit\n");
}

int		main(int ac, char **av)
{
	if (av[1] == NULL)
		parse_single(".", ".");
	else if (!(ft_strcmp(av[1], "--help")))
		help_ls();
	else if (av[2] == NULL && av[1][0] == '-')
		parse_single(av[1], ".");
	else if (av[2] == NULL)
		parse_single(".", av[1]);
	else
		parse_multi(ac, av);
	return (0);
}
