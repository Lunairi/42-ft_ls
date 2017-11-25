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

Day 3 (About 7 hours)
- Completed: Basic output, basic sorting algorithm, sort hidden items, --help, customized flag system
- Incomplete: -R, -t
- In Progress: -l, -a, -r, sort upper/lower, kind of handling multiple argv
- Note: Until I finalize handle multiple argv I won't consider any -commands completed, currently working on basic output with simple argv before transitioning into mutliple argv which will require me to use more of the functions below. Will have to rewrite how I parse flags and make it more of a toggle system where I check every argv due to how flags can be used in any order and mixed to do multiple results. Standardly, -a shows hidden files, -r reverses search, -1 is the default for our ls project, -R is recursive to check every directory, and -t orders by time. Because each of these flags affects eachother will write a switchboard toggling function that allows me to prioritize -1 first, -a will toggle hidden files to print in my print function, -r will cause the i value used to print to be reversed, -t and -R will be worked on separately. Bigger progress today, hopefully will have more time to flush out more.

New Functions Learning List:
- ~opendir (studied and used)~
- ~readdir (studied and used)~
- closedir (studied, not yet used)
- stat (studied, not yet used)
- lstat (studied, not yet used)
- getpwuid (did not study yet)
- getgrgid (did not study yet)
- listxattr (did not study yet)
- getxattr (did not study yet)
- time (studied, not yet used)
- ctime (studied, not yet used)
- readlink (did not study yet)
- perror (studied, not yet used)
- strerror (studied, not yet used)
