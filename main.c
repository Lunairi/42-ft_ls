#include <sys/ioctl.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		longestitem(char *str, int i)
{
	static int longest;

	while(str[i] != '\0')
		i++;
	if (i > longest)
		longest = i;
	return (longest);
}

int		ls(char *str, int maxlength, int colsize)
{
	struct dirent	*d;
	DIR				*dir;

	printf("%d\n%d\n", maxlength, colsize);
	// if ((dir = opendir(str)) == NULL)
	// 	return (0);
	// while ((d = readdir(dir)))
	// {
	// 	printf("%s\n", d->d_name);
	// }
}

int		setup(char *str)
{
    struct winsize	w;
	int				max;
	struct dirent	*d;
	DIR				*dir;
	
	if ((dir = opendir(str)) == NULL)
		return (0);
	while ((d = readdir(dir)))
		max = longestitem(d->d_name, 0);
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	ls(str, max, w.ws_col);
}

int		main(int ac, char **av)
{
	(void)ac;
	if (av[1] == NULL)
		setup(".");
	else
		setup(av[1]);
	return (0);
}