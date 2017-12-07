/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 18:36:26 by rnugroho          #+#    #+#             */
/*   Updated: 2017/12/03 18:36:27 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define FTPF_CV "diouxXDOUeEfFgGaAcCsSpnb"
# define FTPF_NUMERIC "diouDOUxXpb"
# define FTPF_LM "hljzL"
# define FTPF_SWITCHES "0+- #_"

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

# define NEW_MODIFIER (t_modifier){{{0, 0, 0, 0, 0, 0}}, 0, 0, -1, -1};

int		ft_printf(char const *format, ...);
int		ft_dprintf(int fd, char const *format, ...);
int		ft_asprintf(char **ret, char const *format, ...);
int		ft_sprintf(char *s, char const *format, ...);
int		ft_snprintf(char *s, size_t size, char const *format, ...);

int		ft_vprintf(char const *format, va_list ap);
int		ft_vdprintf(int fd, char const *format, va_list ap);
int		ft_vasprintf(char **ret, char const *s, va_list ap);
int		ft_vsprintf(char *s, char const *format, va_list ap);
int		ft_vsnprintf(char *s, size_t size, char const *format, va_list ap);

void	pf_convert(t_modifier *m, t_array *d, va_list ap);

int		pf_unsigned_integer(t_modifier *m, t_array *d, va_list ap, int b);
int		pf_signed_integer(t_modifier *m, t_array *d, va_list ap, int b);

int		pf_cv_di(t_modifier *m, t_array *d, va_list ap);
int		pf_cv_s(t_modifier *m, t_array *d, va_list ap);
int		pf_cv_ws(t_modifier *m, t_array *d, va_list ap);

#endif
