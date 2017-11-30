/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/11/28 17:43:16 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

int		parse_multi(int ac, char **av)
{
	t_flags	*toggle;
	char	**search;
	int 	i;
	int		exist;

	search = (char**)ft_memalloc(sizeof(char*) * (ac - 1));
	toggle = ft_memalloc(sizeof(t_flags));
	// ft_printf("%p toggle | %p search\n", toggle, search);
	i = 1;
	exist = 0;
	while (av[i])
	{
		if(av[i][0] == '-')
		{
			if (av[i][1] != 'r' && av[i][1] != 'a' && av[i][1] != '1' && av[i][1] != 'l')	
			{
				ft_printf("ls: invalid option -- '%c'\n", av[i][1]);
				ft_printf("Try 'ft_ls --help' for more information.\n");
				return (0);
			}
		}
		av[i][0] == '-' && av[i][1] == 'r' ? toggle->r = 1 : 0;
		av[i][0] == '-' && av[i][1] == 'a' ? toggle->a = 1 : 0;
		av[i][0] == '-' && av[i][1] == 'l' ? toggle->l = 1 : 0;
		if (av[i][0] != '-')
		{
			search[exist] = av[i];
			// printf("Item: %s\n", search[exist]); // remove later, used to test -l
			// print_l(search[exist]); // remove later, used to test -l
			exist++;
		}
		i++;
	}
	if (exist == 0)
	{
		search[exist] = ".";
		exist++;
	}
	i = exist - 1;
	while (i >= 0)
	{
		if (exist > 1) // temporary, doesn't work properly with file and dir
			ft_printf("%s:\n", search[i]);
		ls_single(search[i], toggle); // uncomment later after testing -l
		i--;
		if (i >= 0) // temp for new line
			write(1, "\n", 1);
	}
	free(search);
	free(toggle);
	return (0);
}
