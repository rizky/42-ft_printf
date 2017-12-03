#include "ft_printf.h"

int		ft_vprintf(char const *format, va_list ap)
{
	return (ft_vdprintf(1, format, ap));
}

int		ft_vdprintf(int fd, char const *format, va_list ap)
{
	char		*str;
	int			ans;

	ans = ft_vasprintf(&str, format, ap);
	write(fd, str, ans);
	free(str);
	return (ans);
}
