/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:34:23 by rnugroho          #+#    #+#             */
/*   Updated: 2018/02/24 02:26:18 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int
	pf_print(t_modifier *m, t_array *d, va_list ap)
{
	int			i;
	char const	*c = "sSpdDioOuUxXcCbneEfFgGaAwWTyY";
	void *const	t[] = {
	&pf_cv_s, &pf_cv_ws, &pf_cv_p, &pf_cv_di, &pf_cv_di, &pf_cv_di,
	&pf_cv_o, &pf_cv_o, &pf_cv_u, &pf_cv_u, &pf_cv_x, &pf_cv_cx,
	&pf_cv_c, &pf_cv_wc, &pf_cv_b, &pf_cv_n, &pf_cv_e, &pf_cv_ce,
	&pf_cv_f, &pf_cv_cf, &pf_cv_g, &pf_cv_cg, &pf_cv_a, &pf_cv_ca,
	&pf_cv_w, &pf_cv_cw, &pf_cv_ct, pf_cv_y, pf_cv_cy};

	if (is_in(m->conversion, "DOU") >= 0)
		m->length = 'l';
	i = 0;
	while (c[i] != '\0' && m->conversion != c[i])
		i++;
	if (c[i] != '\0')
		return (((int (*)())t[i])(m, d, ap));
	fta_append(d, &m->conversion, 1);
	m->precision = -1;
	return (1);
}

static int
	pf_precision(t_modifier *m, t_array *d, va_list ap)
{
	size_t	before;
	size_t	after;
	int		width;
	int		len;

	before = d->size;
	width = pf_print(m, d, ap);
	if (width == -1)
		return (-1);
	after = d->size;
	len = width;
	if (len < m->precision && is_in(m->conversion, FTPF_NUMERIC) >= 0)
	{
		while (len < m->precision && ++len)
			fta_append(d, "0", 1);
		fta_swap(d, after - width, after);
	}
	if (m->size < 0 && m->precision == -1)
	{
		m->size = ABS(m->size);
		m->booleans.n.minus = 1;
	}
	return (len);
}

int
	pf_convert(t_modifier *m, t_array *d, va_list ap)
{
	size_t	before;
	size_t	after;
	int		width;
	int		len;

	before = d->size;
	width = pf_precision(m, d, ap);
	if (width == -1)
		return (-1);
	after = d->size;
	len = after - before;
	if (len <= m->size)
	{
		if (m->booleans.n.zero && m->precision <= -1 && !m->booleans.n.minus)
			while (len < m->size && ++len)
				fta_append(d, "0", 1);
		else
			while (len < m->size && ++len)
				fta_append(d, " ", 1);
		if (m->booleans.n.zero && m->precision <= -1 && !m->booleans.n.minus)
			before = after - width;
		if (!m->booleans.n.minus)
			fta_swap(d, before, after);
	}
	return (1);
}
