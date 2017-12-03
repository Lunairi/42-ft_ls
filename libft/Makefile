# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlu <marvin@student.42.fr>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/11 13:48:43 by mlu               #+#    #+#              #
#    Updated: 2017/06/13 12:45:09 by mlu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_find_next_prime.c ft_is_prime.c \
	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_numullen.c \
	ft_isprint.c ft_isspace.c ft_itoa.c ft_lstadd.c ft_putwstrf.c \
	ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
	ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_numlen.c \
	ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c ft_putendl.c \
	ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c ft_putstr.c \
	ft_sqrt.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c \
	ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_putld.c \
	ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_printf.c \
	ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
	ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
	ft_strrev.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
	ft_swap.c ft_tolower.c ft_toupper.c ft_strmcat.c ft_fdtostr.c \
	ft_strndup.c ft_strucmp.c ft_strnull.c ft_strerr.c ft_strput.c \
	ft_putoct.c ft_putunbr.c ft_puthex.c ft_putuhex.c flags_intj.c \
	ft_putstrf.c ft_putnbrf.c ft_numulen.c ft_putadr.c ft_putull.c \
	flags_adr.c flags_align.c flags_int.c flags_inth.c flags_zero.c \
	flags_inthh.c parse_flags.c parse_moreflags.c flags_palign.c \
	flags_spc.c flags_str.c flags_intl.c flags_intll.c flags_intz.c

OBJ = $(SRC:.c=.o)
HEADER = includes/

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c -I$(HEADER) $(SRC) -g
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all