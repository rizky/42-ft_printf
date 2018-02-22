/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_double_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 17:37:10 by rnugroho          #+#    #+#             */
/*   Updated: 2018/02/22 01:16:43 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int
	pf_signed_double_e(t_modifier *m, t_array *d, long double arg, char *c)
{
	int		ans;
	int		e;

	e = 0;
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
	if (ABS(e) < 10)
		ans += fta_append(d, "0", 1);
	pf_itoa_base(d, e, 10, 0);
	return (ans);
}

static int
	pf_finde(long double *arg, int *ans, t_array *d, int e)
{
	if (*arg < 1 && *arg >= 0.0001)
		return (e);
	if (*arg > 0 && *arg < 1)
	{
		if (((int)((*arg) * 10) % 10) != 0)
		{
			*ans = fta_append(d, "0.", 2);
			*arg = *arg * 10;
		}
		else
		{
			while (*arg > 0 && *arg < 1)
			{
				*arg = *arg * 10;
				e--;
			}
		}
	}
	while (*arg > 9)
	{
		*arg = *arg / 10;
		e++;
	}
	return (e);
}

int
	pf_signed_double_g(t_modifier *m, t_array *d, long double arg, char *c)
{
	int		ans;
	int		e;

	e = 0;
	e = pf_finde(&arg, &ans, d, e);
	ans = pf_rtoa(d, ABS(arg), 10, m->precision);
	while (d->size > 1 && ((ARRAY_LAST(d))[0] == '0' || (ARRAY_LAST(d))[0] == '.'))
	{
		fta_popback(d, 1);
		ans--;
	}
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
	if (ABS(e) < 10)
		ans += fta_append(d, "0", 1);
	pf_itoa_base(d, e, 10, 0);
	return (ans);
}

static int
	pf_findp(long double *arg, int p)
{
	while (*arg > 0 && *arg < 1)
	{
		*arg = *arg * 2;
		p--;
	}
	while (*arg > 2)
	{
		*arg = *arg / 2;
		p++;
	}
	return (p);
}

int
	pf_signed_double_a(t_modifier *m, t_array *d, long double arg, char *c)
{
	int		ans;
	int		p;

	p = 0;
	p = pf_findp(&arg, p);
	if (*c == 'p')
		ans = pf_rtoa(d, ABS(arg), 16, m->precision);
	else
		ans = pf_rtoa(d, ABS(arg), -16, m->precision);
	while (d->size > 3 && ((ARRAY_LAST(d))[0] == '0' || (ARRAY_LAST(d))[0] == '.'))
	{
		fta_popback(d, 1);
		ans--;
	}
	ans += fta_append(d, c, 1);
	if (p >= 0)
		ans += fta_append(d, "+", 1);
	else
		ans += fta_append(d, "-", 1);
	pf_itoa_base(d, p, 10, 0);
	return (ans);
}
