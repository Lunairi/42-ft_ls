#include <sys/ioctl.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/*
** This function specifically is made to detect the longest
** item name so I can display regular ls on one line
*/

int		longestitem(char *str, int i)
{
	static int longest;

	while (str[i] != '\0')
		i++;
	if (i > longest)
		longest = i;
	return (longest);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ls(char *str, int maxlength, int colsize)
{
	struct dirent	*d;
	DIR				*dir;
	int				precision;
	int				pbytes;

	precision = (colsize / maxlength); // number of dir to be displayed in one line
	// colsize is equal to the total terminal length
	// maxlength is the longest dir size
	printf("%d\n%d\n%d\n", maxlength, colsize, precision);
	if ((dir = opendir(str)) == NULL)
		return (0);
	while ((d = readdir(dir)))
	{

		// printf("%s\n", d->d_name);
	}
}

/*
** This function does two important thing. First, it gets max and w.ws_col
** which is necessary for default ls where items are displayed in one line.
** w.ws_col will provide me the info on the terminal col length, while max
** will be equal to the longest item length, this way I can calculate
** how many items can be pasted on one line (w.ws_col / max) and
** also print out the width necessary to make them all line up neatly
*/

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