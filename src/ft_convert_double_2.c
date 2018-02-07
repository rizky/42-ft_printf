/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_double_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 17:37:10 by rnugroho          #+#    #+#             */
/*   Updated: 2018/02/07 17:41:34 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int
	pf_signed_double_e(t_modifier *m, t_array *d, va_list ap, char *c)
{
	double	arg;
	int		ans;
	int		e;

	arg = va_arg(ap, double);
	if (arg < 0)
		fta_append(d, "-", 1);
	else if (m->booleans.n.plus)
		fta_append(d, "+", 1);
	else if (m->booleans.n.space)
		fta_append(d, " ", 1);
	if (m->precision == -1)
		m->precision = 6;
	e = 0;
	arg = ABS(arg);
	while (arg > 0 && arg < 1)
	{
		arg = arg * 10;
		e--;
	}
	while (arg > 9)
	{
		arg = arg / 10;
		e++;
	}
	ans = pf_rtoa(d, ABS(arg), 10, m->precision);
	ans += fta_append(d, c, 1);
	if (e >= 0)
		ans += fta_append(d, "+", 1);
	else
		ans += fta_append(d, "-", 1);
	if (e < 10)
		ans += fta_append(d, "0", 1);
	pf_itoa_base(d, e, 10, 0);
	return (ans);
}

int
	pf_signed_double_g(t_modifier *m, t_array *d, va_list ap, char *c)
{
	double	arg;
	int		ans;
	int		e;

	arg = va_arg(ap, double);
	if (arg < 0)
		fta_append(d, "-", 1);
	else if (m->booleans.n.plus)
		fta_append(d, "+", 1);
	else if (m->booleans.n.space)
		fta_append(d, " ", 1);
	if (m->precision == -1)
		m->precision = 6;
	e = 0;
	arg = ABS(arg);
	if (arg > 0 && arg < 1)
	{
		if (((int)(arg * 10) % 10) != 0)
		{
			ans = fta_append(d, "0.", 2);
			arg = arg * 10;
		}
		else
		{
			while (arg > 0 && arg < 1)
			{
				arg = arg * 10;
				e--;
			}
		}
	}
	while (arg > 9)
	{
		arg = arg / 10;
		e++;
	}
	if (m->precision != 0)
		m->precision = m->precision - 1;
	ans = pf_rtoa(d, ABS(arg), 10, m->precision);
	if (e == 0)
	{
		m->precision = -1;
		return (ans);
	}
	ans += fta_append(d, c, 1);
	if (e >= 0)
		ans += fta_append(d, "+", 1);
	else
		ans += fta_append(d, "-", 1);
	if (e < 10)
		ans += fta_append(d, "0", 1);
	pf_itoa_base(d, e, 10, 0);
	return (ans);
}

int
	pf_signed_double_a(t_modifier *m, t_array *d, va_list ap, char *c)
{
	double	arg;
	int		ans;
	int		e;

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
	e = 0;
	arg = ABS(arg);
	while (arg > 0 && arg < 1)
	{
		arg = arg * 2;
		e--;
	}
	while (arg > 2)
	{
		arg = arg / 2;
		e++;
	}
	ans = pf_rtoa(d, ABS(arg), 16, m->precision);
	ans += fta_append(d, c, 1);
	if (e >= 0)
		ans += fta_append(d, "+", 1);
	else
		ans += fta_append(d, "-", 1);
	pf_itoa_base(d, e, 10, 0);
	return (ans);
}

int
	pf_cv_f(t_modifier *m, t_array *d, va_list ap)
{
	double	arg;

	arg = va_arg(ap, double);
	if (arg < 0)
		fta_append(d, "-", 1);
	else if (m->booleans.n.plus)
		fta_append(d, "+", 1);
	else if (m->booleans.n.space)
		fta_append(d, " ", 1);
	if (arg == 0 && m->precision == 0)
		return (0);
	if (m->precision == -1)
		m->precision = 6;
	return (pf_rtoa(d, ABS(arg), 10, m->precision));
}

int
	pf_cv_e(t_modifier *m, t_array *d, va_list ap)
{
	return (pf_signed_double_e(m, d, ap, "e"));
}
