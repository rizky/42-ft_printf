/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 02:11:04 by rnugroho          #+#    #+#             */
/*   Updated: 2018/02/24 02:57:51 by rnugroho         ###   ########.fr       */
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

int
	pf_cv_cy(t_modifier *m, t_array *d, va_list ap)
{
	intmax_t	*arg;
	int			i;
	int			j;
	int			c;

	arg = va_arg(ap, intmax_t *);
	i = 0;
	c = 0;
	while (i < m->size)
	{
		j = 0;
		if (i > 0)
			fta_append(d, "\n", 1);
		fta_append(d, "[", 1);
		while (j < m->precision)
		{
			if (j > 0)
				fta_append(d, ", ", 2);
			fta_append(d, ft_itoa(arg[c]), ft_strlen(ft_itoa(arg[c])));
			j++;
			c++;
		}
		fta_append(d, "]", 1);
		i++;
	}
	return (1);
}