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

#endif
