/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:33:58 by rnugroho          #+#    #+#             */
/*   Updated: 2018/02/09 20:15:25 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>

int
	pf_cv_s(t_modifier *m, t_array *d, va_list ap)
{
	char	*arg;
	int		ans;

	if (m->length == 'l')
		return (pf_cv_ws(m, d, ap));
	else
		arg = va_arg(ap, char *);
	if (arg == NULL)
		arg = "(null)";
	ans = (m->precision >= 0 ? MIN(ft_strlen(arg), (size_t)m->precision)
		: ft_strlen(arg));
	m->precision = -1;
	fta_append(d, (void *)arg, ans);
	return (ans);
}

int
	pf_cv_wc(t_modifier *m, t_array *d, va_list ap)
{
	wint_t	arg;
	size_t	ans;

	(void)m;
	arg = va_arg(ap, wint_t);
	m->precision = -1;
	fta_reserve(d, 4);
	ans = ft_widetoa((char *)ARRAY_END(d), arg);
	d->size += ans;
	return ((int)ans);
}

int
	pf_cv_ws(t_modifier *m, t_array *d, va_list ap)
{
	wchar_t	*arg;
	size_t	len;
	wchar_t	*ptr;

	arg = va_arg(ap, wchar_t *);
	if (arg == NULL)
		arg = L"(null)";
	ptr = arg;
	while (*ptr)
		ptr++;
	fta_reserve(d, 4 * (ptr - arg));
	if (m->precision >= 0)
		len = ft_wstrnconv((char *)ARRAY_END(d), arg, m->precision);
	else
		len = ft_wstrconv((char *)ARRAY_END(d), arg);
	m->precision = -1;
	d->size += len;
	return (len);
}

int
	pf_cv_c(t_modifier *m, t_array *d, va_list ap)
{
	unsigned char	arg;

	(void)m;
	if (m->length == 'l')
		return (pf_cv_wc(m, d, ap));
	else
		arg = (char)va_arg(ap, int);
	m->precision = -1;
	fta_append(d, (void *)&arg, 1);
	return (1);
}
