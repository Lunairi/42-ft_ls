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
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

# include "libft.h"

typedef struct			s_flags
{
	int					r;
	int					a;
	int					l;
	int					t;
	int					re;
	long long			blocks;
	int					nlinks;
	int					uid;
	int					gid;
	unsigned long long	size;
	unsigned long long	i;
	int					exist;
	int					file;
	int					fnlinks;
	int					fuid;
	int					fgid;
	unsigned long long	fsize;
	unsigned long long	total;
}						t_flags;

/*
** multi.c
*/
int						parse_multi(int ac, char **av);

/*
** single.c
*/
int						ls_single(char *str, t_flags *toggle);
int						parse_single(char *flag, char *search);

/*
** printsort.c
*/
void					print_list(char **list, int size, t_flags *toggle);
void					sort_recursive(char **list, int size,
							t_flags *toggle, char *dir);
void					time_sort_recursive(char **list, int size,
							t_flags *toggle, char *dir);
void					print_long(char **list, int size,
							t_flags *toggle, char *dir);

/*
** utility.c
*/
int						item_amount(char *str, t_flags *toggle);
void					swap_item(char **one, char **two);
int						check_flags(char *str, t_flags *toggle);
void					grab_format_long(char *str, char *dir,
							char *file, t_flags *toggle);
void					reset_data(t_flags *toggle);

/*
** printlong.c
*/
void					print_l(char *str, char *dir,
							char *file, t_flags *toggle);
void					print_l_f(char *str, char *file, t_flags *toggle);

/*
** fd_sort.c
*/
void					file_dir_sort(char **search, int exist,
							t_flags *toggle, int i);
void					file_dir_alpha_sort(char **search, int exist,
							t_flags *toggle, int i);
void					file_dir_time_sort(char **search, int exist,
							t_flags *toggle, int i);
void					sort_file_dir(char **search, int exist,
							t_flags *toggle);

/*
** fd_utility.c
*/
void					grab_format_file(char *str, char *file,
							t_flags *toggle);
int						mode_compare(int one, int two, t_flags *toggle);
void					print_info_mode(char *str, char *dir,
							t_flags *toggle);

/*
** long_process.c
*/
int						item_long(char *str, t_flags *toggle);
int						ls_long(char *str, t_flags *toggle, int i, int item);

/*
** print_process.c
*/
void					print_l_hub(char *str, char *dir, char *file,
							t_flags *toggle);
int						time_compare(char *one, char *two, char *dir);
void					suffix(char *path);
void					print_spacing(t_flags *toggle, char *dir);

/*
** fd_sorting.c
*/
void					file_dir_reverse_sort(char **search, int exist,
							t_flags *toggle, int i);
int						alpha_sort_fd(char **search, int i, t_flags *toggle);
int						time_sort_fd(char **search, int i, t_flags *toggle);

#endif
