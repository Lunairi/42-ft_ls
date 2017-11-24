#include <sys/ioctl.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		return (c);
}

int		ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

size_t		ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

int	check_upper(const char *s1, const char *s2)
{
	// printf("%c %c \n", *s1, *s2);
	while ((ft_tolower(*s1) == ft_tolower(*s2))
			&& (*s1 != '\0') && (*s2 != '\0'))
	{
		printf("%c %c \n", *s1, *s2);
		if (ft_isupper(*s1))
			return (1);
		else
		{
			*s1++;
			*s2++;
		}
	}
	return (0);
}

int	ft_strcmpl(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (*s1 == '.' && *s1 != '\0')
		*s1++;
	while (*s2 == '.' && *s2 != '\0')
		*s2++;
	while (ft_tolower(*s1) == ft_tolower(*s2)
			&& *s1 != '\0' && *s2 != '\0')
	{
		*s1++;
		*s2++;
	}
	if (check_upper(s1, s2))
		return -1;
	return (ft_tolower(*s1) - ft_tolower(*s2));
}

// int		ls(char *str, char *find, int fprint)
// {
// 	struct dirent	*d;
// 	DIR				*dir;

// 	if ((dir = opendir(".")) == NULL)
// 	{
// 			return (0);
// 	}
// 	while ((d = readdir(dir)))
// 	{
// 		// printf("find %s str %s\n", find, d->d_name);
// 		if(find == NULL && d->d_name[0] != '.')
// 			printf("%s\n", d->d_name);
// 		else if ((ft_strcmp(d->d_name, find)) && d->d_name[0] != '.')
// 		{
// 			printf("%s\n", d->d_name);
// 			fprint = 1;
// 		}
// 	}
// 	if (fprint == 0 && find != NULL)
// 		printf("ft_ls: cannot access '%s': No such file or directory\n", find);
// 	closedir(dir);
// }

void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
		((unsigned char *)s)[--n] = 0;
}

void	*ft_memalloc(size_t size)
{
	char	*ptr;

	if (size <= 0)
		return (NULL);
	ptr = (char *)malloc(size * sizeof(*ptr));
	ft_bzero(ptr, size);
	return ((void *)ptr);
}


char	*ft_strcpy(char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i += 1;
	}
	s1[i] = '\0';
	return (s1);
}

int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_isalpha(int c)
{
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}

int		sort_list(char *one, char *two)
{
	return (ft_strcmpl(one, two));
}

void	swap_item(char **one, char **two)
{
	char *tmp;

	tmp = *one;
	*one = *two;
	*two = tmp;
}

void	print_r(char **list, int size)
{
	int 	i;
	char 	*tmp;
	int		count;

	i = 0;
	count = 0;
	while (i < size)
	{
		if ((list[i + 1] != NULL))
		{
			if(ft_strcmpl(list[i + 1], list[i]) < 0)
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
	if (count == 0)
	{
		// For reversing . and ..
		swap_item(&list[0], &list[1]);
		i = size - 1;
		while (i >= 0)
		{
			if (list[i][0] != '.')
				printf("%s\n", list[i]);
			i--;
		}
	}
	else
		print_r(list, size);
}

void	print_a(char **list, int size)
{
	int 	i;
	char 	*tmp;
	int		count;

	i = 0;
	count = 0;
	while (i < size)
	{
		if ((list[i + 1] != NULL))
		{
			if(ft_strcmpl(list[i + 1], list[i]) < 0)
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
	if (count == 0)
	{
		swap_item(&list[0], &list[1]);
		i = -1;
		while (++i < size)
			printf("%s\n", list[i]);
	}
	else
		print_a(list, size);
}

void	print_one(char **list, int size)
{
	int 	i;
	char 	*tmp;
	int		count;

	i = 0;
	count = 0;
	while (i < size)
	{
		if ((list[i + 1] != NULL))
		{
			if(ft_strcmpl(list[i + 1], list[i]) < 0)
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
	if (count == 0)
	{
		// For reversing . and ..
		swap_item(&list[0], &list[1]);
		i = 0;
		while (i < size)
		{
			if (list[i][0] != '.')
				printf("%s\n", list[i]);
			i++;
		}
	}
	else
		print_one(list, size);
}

void	print_sort(char **list, int size, int type)
{
	type == 1 ? print_one(list, size) : 0;
	type == 2 ? print_r(list, size) : 0;
	type == 3 ? print_a(list, size) : 0;
}

int		ls_single(char *str, int type)
{
	struct dirent	*d;
	DIR				*dir;
	char			**list;
	int				i;

	i = 0;
	list = (char**)ft_memalloc(sizeof(char**)*99999);
	dir = opendir(str);
	if (dir == NULL)
		return (0);
	while ((d = readdir(dir)))
	{
		list[i] = (char*)ft_memalloc(sizeof(char*)*99999);
		// list[i] = ft_strcpy(list[i], d->d_name);
		list[i] = d->d_name;
		// printf("%s\n", *list);
		i++;
	}
	print_sort(list, i, type);
	free(list);
}

void	parse_single(char *flag, char *search)
{
	// printf("flag %s, search %s", flag, search);
	flag[0] == '-' && flag[1] == '1' ? ls_single(search, 1) : 0;
	flag[0] == '-' && flag[1] == 'r' ? ls_single(search, 2) : 0;
	flag[0] == '-' && flag[1] == 'a' ? ls_single(search, 3) : 0;
	flag[0] != '-' ? ls_single(search, 1) : 0;
	// ls(str);
}

int		main(int ac, char **av)
{
	if(ac < 4)
	{
		if (av[1] == NULL)
			parse_single(".", ".");
		else if (av[2] == NULL)
			parse_single(av[1], ".");
		else
			parse_single(av[1], av[2]);
	}
	// else if (ac >= 3)
	// {
	// 	while(ac-- > 1)
	// 		parse_flag(av[1], av[ac]);
	// }
	return (0);
}