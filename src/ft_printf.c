/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 18:35:59 by rnugroho          #+#    #+#             */
/*   Updated: 2018/02/07 16:22:22 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** _format_ is the string describing the expected output,
** the data being given through a unknown number
** of parameters following _format_.
** All those functions return the number of bytes written.
*/

/*
** Writes on the standard output.
*/

int		ft_printf(char const *format, ...)
{
	va_list		ap;
	int			ans;

	va_start(ap, format);
	ans = ft_vprintf(format, ap);
	va_end(ap);
	return (ans);
}

/*
** Allocates a string, writes into it, and returns it through _ret_
*/

int		ft_asprintf(char **ret, char const *format, ...)
{
	va_list		ap;
	int			ans;

	va_start(ap, format);
	ans = ft_vasprintf(ret, format, ap);
	va_end(ap);
	return (ans);
}