# 42-ft_ls
First unix/system branch project. Recreate ls functionality in terminal with C. In progress (because filler has binaries that doesn't work on my laptop while I'm in vegas sadly). Have no experience with anything in dirent.h library, lots of learning

Day 1 (About 3~4 hours)
Completed: N/A
Incomplete: -R, -t, basic sorting algorithm, sort hidden items, sort upper/lower
In Progress: -1, -a, -r
Notes: Learned about opendir() readdir() closedir(), trying to mimic ls -1, ls -1 -a and ls -1 -r

Day 2 (About 3-4 hours)
Completed: Basic output of opendir
Incomplete: -R, -t, sort hidden items, sort upper/lower
In Progress: -1, -a, -r, basic sorting algorithm
Notes: At the moment can only handle no additional argv, will need to use stat() and lstat() later to discern directories/files to handle multiple argv

Day 3 (In Progress)
Completed: Basic output, basic sorting algorithm, sort hidden items
Incomplette: -R, -t, handle multiple argv
In Progress: -1, -a, -r, sort upper/lower
Note: Until I finalize handle multiple argv I won't consider any -commands completed, currently working on basic output with simple argv before transitioning into mutliple argv which will require me to use more of the functions below

New Functions Learning List:
◦ opendir (completed)
◦ readdir (completed)
◦ closedir (completed)
◦ stat (studied, not yet used)
◦ lstat (studied, not yet used)
◦ getpwuid (did not study yet)
◦ getgrgid (did not study yet)
◦ listxattr (did not study yet)
◦ getxattr (did not study yet)
◦ time (studied, not yet used)
◦ ctime (studied, not yet used)
◦ readlink (did not study yet)
◦ perror (studied, not yet used)
◦ strerror (studied, not yet used)
