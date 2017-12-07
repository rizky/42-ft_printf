/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:37:44 by angagnie          #+#    #+#             */
/*   Updated: 2017/09/22 21:02:32 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_cv_s(t_modifier *m, t_array *d, va_list ap)
{
	char	*arg;
	int		ans;

	arg = va_arg(ap, char *);
	if (arg == NULL)
		arg = "(null)";
	ans = (m->precision >= 0 ? MIN(ft_strlen(arg), (size_t)m->precision)
		: ft_strlen(arg));
	fta_append(d, (void *)arg, ans);
	return (ans);
}
