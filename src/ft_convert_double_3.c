/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_double_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 17:36:25 by rnugroho          #+#    #+#             */
/*   Updated: 2018/02/17 15:41:57 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_cv_ce(t_modifier *m, t_array *d, va_list ap)
{
	double	arg;

	arg = va_arg(ap, double);
	if (arg < 0)
		fta_append(d, "-", 1);
	else if (m->booleans.n.plus)
		fta_append(d, "+", 1);
	else if (m->booleans.n.space)
		fta_append(d, " ", 1);
	if (m->precision == -1)
		m->precision = 6;
	arg = ABS(arg);
	return (pf_signed_double_e(m, d, arg, "E"));
}

int		pf_cv_g(t_modifier *m, t_array *d, va_list ap)
{
	double	arg;

	arg = va_arg(ap, double);
	if (arg < 0)
		fta_append(d, "-", 1);
	else if (m->booleans.n.plus)
		fta_append(d, "+", 1);
	else if (m->booleans.n.space)
		fta_append(d, " ", 1);
	if (m->precision == -1)
		m->precision = 6;
	arg = ABS(arg);
	if (m->precision != 0)
		m->precision = m->precision - 1;
	return (pf_signed_double_g(m, d, arg, "e"));
}

int		pf_cv_cg(t_modifier *m, t_array *d, va_list ap)
{
	double	arg;

	arg = va_arg(ap, double);
	if (arg < 0)
		fta_append(d, "-", 1);
	else if (m->booleans.n.plus)
		fta_append(d, "+", 1);
	else if (m->booleans.n.space)
		fta_append(d, " ", 1);
	if (m->precision == -1)
		m->precision = 6;
	arg = ABS(arg);
	if (m->precision != 0)
		m->precision = m->precision - 1;
	return (pf_signed_double_g(m, d, arg, "E"));
}

int		pf_cv_a(t_modifier *m, t_array *d, va_list ap)
{
	double	arg;

	arg = va_arg(ap, double);
	if (arg < 0)
		fta_append(d, "-", 1);
	else if (m->booleans.n.plus)
		fta_append(d, "+", 1);
	else if (m->booleans.n.space)
		fta_append(d, " ", 1);
	fta_append(d, "0x", 2);
	if (m->precision == -1)
		m->precision = 13;
	arg = ABS(arg);
	return (pf_signed_double_a(m, d, arg, "p"));
}

int		pf_cv_ca(t_modifier *m, t_array *d, va_list ap)
{
	double	arg;

	arg = va_arg(ap, double);
	if (arg < 0)
		fta_append(d, "-", 1);
	else if (m->booleans.n.plus)
		fta_append(d, "+", 1);
	else if (m->booleans.n.space)
		fta_append(d, " ", 1);
	fta_append(d, "0X", 2);
	if (m->precision == -1)
		m->precision = 13;
	arg = ABS(arg);
	return (pf_signed_double_a(m, d, arg, "P"));
}
