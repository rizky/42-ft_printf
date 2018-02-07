/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_double_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 17:36:25 by rnugroho          #+#    #+#             */
/*   Updated: 2018/02/07 17:39:58 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int		pf_cv_a(t_modifier *m, t_array *d, va_list ap)
{
	return (pf_signed_double_a(m, d, ap, "p"));
}

int		pf_cv_ca(t_modifier *m, t_array *d, va_list ap)
{
	return (pf_signed_double_a(m, d, ap, "P"));
}
