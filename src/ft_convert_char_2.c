/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 17:12:14 by rnugroho          #+#    #+#             */
/*   Updated: 2018/02/07 17:14:41 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
