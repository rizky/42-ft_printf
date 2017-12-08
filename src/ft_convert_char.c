#include "ft_printf.h"

int		pf_cv_s(t_modifier *m, t_array *d, va_list ap)
{
	char	*arg;
	int		ans;

	arg = va_arg(ap, char *);
	if (arg == NULL)
		arg = "(null)";
	ans = (m->precision >= 0 ? MIN(ft_strlen(arg), (size_t)m->precision)
		: ft_strlen(arg));
	fta_append(d, (void *)arg, ans);
	return (ans);
}

int		pf_cv_c(t_modifier *m, t_array *d, va_list ap)
{
	unsigned char	arg;

	(void)m;
	arg = (char)va_arg(ap, int);
	m->precision = -1;
	fta_append(d, (void *)&arg, 1);
	return (1);
}
