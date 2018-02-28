/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:35:12 by rnugroho          #+#    #+#             */
/*   Updated: 2018/02/28 22:21:47 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>
#include <float.h>

#include <stdio.h>
#include <string.h>
#include <locale.h>

#define LONG_MAX  __LONG_MAX__

#define LONG_MIN  (-__LONG_MAX__ -1L)
#define ULONG_MAX (__LONG_MAX__ *2UL+1UL)

#define TEST(FMT,...)															\
	pf = asprintf(&pf_dst,FMT,##__VA_ARGS__);									\
	ft = ft_asprintf(&ft_dst,FMT,##__VA_ARGS__);								\
	if (ft != pf)																\
		dprintf(2, "Fail : return value Real(%i vs %i)Yours\n", pf, ft);		\
	if (pf >= 0 && ft >= 0) {													\
		if (strcmp(ft_dst, pf_dst))												\
			printf("%sFail : strings differ\n|%s| (Real) vs\n|%s| (Yours)\n%s",	\
					"\e[1;31m", pf_dst, ft_dst, "\e[0m");						\
		else																	\
		{																		\
			printf("\e[1;32m|%s|%d\e[0m\n", pf_dst, pf);								\
			printf("\e[1;32m|%s|%d\e[0m\n\n", ft_dst, ft);								\
		}																		\
	}

int		main(int ac, char **av)
{
	char	*pf_dst;
	char	*ft_dst;
	int		pf;
	int		ft;

	int i;
	i = 42;

	TEST("%f", FLT_MAX);

	// TEST("%%s: %s", "Hello World");
	// TEST("%%p: %p", &i);
	// TEST("%%d: %d", i);
	// TEST("%%");

	// TEST("%s %p %d", "Hello World", &i, i);

	// setlocale(LC_ALL, "");
	// TEST("%%S: %S", L"你好");
	// TEST("%%D: %D", i);
	// TEST("%%i: %i", i);
	// TEST("%%o: %o", i);
	// TEST("%%O: %O", i);
	// TEST("%%u: %u", i * -1);
	// TEST("%%U: %U", i * -1);
	// TEST("%%x: %x", i);
	// TEST("%%X: %X", i);
	// TEST("%%c: %c", i);
	// TEST("%%C: %C", L'你');

	// TEST("%s %d %p %% %S %D %i %o %O %u %U %x %X %c %C","bonjour", i, &i, L"你好", LONG_MAX, i, i, i, 100000, ULONG_MAX, i, i, 'c', L'你');

	// TEST("%#8d", i);
	// TEST("%08d", i);
	// TEST("%+#8d", i);
	// TEST("%-08d", i);

	// TEST("%d %hd", 32768, 32768);
	// TEST("%d %hhd", 257, 257);
	// TEST("%d %ld", LONG_MAX, LONG_MAX);
	// TEST("%d %lld", LONG_MAX, LONG_MAX);
	// TEST("%d %jd", 2147483648, 2147483648);

	// TEST("%.5s", "Hello World");
	// TEST("%.5d", i);
	// TEST("%.5x", i);
	// TEST("%.5o", i);
	// TEST("%.5e", 42.0);
	// TEST("%.5f", 42.0);
	// TEST("%.5g", 0.000042);
	// TEST("%.5g", 420000.0);
	// TEST("%.5g", 99999.0);
	// TEST("%.5a", 42.0);

	// TEST("%%E: %E", 42.0);
	// TEST("%%F: %F", 42.0);
	// TEST("%%G: %G", 42.0);
	// TEST("%%A: %A", 42.0);

	// TEST("%*.*f", 10, 3, 42.0);
	// TEST("%1$d %1$x %1$o %2$e %2$f %2$g %2$g", 42, 42.0);
	// TEST("%2$*1$d", 2, 1);
	// TEST("%*d", 2, 1);

	// TEST("%f %'f", 10000000.0, 10000000.0);

	// ft_printf("%6w|%s|%5w|%s|%4w|%s|%3w|%s|%2w|%s|%1w|%s|%w\n","Test","Test","Test","Test","Test","Test");
	
	// t_list *list;
	// list = ft_strsplit_tolst("Hello how are you doing",' ');
	// ft_printfln("%r", list);
	// ft_printfln("%*Q", 100, '-');
	// long	date[6] = {
	// 	16, 53, 06, 22, 11, 2015
	// };
	// ft_printfln("%*.*y", 1, 6, date);
	// int	tabs[10] = {0, 23, 150, 255, 12, 16,  21, 42};
	// ft_printf("%*m", sizeof(date), date);
	// long	tab[3][2] = {{1 , 2}, {3, 12324}, {5, 6}};
	// ft_printfln("%*.*y", 3, 2, tab);
	// long	tab2[6][6] = {{12324 , 2, 12324 , 2, 1 , 2}, {3, 12324, 5, 6 ,5, 6}, {5, 6, 5, 6, 5, 6},
	// 				{1 , 2, 1 , 2, 1 , 2}, {3, 12324, 5, 6 ,5, 6}, {5, 6, 5, 6, 5, 6}};
	// ft_printf("%*.*y\n", 6, 6, tab2);

	// ft_printf("%q\n", 32300000000.0);
	// printf("%d\n", ft_datetoepoch(date));
	// ft_printf("%T\n", ft_datetoepoch(date));
	// ft_printf("%1T\n", ft_datetoepoch(date));
	// ft_printf("%2T\n", ft_datetoepoch(date));	
	(void)ac;
	(void)av;
	return (0);
}
