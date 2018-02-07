/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_numeric_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 16:54:20 by rnugroho          #+#    #+#             */
/*   Updated: 2018/02/07 16:54:59 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Writes an implementation defined character sequence defining a pointer.
*/

int
	pf_cv_p(t_modifier *m, t_array *d, va_list ap)
{
	(void)m;
	fta_append(d, "0x", 2);
	m->length = 'L';
	return (pf_unsigned_integer(m, d, ap, 16));
}

/*
** Converts a unsigned integer into octal representation oooo.
*/

int
	pf_cv_o(t_modifier *m, t_array *d, va_list ap)
{
	int alt;

	alt = 0;
	if (m->booleans.n.alternate)
	{
		fta_append(d, "0", 1);
		alt = 1;
	}
	return (pf_unsigned_integer(m, d, ap, 8) + alt);
}

/*
** Converts a unsigned integer into binary representation bbbb.
*/

int
	pf_cv_b(t_modifier *m, t_array *d, va_list ap)
{
	if (m->booleans.n.alternate)
		fta_append(d, "b", 1);
	return (pf_unsigned_integer(m, d, ap, 2));
}

/*
** returns the number of characters written so far by this call to the function.
*/

int
	pf_cv_n(t_modifier *m, t_array *d, va_list ap)
{
	int		*arg;

	arg = va_arg(ap, void *);
	if (!arg)
		return (-1);
	m->size = 0;
	m->precision = -1;
	if (m->length == 'H')
		*(char *)arg = (char)d->size;
	else if (m->length == 'h')
		*(short *)arg = (short)d->size;
	else if (m->length == 'l' || m->length == 'z')
		*(long *)arg = (long)d->size;
	else if (m->length == 'L')
		*(long long *)arg = (long long)d->size;
	else if (m->length == 'j')
		*(intmax_t *)arg = (intmax_t)d->size;
	else
		*(int *)arg = (int)d->size;
	return (0);
}
