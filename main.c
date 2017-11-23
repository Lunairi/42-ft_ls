#include <sys/ioctl.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	return (0);
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



int		ls(char *str)
{
	struct dirent	*d;
	DIR				*dir;
	char			**list;
	int				i;

	list = (char**)malloc(sizeof(char**) + 1);
	i = 0;
	if ((dir = opendir(str)) == NULL)
		return (0);
	while ((d = readdir(dir)))
	{
		if(d->d_name[0] != '.' && d->d_name[0] != '\0')
		{
			list[i] = (char*)malloc(sizeof(char*) + 1);
			list[i] = d->d_name;
			printf("%s list[%i]\n", list[i], i);
			i++;
		}
	}
}

void	parse_flag(char *str, char *find)
{
	(void)find;
	str[0] == '-' && str[1] == '1' ? ls(str) : 0;
	str[0] != '-' ? ls(str) : 0;
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