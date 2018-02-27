/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 18:36:14 by rnugroho          #+#    #+#             */
/*   Updated: 2018/02/27 14:42:42 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int
	ft_vprintf(char const *format, va_list ap)
{
	return (ft_vdprintf(1, format, ap));
}

int
	ft_vdprintf(int fd, char const *format, va_list ap)
{
	char		*str;
	int			ans;
	va_list		dap;

	va_copy(dap, ap);
	ans = ft_vasprintf(&str, format, ap, dap);
	if (ans == -1)
		write(fd, str, ft_strlen(str));
	else
		write(fd, str, ans);
	free(str);
	return (ans);
}

int
	pf_print_format(char const *s)
{
	ft_printf("%wFormat: %s\n", s);
	return (ft_strlen(s) + 1);
}

int
	ft_printf_format(char const *format, ...)
{
	va_list		ap;
	int			ans;

	va_start(ap, format);
	ans = pf_print_format(format);
	va_end(ap);
	return (ans);
}
