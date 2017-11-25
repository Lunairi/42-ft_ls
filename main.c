#include <sys/ioctl.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct	s_flags
{
	int 		r;
	int			a;
	int			l;
	int			t;
}				t_flags;

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

void	print_list(char **list, int size, t_flags *toggle)
{
	int i;

	swap_item(&list[0], &list[1]); // For reversing . and ..
	if (toggle->r == 1)
		i = size - 1;
	else
		i = 0;
	while (i < size)
	{
		if (list[i][0] != '.' && toggle->a == 0) // will not print hidden files
			printf("%s\n", list[i]);
		if (toggle->a == 1) // will print hidden files
			printf("%s\n", list[i]);
		if (toggle->r == 1)
			i--;
		else
			i++;
		if (i == -1) // really not needed but lazy way of handling r reverse counting down without two print function
			i = size;
	}
}

void	sort_recursive(char **list, int size, t_flags *toggle)
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
		print_list(list, size, toggle);
	else
		sort_recursive(list, size, toggle);
}

int		item_amount(char *str)
{
	struct dirent	*d;
	DIR				*dir;
	int				i;

	i = 0;
	dir = opendir(str);
	if (dir == NULL)
	{
		// need to discern between dir and file for display or error, will do later
		printf("ft_ls: cannot access '%s': No such file or directory\n", str);
		return (0);
	}
	while ((d = readdir(dir)))
		i++;
	closedir(dir);
	return (i + 1);
}

int		ls_single(char *str, t_flags *toggle)
{
	struct dirent	*d;
	DIR				*dir;
	char			**list;
	int				i;
	int				item;

	i = 0;
	if (!(item = item_amount(str))) // if return 0 it means directory couldn't open
		return (0);
	list = (char**)ft_memalloc(sizeof(char*) * item);
	dir = opendir(str);
	while ((d = readdir(dir)))
	{
		// list[i] = ft_memalloc(sizeof(str) - sizeof(char*));
		list[i] = d->d_name;
		i++;
	}
	sort_recursive(list, i, toggle);
	free(list);
	closedir(dir);
}

int		parse_single(char *flag, char *search)
{
	t_flags *toggle;

	if(flag[0] == '-')
	{
		if (flag[1] != 'r' && flag[1] != 'a' && flag[1] != '1')	
		{
			printf("ls: invalid option -- '%c'\n", flag[1]);
			printf("Try 'ft_ls --help' for more information.\n");
			return (0);
		}
	}
	toggle = ft_memalloc(sizeof(t_flags));
	flag[0] == '-' && flag[1] == 'r' ? toggle->r = 1 : 0;
	flag[0] == '-' && flag[1] == 'a' ? toggle->a = 1 : 0;
	ls_single(search, toggle);
	free(toggle);
}

void	help_ls()
{
	printf("Usage: ft_ls [OPTION]... [FILE]...\n");
	printf("List information about the FILEs (the current directory by default).\n");
	printf("Mandatory arguments to long options are mandatory for short options too.\n");
  	printf("-a, --all                  do not ignore entries starting with .\n");
	printf("-l                         use a long listing format\n");
	printf("-r, --reverse              reverse order while sorting\n");
	printf("-R, --recursive            list subdirectories recursively\n");
	printf("-t                         sort by modification time, newest first\n");
	printf("-1                         list one file per line\n");
	printf("--help                     display this help and exit\n");
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int		parse_multi(int ac, char **av)
{
	t_flags	*toggle;
	char	**search;
	int 	i;
	int		exist;

	search = (char**)ft_memalloc(sizeof(char*) * (ac - 1));
	toggle = ft_memalloc(sizeof(t_flags));
	// printf("%p toggle | %p search\n", toggle, search);
	i = 1;
	exist = 0;
	while (av[i])
	{
		if(av[i][0] == '-')
		{
			if (av[i][1] != 'r' && av[i][1] != 'a' && av[i][1] != '1')	
			{
				printf("ls: invalid option -- '%c'\n", av[i][1]);
				printf("Try 'ft_ls --help' for more information.\n");
				return (0);
			}
		}
		av[i][0] == '-' && av[i][1] == 'r' ? toggle->r = 1 : 0;
		av[i][0] == '-' && av[i][1] == 'a' ? toggle->a = 1 : 0;
		if (av[i][0] != '-')
		{
			if (*search != NULL)
				*search++;
			// *search = ft_memalloc(sizeof(av[i]) - sizeof(char*));
			*search = av[i];
			exist++;
		}
		i++;
	}
	if (exist == 0)
	{
		*search = ".";
		exist++;
	}
	i = 0;
	while (i < exist)
	{
		ls_single(search[i], toggle);
		i++;
	}
	free(search);
	free(toggle);
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