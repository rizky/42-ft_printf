#include "ft_printf.h"

double ft_modf(double x, double *iptr)
{
	union {double x; uint64_t n;} u = {x};
	uint64_t mask;
	int e;

	e = (int)(u.n>>52 & 0x7ff) - 0x3ff;

	/* no fractional part */
	if (e >= 52) {
		*iptr = x;
		if (e == 0x400 && u.n<<12 != 0) /* nan */
			return x;
		u.n &= (uint64_t)1<<63;
		return u.x;
	}

	/* no integral part*/
	if (e < 0) {
		u.n &= (uint64_t)1<<63;
		*iptr = u.x;
		return x;
	}

	mask = (uint64_t)-1>>12 >> e;
	if ((u.n & mask) == 0) {
		*iptr = x;
		u.n &= (uint64_t)1<<63;
		return u.x;
	}
	u.n &= ~mask;
	*iptr = u.x;
	return x - *iptr;
}

int ft_round(double x)
{
    if (x < 0.0)
        return (int)(x - 0.5);
    else
        return (int)(x + 0.5);
}

int		pf_rtoa(t_array *d, long double x, int b, int precision)
{
	double				frac;
	double				intg;
	int					ans;
	int					bp;

	ans = 1 + pf_itoa_base(d, (long long)x, b, 0);
	if (precision == 0)
		return (ans);
	fta_append(d, ".", 1);
	bp = 0;
	frac = ft_modf(x, &intg);
	while (bp < precision)
	{
		frac *= b;
		ans++;
		bp++;
	}
	frac = ft_round(frac);
	if (frac != 0)
	{
		pf_itoa_base(d, (long long)frac, b, 0);
	}
	else
	{
		bp = 0;
		while (bp < precision)
		{
			fta_append(d, "0", 1);
			bp++;
		}
	}
	return (ans);
}

int			pf_signed_double(t_modifier *m, t_array *d, va_list ap, int b)
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
	return (pf_rtoa(d, ABS(arg), b, m->precision));
}

int			pf_signed_double_e(t_modifier *m, t_array *d, va_list ap, char *c)
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

int			pf_signed_double_g(t_modifier *m, t_array *d, va_list ap, char *c)
{
	double	arg;
	int		ans;
	int		e;
	int		sig;
	int		mul;

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
	mul = 10;
	sig = 0;
	while (((int)(arg * mul) % 10) != 0)
	{
		sig++;
		mul = mul * 10;
	}
	if (m->precision != 0)
		m->precision = m->precision - 1;
	if (sig < m->precision)
		m->precision = sig;
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

int		pf_cv_f(t_modifier *m, t_array *d, va_list ap)
{
	return (pf_signed_double(m, d, ap, 10));
}

int		pf_cv_e(t_modifier *m, t_array *d, va_list ap)
{
	return (pf_signed_double_e(m, d, ap, "e"));
}

int		pf_cv_ce(t_modifier *m, t_array *d, va_list ap)
{
	return (pf_signed_double_e(m, d, ap, "E"));
}

int		pf_cv_g(t_modifier *m, t_array *d, va_list ap)
{
	return (pf_signed_double_g(m, d, ap, "e"));
}

int		pf_cv_cg(t_modifier *m, t_array *d, va_list ap)
{
	return (pf_signed_double_g(m, d, ap, "E"));
}