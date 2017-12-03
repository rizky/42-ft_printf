/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_legacy.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:50:45 by angagnie          #+#    #+#             */
/*   Updated: 2017/03/28 22:52:30 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "private_libft.h"

# include "ft_ctype.h"
# include "ft_array.h"
# include "ft_tree.h"
# include "ft_string_legacy.h"
# include "ft_string.h"
# include "ft_color.h"
# include "ft_list.h"
# include "get_next_line.h"

# include <stddef.h>

int		ft_atoi(const char *str);

void	ft_bzero(void *s, size_t n);

/*
** itoa_base :   NxN    ->  String
** |            (n,b)   |-> n expressed in base b
** -
** @return : An allocated null-termminated characters array.
** | If _value_ is strictly negative, the first character will be '-'.
** | If _base_ is not in [2;36], NULL is returned.
** -
** @param _value_ : the number to be expressed in base _base_
** @param _base_ : an integer that should be in range [2;36]
** -
*/

char	*ft_itoa_base(int n, int base);
char	*ft_itoa(int n);

void	*ft_memalloc(size_t size);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_memdel(void **ap);
void	*ft_memdup(void const *addr, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);

void	ft_print_memory(void const *addr, size_t size);

void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr(char const *s);
void	ft_putstr_fd(char const *s, int fd);

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size, size_t factor);
void	*ft_calloc(size_t count, size_t size);
void	ft_exit(char const *const fnc, char const *const str);
void	*ft_safe_calloc(size_t count, size_t size);

/*
** Numbers manipulation tools
*/

# define ABS(V) ((V) < 0 ? -(V) : (V))

# define MIN(...) CAT(_MIN,ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)
# define MAX(...) CAT(_MAX,ARG_COUNT(__VA_ARGS__))(__VA_ARGS__)

/*
** Miscellaneous tricks
*/

# define ARG_COUNT(...) _ARG_COUNT1(__VA_ARGS__)

# define FD_PUT(F,A) write(F, A, ft_strlen(A))
# define FT_PUT(A) FD_PUT(1, A)

# define TO_STR(M) _TO_STR(M)
# define CAT(A,B) _CAT(A,B)

# define TWICE(A) (A),(A)
# define THRICE(A) (A),(A),(A)
# define PPP __VA_ARGS__

/*
** Asserts
*/

# ifdef DISABLE_ASSERT
#  define ASSERT(B) (B)
# else
#  define ASSERT(B) (B ? 1 : FD_PUT(2, __FILE__ " @" TO_STR(__LINE__) " : " #B))
# endif

#endif
