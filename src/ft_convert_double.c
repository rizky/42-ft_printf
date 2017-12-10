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

int		pf_rtoa(t_array *d, long double x, int b, int precision)
{
	double				frac;
	double				intg;
	int					ans;
	int					bp;

	ans = 1 + pf_itoa_base(d, (long long)x, b, 0);
	fta_append(d, ".", 1);
	bp = 0;
	frac = ft_modf(x, &intg);
	while (bp < precision)
	{
		frac *= b;
		ans++;
		bp++;
	}
	if (frac != 0)
	{
		frac = (int)(frac * 100 + 0.5) / 100.0;
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

int			pf_signed_double_e(t_modifier *m, t_array *d, va_list ap, int b)
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
	if (arg == 0 && m->precision == 0)
		return (0);
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
	ans = pf_rtoa(d, ABS(arg), b, m->precision);
	ans += fta_append(d, "e", 1);
	if (e > 0)
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
	return (pf_signed_double_e(m, d, ap, 10));
}