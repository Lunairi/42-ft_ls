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

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (ft_tolower(s1[i]) == ft_tolower(s2[i])
			&& s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (ft_tolower(s1[i]) - ft_tolower(s2[i]));
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
	return (ft_strcmp(one, two));
}

void	printsort(char **list, int size)
{
	int 	i;
	char 	*tmp;
	int		count;

	i = 0;
	count = 0;
	// tmp = (char*)ft_memalloc(sizeof(char*)*99999);
	while (i < size)
	{
		// printf("i - %i || size - %i\n", i, size);
		if ((list[i + 1] != NULL))
		{
			if(ft_strcmp(list[i + 1], list[i]) < 0)
			{
				// printf("%d for %s and %s\n", ft_strcmp(list[i + 1], list[i]), list[i + 1], list[i]);
				// printf("%s %s\n", list[i + 1], list[i]);
				tmp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = tmp;
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
		i = 0;
		while (i < size)
		{
			if (list[i][0] != '.')
				printf("%s\n", list[i]);
			i++;
		}
	}
	else
		printsort(list, size);
}

int		ls_one(char *str)
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
	printsort(list, i);
}

void	parse_flag(char *str, char *find)
{
	(void)find;
	str[0] == '-' && str[1] == '1' ? ls_one(str) : 0;
	str[0] != '-' ? ls_one(str) : 0;
	// ls(str);
}

int		main(int ac, char **av)
{
	if(ac < 3 || av[1] == NULL)
	{
		if (av[1] == NULL)
			parse_flag(".", NULL);
		else
			parse_flag(av[1], NULL);
	}
	// else if (ac >= 3)
	// {
	// 	while(ac-- > 1)
	// 		parse_flag(av[1], av[ac]);
	// }
	return (0);
}