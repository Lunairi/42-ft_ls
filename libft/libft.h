/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 13:48:43 by mlu               #+#    #+#             */
/*   Updated: 2017/06/21 12:07:12 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>
# include <math.h>
# include <stdarg.h>
# include <stdint.h>
# include <inttypes.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_putchar(char c);
int					ft_strnull(char *str);
int					ft_strput(char *str);
int					ft_strerr(char *str);
void				ft_putstr(char const *str);
void				ft_putendl(char const *str);
void				ft_putnbr(int nbr);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_itoa(int n);
int					ft_atoi(const char *str);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *restrict src,
						int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big,
						const char *little, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *n);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_strrev(char *str);
void				ft_swap(int *a, int *b);
int					ft_is_prime(int nb);
int					ft_is_prime(int nb);
int					ft_sqrt(int nb);
int					ft_isspace(int c);
size_t				ft_numlen(int n);
char				*ft_strndup(const char *s1, size_t n);
void				ft_strmcat(char *s1, char *s2,
						unsigned int *size, unsigned int buf);
char				*ft_fdtostr(int fd);
int					ft_strucmp(const char *s1, const char *s2);

/*
** printf helper ft functions
*/

void				ft_putoct(unsigned int n, int *p);
void				ft_putunbr(unsigned int n, int *p);
void				ft_puthex(unsigned int n, int *p);
void				ft_putuhex(unsigned int n, int *p);
void				ft_putstrf(char const *s, int *p);
void				ft_putnbrf(int n, int *p);
size_t				ft_numulen(unsigned int n);
void				ft_putadr(unsigned long n, int *p);
void				ft_putull(unsigned long long n, int *p);
void				ft_putld(long n, int *p);
void				ft_putwstrf(wchar_t *s, int *p);
unsigned long long	ft_numullen(unsigned long long n);

/*
** printf functions in printf folder
*/

/*
** ft_printf.c
*/
int					ft_printf(const char *str, ...);

/*
** parse_flags.c
*/
void				parse_flags(int *i, const char *str, va_list args, int *p);

/*
** parse_moreflags.c
*/
void				parse_j(va_list args, int *p, const char *str, int *i);
void				parse_z(va_list args, int *p, const char *str, int *i);
void				parse_l(va_list args, int *p, const char *str, int *i);
void				parse_ll(va_list args, int *p, const char *str, int *i);

/*
** flags_align.c
*/
void				parse_rightalign(int *i,
						const char *str, va_list args, int *p);
void				parse_leftalign(int *i,
						const char *str, va_list args, int *p);

/*
** flags_palign.c
*/
void				parse_rightpalign(int *i,
						const char *str, va_list args, int *p);
void				parse_leftpalign(int *i,
						const char *str, va_list args, int *p);

/*
** flags_zero.c
*/
void				parse_zero(int *i, const char *str, va_list args, int *p);
void				parse_pzero(int *i, const char *str, va_list args, int *p);

/*
** flags_int.c
*/
void				flags_int(va_list args, int *p);
void				flags_oct(va_list args, int *p);
void				flags_uint(va_list args, int *p);
void				flags_hex(va_list args, int *p);
void				flags_uhex(va_list args, int *p);

/*
** flags_inth.c
*/
void				flags_inth(va_list args, int *p);
void				flags_octh(va_list args, int *p);
void				flags_uinth(va_list args, int *p);
void				flags_hexh(va_list args, int *p);
void				flags_uhexh(va_list args, int *p);

/*
** flags_inthh.c
*/
void				flags_inthh(va_list args, int *p);
void				flags_octhh(va_list args, int *p);
void				flags_uinthh(va_list args, int *p);
void				flags_hexhh(va_list args, int *p);
void				flags_uhexhh(va_list args, int *p);

/*
** flags_intl.c
*/
void				flags_intl(va_list args, int *p);
void				flags_octl(va_list args, int *p);
void				flags_uintl(va_list args, int *p);
void				flags_hexl(va_list args, int *p);
void				flags_uhexl(va_list args, int *p);

/*
** flags_intll.c
*/
void				flags_intll(va_list args, int *p);
void				flags_octll(va_list args, int *p);
void				flags_uintll(va_list args, int *p);
void				flags_hexll(va_list args, int *p);
void				flags_uhexll(va_list args, int *p);

/*
** flags_intj.c
*/
void				flags_intj(va_list args, int *p);
void				flags_octj(va_list args, int *p);
void				flags_uintj(va_list args, int *p);
void				flags_hexj(va_list args, int *p);
void				flags_uhexj(va_list args, int *p);

/*
** flags_intz.c
*/
void				flags_intz(va_list args, int *p);
void				flags_octz(va_list args, int *p);
void				flags_uintz(va_list args, int *p);
void				flags_hexz(va_list args, int *p);
void				flags_uhexz(va_list args, int *p);

/*
** flags_adr.c
*/
void				flags_adr(va_list args, int *p);
void				flags_per(int *p);

/*
** flags_str.c
*/
void				flags_str(va_list args, int *p);
void				flags_char(va_list args, int *p);
void				flags_wchar(va_list args, int *p, const char *str, int *i);

/*
** flags_spc.
*/
void				flags_ws(va_list args, int *p, const char *str, int *i);
void				flags_plus(va_list args, int *p, const char *str, int *i);
void				flags_hash(va_list args, int *p, const char *str, int *i);

#endif
