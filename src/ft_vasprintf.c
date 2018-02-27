/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 18:36:35 by rnugroho          #+#    #+#             */
/*   Updated: 2018/02/27 14:13:29 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char
	*pf_update_precision(char const *s, t_modifier *m, va_list ap, va_list dap)
{
	if (*s == '*')
	{
		m->precision = va_arg(dap, unsigned);
		return (s + 1);
	}
	m->precision = 0;
	while ('0' <= *s && *s <= '9')
		m->precision = 10 * (m->precision) + *s++ - '0';
	return (s);
}

static const char
	*pf_update_size(char const *s, t_modifier *m, va_list ap, va_list dap)
{
	if (*s == '*')
	{
		m->size = va_arg(dap, unsigned);
		s = s + 1;
	}
	else
	{
		m->size = 0;
		while ('0' <= *s && *s <= '9')
			m->size = 10 * (m->size) + *s++ - '0';
	}
	if (m->ndollar != 0)
		va_copy(ap, dap);
	return (s);
}

static void
	pf_set_length_modifier(char c, char *lm)
{
	if (c == 'h' && *lm == 'h')
		*lm = ft_toupper(c);
	else if (c == 'l' && *lm == 'l')
		*lm = '7';
	else if (*lm == 0 || !(c == 'h' && *lm != 'H'))
		*lm = c;
}

static const char
	*pf_match(char const *s, t_modifier *m, va_list ap, va_list dap)
{
	*m = NEW_MODIFIER;
	while (*(++s) != '\0')
	{
		if (*s == '.')
			s = pf_update_precision(s + 1, m, ap, dap) - 1;
		else if (*s == '\'')
			m->quote = 1;
		else if (*s == '$')
		{
			m->ndollar = m->size;
			m->size = 0;
			va_arg(dap, unsigned);
		}
		else if (('1' <= *s && *s <= '9') || *s == '*')
			s = pf_update_size(s, m, ap, dap) - 1;
		else if ((is_in(*s, FTPF_SWITCHES)) >= 0)
			m->booleans.t[is_in(*s, FTPF_SWITCHES)] = 1;
		else if (is_in(*s, FTPF_LM) >= 0)
			pf_set_length_modifier(*s, &(m->length));
		else if ((m->conversion = *s))
			return (s + 1);
	}
	return (s);
}

int
	ft_vasprintf(char **ret, char const *s, va_list ap, va_list dap)
{
	t_array		d;
	t_modifier	m;
	int			temp;

	d = NEW_ARRAY(char);
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s = pf_match(s, &m, ap, dap);
			if (m.conversion && pf_convert(&m, &d, ap, dap) == -1)
			{
				fta_resize(&d, temp);
				fta_trim(&d);
				*ret = d.data;
				d.size = 0;
				return (-1);
			}
			temp = d.size;
		}
		s = pf_next_specifier(s, &d);
	}
	fta_trim(&d);
	*ret = d.data;
	return (d.size - 1);
}
