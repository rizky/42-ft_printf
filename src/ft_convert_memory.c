/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_memory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 16:40:45 by rnugroho          #+#    #+#             */
/*   Updated: 2018/02/25 16:51:47 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(int number, int rem, t_array *d)
{
	const char *base = "0123456789abcdef";

	if (rem > 1)
		ft_putnbr_hex(number / 16, rem - 1, d);
	fta_append(d, &(base[number % 16]), 1);
}

void	ft_putchar_dot(unsigned char const c, t_array *d)
{
	if (c >= ' ' && c <= '~')
		fta_append(d, &c, 1);
	else
		fta_append(d, ".", 1);
}

void	print_memory(const void *addr, size_t size, t_array *d)
{
	size_t	i;
	size_t	col;
	const unsigned char *ptr = addr;
	
	i = 0;
	while (i < size)
	{
		col = 0;
		while (col < 16 && col + i < size)
		{
			ft_putnbr_hex(*(ptr + i + col), 2, d);
			if (col % 2)
				fta_append(d, " ", 1);
			col++;
		}
		while (col < 16)
		{
			fta_append(d, "  ", 2);
			if (col % 2 == 0)
				fta_append(d, " ", 1);
			col++;
		}
		col = 0;
		while (col < 16 && col + i < size)
		{
			ft_putchar_dot(*(ptr + i + col), d);
			col++;
		}
		fta_append(d, "\n", 1);
		i = i + 16;
	}
}

int
	pf_cv_m(t_modifier *m, t_array *d, va_list ap)
{
	int		*arg;

	arg = va_arg(ap, int *);
	print_memory(arg, m->size, d);
	return (1);
}