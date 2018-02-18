/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 18:36:26 by rnugroho          #+#    #+#             */
/*   Updated: 2018/02/18 17:15:05 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define FTPF_CV "sSpdDioOuUxXcCbn"
# define FTPF_NUMERIC "diouDOUxXpb"
# define FTPF_LM "hljzL"
# define FTPF_SWITCHES "0+- #_"
# define NEW_MODIFIER (t_modifier){{{0, 0, 0, 0, 0, 0}}, 0, 0, 0, -1};

typedef struct		s_modifier
{
	union
	{
		char		t[6];
		struct
		{
			char	zero;
			char	plus;
			char	minus;
			char	space;
			char	alternate;
			char	underscore;
		}			n;
	}				booleans;
	char			conversion;
	char			length;
	int				size;
	int				precision;
}					t_modifier;

int					ft_printf(char const *format, ...);
int					ft_dprintf(int fd, char const *format, ...);
int					ft_asprintf(char **ret, char const *format, ...);
int					ft_sprintf(char *s, char const *format, ...);
int					ft_snprintf(char *s, size_t size, char const *format, ...);

int					ft_vprintf(char const *format, va_list ap);
int					ft_vdprintf(int fd, char const *format, va_list ap);
int					ft_vasprintf(char **ret, char const *s, va_list ap);
int					ft_vsprintf(char *s, char const *format, va_list ap);
int					ft_vsnprintf(char *s, size_t size,
					char const *format, va_list ap);

int					pf_convert(t_modifier *m, t_array *d, va_list ap);

int					pf_unsigned_integer(t_modifier *m,
					t_array *d, va_list ap, int b);
int					pf_signed_integer(t_modifier *m,
					t_array *d, va_list ap, int b);

int					pf_itoa_base(t_array *d, intmax_t n, int b, char info);
int					pf_rtoa(t_array *d, long double x, int b, int precision);
int					pf_signed_double_e(t_modifier *m,
					t_array *d, double arg, char *c);
int					pf_signed_double_g(t_modifier *m,
					t_array *d, double arg, char *c);
int					pf_signed_double_a(t_modifier *m,
					t_array *d, double arg, char *c);

int					pf_cv_s(t_modifier *m, t_array *d, va_list ap);
int					pf_cv_ws(t_modifier *m, t_array *d, va_list ap);
int					pf_cv_p(t_modifier *m, t_array *d, va_list ap);
int					pf_cv_di(t_modifier *m, t_array *d, va_list ap);
int					pf_cv_u(t_modifier *m, t_array *d, va_list ap);
int					pf_cv_x(t_modifier *m, t_array *d, va_list ap);
int					pf_cv_cx(t_modifier *m, t_array *d, va_list ap);
int					pf_cv_o(t_modifier *m, t_array *d, va_list ap);
int					pf_cv_c(t_modifier *m, t_array *d, va_list ap);
int					pf_cv_wc(t_modifier *m, t_array *d, va_list ap);

int					pf_cv_b(t_modifier *m, t_array *d, va_list ap);
int					pf_cv_n(t_modifier *m, t_array *d, va_list ap);

int					pf_cv_f(t_modifier *m, t_array *d, va_list ap);
int					pf_cv_e(t_modifier *m, t_array *d, va_list ap);
int					pf_cv_ce(t_modifier *m, t_array *d, va_list ap);
int					pf_cv_g(t_modifier *m, t_array *d, va_list ap);
int					pf_cv_cg(t_modifier *m, t_array *d, va_list ap);
int					pf_cv_a(t_modifier *m, t_array *d, va_list ap);
int					pf_cv_ca(t_modifier *m, t_array *d, va_list ap);
size_t				ft_wstrnconv(char *buff, const wchar_t *wstr, size_t n);
size_t				ft_wstrconv(char *buff, const wchar_t *wstr);
#endif
