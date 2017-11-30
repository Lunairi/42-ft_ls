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

New Functions Learning List:
- ~opendir (studied and used)~
- ~readdir (studied and used)~
- ~closedir (studied and used)~
- ~stat (studied and used)~
- lstat (studied, not yet used)
- ~getpwuid (studied and used)~
- ~getgrgid (studied and used)~
- listxattr (did not study yet)
- getxattr (did not study yet)
- time (studied, not yet used)
- ~ctime (studied and used)~
- readlink (studied, not yet used)
- perror (studied, not yet used)
- strerror (studied, not yet used)
