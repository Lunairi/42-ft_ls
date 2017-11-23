#include <sys/ioctl.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/*
** This function specifically is made to detect the longest
** item name so I can display regular ls on one line. Static
** is used so I never lose track of the largest int that I do
** end up getting for the item through this function
** NOTE: Commented out, turns out ls by itself is not necessary to do
** row format, leaving this here in the event I choose to finish it
*/

// int		longestitem(char *str, int i)
// {
// 	static int longest;

// 	while (str[i] != '\0')
// 		i++;
// 	if (i > longest)
// 		longest = i;
// 	return (longest);
// }

// int		ft_strlen(char *str)
// {
// 	int i;

// 	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }

int		ls(char *str, char *find)
{
	struct dirent	*d;
	DIR				*dir;

	if ((dir = opendir(str)) == NULL)
		return (0);
	while ((d = readdir(dir)))
	{
		// printf("find %s str %s\n", find, d->d_name);
		if(find == NULL && d->d_name[0] != '.')
			printf("%s\n", d->d_name);
		else if (find == d->d_name)
			printf("%s\n", d->d_name);
	}
}

/*
** This function does two important thing. First, it gets max and w.ws_col
** which is necessary for default ls where items are displayed in one line.
** w.ws_col will provide me the info on the terminal col length, while max
** will be equal to the longest item length, this way I can calculate
** how many items can be pasted on one line (w.ws_col / max) and
** also print out the width necessary to make them all line up neatly
** NOTE: Commented out, turns out ls by itself is not necessary to do
** row format, leaving this here in the event I choose to finish it
*/

// int		setup(char *str)
// {
//     struct winsize	w;
// 	int				max;
// 	struct dirent	*d;
// 	DIR				*dir;
	
// 	if ((dir = opendir(str)) == NULL)
// 		return (0);
// 	while ((d = readdir(dir)))
// 		max = longestitem(d->d_name, 0);
// 	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
// 	ls(str, max, w.ws_col);
// }

void	parse_flag(char *str, char *find)
{
	str[0] == '-' && str[1] == '1' ? ls(".", find) : 0;
	str[0] == '-' && str[1] == 'R' ? ls(str, find) : 0;
	str[0] != '-' ? ls(str, find) : 0;
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
	else
	{
		while(--ac > 1)
			parse_flag(av[1], av[ac]);
	}
	return (0);
}