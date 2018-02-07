/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_double_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:34:08 by rnugroho          #+#    #+#             */
/*   Updated: 2018/02/07 17:48:25 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static double
	ft_modf(double num)
{
	int		intpart;

	intpart = (int)num;
	return (num - intpart);
}

static long int
	ft_round_base(double x, int b)
{
	double half;

	half = ((double)b) / 10 / 2;
	if (x < 0.0)
		return (long int)(x - half);
	else
		return (long int)(x + half);
}

int
	pf_rtoa(t_array *d, long double x, int b, int precision)
{
	double			frac;
	double			intg;
	int				ans;
	int				bp;

	ans = 1 + pf_itoa_base(d, (long long)x, b, 0);
	if (precision == 0)
		return (ans);
	fta_append(d, ".", 1);
	bp = 0;
	frac = ft_modf(x);
	while (bp < precision)
	{
		frac *= b;
		if (frac < 1)
			fta_append(d, "0", 1);
		ans++;
		bp++;
	}
	frac = ft_round_base(frac, b);
	if (frac != 0)
		pf_itoa_base(d, (long long)frac, b, 0);
	return (ans);
}
