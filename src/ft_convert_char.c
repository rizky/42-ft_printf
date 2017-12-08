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

// int		pf_cv_ws(t_modifier *m, t_array *d, va_list ap)
// {
// 	wchar_t	*arg;
// 	size_t	len;

// 	arg = va_arg(ap, wchar_t *);
// 	if (arg == NULL)
// 		arg = L"(null)";
// 	fta_reserve(d, 4 * ft_wstrlen(arg));
// 	if (m->precision >= 0)
// 		len = ft_wstrnconv((char *)ARRAY_END(d), arg, m->precision);
// 	else
// 		len = ft_wstrconv((char *)ARRAY_END(d), arg);
// 	d->size += len;
// 	return (len);
// }

int		pf_cv_c(t_modifier *m, t_array *d, va_list ap)
{
	unsigned char	arg;

	(void)m;
	arg = (char)va_arg(ap, int);
	m->precision = -1;
	fta_append(d, (void *)&arg, 1);
	return (1);
}

// int		pf_cv_wc(t_modifier *m, t_array *d, va_list ap)
// {
// 	wint_t	arg;
// 	size_t	ans;

// 	(void)m;
// 	arg = va_arg(ap, wint_t);
// 	fta_reserve(d, 4);
// 	ans = ft_widetoa((char *)ARRAY_END(d), arg);
// 	d->size += ans;
// 	return ((int)ans);
// }

