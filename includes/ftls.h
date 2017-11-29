/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mizukori250@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 09:00:00 by mlu               #+#    #+#             */
/*   Updated: 2017/08/25 09:00:00 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTLS_H
# define FTLS_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>
# include <math.h>
# include <sys/ioctl.h>
# include <dirent.h>

# include "libft.h"

typedef struct	s_flags
{
	int 		r;
	int			a;
	int			l;
	int			t;
}				t_flags;

/*
** multi.c
*/
int				parse_multi(int ac, char **av);

/*
** single.c
*/
int				ls_single(char *str, t_flags *toggle);
int				parse_single(char *flag, char *search);

/*
** printsort.c
*/
void			print_list(char **list, int size, t_flags *toggle);
void			sort_recursive(char **list, int size, t_flags *toggle);

/*
** utility.c
*/
int				item_amount(char *str);
void			swap_item(char **one, char **two);

#endif
