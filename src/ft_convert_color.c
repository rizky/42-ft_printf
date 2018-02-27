/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 22:27:14 by rnugroho          #+#    #+#             */
/*   Updated: 2018/02/27 13:59:26 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int
	pf_cv_w(t_modifier *m, t_array *d, va_list ap)
{
	int		index;

	(void)ap;
	(void)m;
	index = m->size;
	m->size = 0;
	if (index > 6)
		index = 0;
	if (index != 0)
		index += 30;
	fta_append(d, "\e[", 2);
	fta_append(d, ft_itoa(index), ft_strlen(ft_itoa(index)));
	fta_append(d, "m", 1);
	return (1);
}

int
	pf_cv_cw(t_modifier *m, t_array *d, va_list ap)
{
	int		index;

	(void)ap;
	(void)m;
	index = m->size;
	m->size = 0;
	if (index > 6)
		index = 0;
	if (index != 0)
		index += 30;
	fta_append(d, "\e[", 2);
	fta_append(d, "1;", 2);
	fta_append(d, ft_itoa(index), ft_strlen(ft_itoa(index)));
	fta_append(d, "m", 1);
	return (1);
}
