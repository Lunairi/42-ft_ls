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

int		multi_flagging(char **av, t_flags *toggle, char **search)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (av[i][0] == '-')
			if (check_flags(av[i], toggle))
				return (0);
		if (av[i][0] != '-')
		{
			search[toggle->exist] = av[i];
			toggle->exist++;
		}
		i++;
	}
	return (0);
}

int		parse_multi(int ac, char **av)
{
	t_flags	*toggle;
	char	**search;
	int		i;

	search = (char**)ft_memalloc(sizeof(char*) * 99999999);
	toggle = ft_memalloc(sizeof(t_flags));
	i = 1;
	toggle->exist = 0;
	multi_flagging(av, toggle, search);
	if (toggle->exist == 0)
	{
		search[toggle->exist] = ".";
		toggle->exist++;
	}
	sort_file_dir(search, toggle->exist, toggle);
	free(search);
	free(toggle);
	return (0);
}
