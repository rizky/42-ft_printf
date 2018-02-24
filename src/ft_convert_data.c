/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 02:11:04 by rnugroho          #+#    #+#             */
/*   Updated: 2018/02/24 03:40:32 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int
	pf_cv_y(t_modifier *m, t_array *d, va_list ap)
{
	intmax_t	*arg;
	int			i;

	arg = va_arg(ap, intmax_t *);
	i = 0;
	fta_append(d, "[", 1);
	while (i < m->size)
	{
		if (i > 0)
			fta_append(d, ", ", 2);
		fta_append(d, ft_itoa(arg[i]), ft_strlen(ft_itoa(arg[i])));
		i++;
	}
	fta_append(d, "]", 1);
	return (1);
}

static
	pf_maxdigit(intmax_t *tab, int len)
{
	int	i;
	int max;

	i = 0;
	max = 0;
	while (i < len)
	{
		if (max < tab[i])
			max = tab[i];
		i++;
	}
	max = ft_strlen(ft_itoa(max));
	return (max);
}

int
	pf_cv_cy(t_modifier *m, t_array *d, va_list ap)
{
	intmax_t	*arg;
	int			i;
	int			j;
	int			c;
	char		*str;

	arg = va_arg(ap, intmax_t *);
	i = -1;
	c = -1;
	fta_append(d, "[", 1);
	while (++i < m->size)
	{
		j = -1;
		if (i > 0)
			fta_append(d, "\n ", 2);
		fta_append(d, "[", 1);
		while (++j < m->precision)
		{
			if (j > 0)
				fta_append(d, ", ", 2);
			ft_asprintf(&str, "%*d", pf_maxdigit(arg, m->size * m->precision),arg[++c]);
			fta_append(d, str, ft_strlen(str));
		}
		fta_append(d, "]", 1);
	}
	fta_append(d, "]", 1);
	return (1);
}

int
	pf_cv_r(t_modifier *m, t_array *d, va_list ap)
{
	t_list *arg;
	t_list *list;

	arg = va_arg(ap, t_list*);
	list = arg;
	while (list)
	{
		if (list != arg)
			fta_append(d, " -> ", 4);
		fta_append(d, "[", 1);
		fta_append(d, list->content, ft_strlen(list->content));
		fta_append(d, "]", 1);
		list = list->next;
	}
	return (1);
}