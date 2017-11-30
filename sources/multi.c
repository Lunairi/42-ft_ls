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
	i = 1;
	exist = 0;
	while (av[i])
	{
		if(av[i][0] == '-')
			if (check_flags(av[i], toggle))
				return (0);
		if (av[i][0] != '-')
		{
			search[exist] = av[i];
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
		ls_single(search[i], toggle); 
		i--;
		if (i >= 0) // temp for new line
			write(1, "\n", 1);
	}
	free(search);
	free(toggle);
	return (0);
}
