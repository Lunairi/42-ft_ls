#* ************************************************************************** */
#*                                                                            */
#*    Makefile               _             _              :::      ::::::::   */
#*    By: mlu               | |           | |           :+:      :+:    :+:   */
#*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
#*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +#+  +:+       +#+        */
#*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +#+#+#+#+#+   +#+           */
#*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        #+#    #+#             */
#*          __/ | __/ | |                             ###   ########.fr       */
#*         |___/ |___/|_|                                                     */
#* ************************************************************************** */

#* I'm bad at makefiles, but I'm good at grilling eggplants

NAME	= ft_ls

SRC		= main.c multi.c single.c printsort.c utility.c printlong.c \
			long_process.c fd_utility.c fd_sort.c print_process.c \
			fd_sorting.c permissions.c
OBJ 	= $(addprefix ./objects/, $(SRC:.c=.o))
CFLAG	= -Wall -Wextra -Werror
IFLAG	= -I libft -I includes

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc $(CFLAG) -L libft -lft -I libft -I includes $^ -o $(NAME) -g
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Created ft_ls"

sanitize: $(OBJ)
	make -C libft/
	gcc -fsanitize=address $(CFLAG) -L libft -lft -I libft -I includes $^ -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Fsanitize ft_ls"

./objects/%.o: ./sources/%.c
	gcc $(IFLAG) -c $< -o $@

clean:
	make fclean -C libft/
	/bin/rm -f *.o
	/bin/rm -rf ./objects/*.o
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Cleaned ft_ls"

fclean: clean
	make fclean -C libft/
	/bin/rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fcleaned ft_ls"

re: fclean all

test: fclean sanitize

.PHONY: clean fclean re all test
