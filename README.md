# 42-ft_ls
First unix/system branch project. Recreate ls functionality in terminal with C. In progress (because filler has binaries that doesn't work on my laptop while I'm in vegas sadly). Have no experience with anything in dirent.h library, lots of learning

Day 1 (About 3 hours)
- Completed: N/A
- Incomplete: -R, -t, basic sorting algorithm, sort hidden items, sort upper/lower
- In Progress: -l, -a, -r
- Notes: Learned about opendir() readdir() closedir(), trying to mimic ls -1, ls -1 -a and ls -1 -r

Day 2 (About 4 hours)
- Completed: Basic output of opendir
- Incomplete: -R, -t, sort hidden items, sort upper/lower
- In Progress: -l, -a, -r, basic sorting algorithm
- Notes: At the moment can only handle no additional argv, will need to use stat() and lstat() later to discern directories/files to handle multiple argv

Day 3 (About 10 hours)
- Completed: Basic output, basic sorting algorithm, sort hidden items, --help, customized flag system, -1, -a, -r, handle multiple argv
- Incomplete: N/A
- In Progress: -l, sort upper/lower, -t, -R, error handling for multi files/dir
- Note: Thanks to cyildiri was able to fix a heap overflow, re-optimized my reading to avoid reading too far. Fixed all leak and freed all memory, valgrind shows no leak and -fsanitize=address has no issue. Fully implemented a multi parser and single parser being able to handle any number of flags. Print/sort is universal and works with both multi and single. Only need to work on -l, -t, -R and make sure that they can fit without too much issue, will have to delve into the function list below to pull info and parse/store info to make -l work. I think -l and -t will be my main priority, my setup is already recursive and I don't see myself having problems doing -R. Also forgot need to mimic ls error for multiple files/dir.

Day 4 (About 3 hours)
- Completed: Basic output, basic sorting algorithm, sort hidden items, --help, customized flag system, -1, -a, -r, handle multiple argv, error handling for multi files/dir
- Incomplete: N/A
- In Progress: -l, -t, -R
- Note: -l function is working but not properly formatted, turns out sort upper/lower was only a linux thing so no longer needs to be completed. -t can easily be done, and setting up the print so that -R can be completed easily. Overall good progress, also started to work on Joe Krause https://github.com/SuperSpyTX who started ls.

Day 5 (About 4 hours)
- Completed: Basic output, basic sorting algorithm, sort hidden items, --help, customized flag system, -1, -a, -r, handle multiple argv, error handling for multi files/dir, -t
- Incomplete: N/A
- In Progress: -l, -R
- Note: -l function has some specific format differences for when you do a regular item versus directory and how it's formatted. -R will be finalized at the end, trying to make -l as close to the same format as -l. -t was relatively quick, had to use timespec to get nanosecond for the most accurate copy, thanks to Stephen Gardner https://github.com/stephen-gardner for some tips and the right direction for some wonky behavior I was having with -t prior to using timespec.

Day 6 (About 6 hours)
- Completed: Basic output, basic sorting algorithm, sort hidden items, --help, customized flag system, -1, -a, -r, handle multiple argv, error handling for multi files/dir, -t, symbolic link, xattr, -l, sort file before dir display
- Incomplete: N/A
- In Progress: -R
- Note: Made alot of progress with completing a big portion of ls, it's almost done. I'd like to turn it in already but need to make -R happen, have it setup so it should theoretically work, time to test it out.

Day 7 (About 5 hours)
- Completed: Basic output, basic sorting algorithm, sort hidden items, --help, customized flag system, -1, -a, -r, handle multiple argv, error handling for multi files/dir, -t, symbolic link, xattr, -l, sort file before dir display, -R
- Incomplete: N/A
- In Progress: N/A
- Note: Finally completed basic ls but there is a problem with optimization. Because I sort everything into a list than sort that humongous list individually for each flag my ls is very slow upon bigger directories. This can be fixed if I swapped my array into a linked list, however at this point for the project I've already invested 35 hours into ls and decided to move on. If I need a more optimized ls I will focus on that next time.

New Functions Learning List:
- ~opendir (studied and used)~
- ~readdir (studied and used)~
- ~closedir (studied and used)~
- ~stat (studied and used)~
- ~lstat (studied and used)~
- ~getpwuid (studied and used)~
- ~getgrgid (studied and used)~
- ~listxattr (studied and used)~
- ~getxattr (studied and used)~
- ~time (studied and used)~
- ~ctime (studied and used)~
- ~readlink (studied and used)~
- ~perror (studied, did not use)~
- ~strerror (studied and used)~
