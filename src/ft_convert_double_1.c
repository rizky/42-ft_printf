/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_double_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:34:08 by rnugroho          #+#    #+#             */
/*   Updated: 2018/02/17 16:41:09 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Return the fraction of the parameter num
*/

static double
	ft_modf(double num)
{
	long int		intpart;

	intpart = (long int)num;
	return (num - intpart);
}

/*
** Round value base on the base @param b
*/

static long int
	ft_round_base(double x, int b)
{
	double half;

	half = ((double)b) / 10 / 2;
	return (long int)(x + half);
}

int
	pf_rtoa(t_array *d, long double x, int b, int precision)
{
	double			frac;
	int				ans;
	int				bp;

	ans = 1 + pf_itoa_base(d, (long long)x, ABS(b), 2 | (b < 0));
	if (precision == 0)
		return (ans);
	fta_append(d, ".", 1);
	bp = 0;
	frac = ft_modf(x);
	while (bp < precision)
	{
		frac *= ABS(b);
		if (frac < 1)
			fta_append(d, "0", 1);
		ans++;
		bp++;
	}
	if (ABS(b) == 10)
		frac = ft_round_base(frac, ABS(b));
	if (frac != 0)
		pf_itoa_base(d, (long long)frac, ABS(b), 2 | (b < 0));
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
	return (pf_signed_double_e(m, d, arg, "e"));
}
