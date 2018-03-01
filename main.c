/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:35:12 by rnugroho          #+#    #+#             */
/*   Updated: 2018/03/01 01:11:42 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>
#include <float.h>

#include <stdio.h>
#include <string.h>
#include <locale.h>

#define LONG_MAX  __LONG_MAX__

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
			printf("\e[1;32m%s|%s|%d\e[0m\n",FMT, pf_dst, pf);					\
			printf("\e[1;32m%s|%s|%d\e[0m\n\n",FMT, ft_dst, ft);				\
		}																		\
	}

int		main(int ac, char **av)
{
	char	*pf_dst;
	char	*ft_dst;
	int		pf;
	int		ft;

	int i;
	double g;
	long double lg;
	i = 42;

	TEST("%s", "Hello World");
	TEST("%p", &i);
	TEST("%d", i);
	TEST("%%");

	TEST("%s %p %d", "Hello World", &i, i);

	setlocale(LC_ALL, "");
	TEST("%S", L"你好");
	TEST("%D", i);
	TEST("%i", i);
	TEST("%o", i);
	TEST("%O", i);
	TEST("%u", i * -1);
	TEST("%U", i * -1);
	TEST("%x", i);
	TEST("%X", i);
	TEST("%c", i);
	TEST("%C", L'你');

	TEST("%s %d %p %% %S %D %i %o %O %u %U %x %X %c %C","bonjour", i, &i, L"你好", LONG_MAX, i, i, i, 100000, ULONG_MAX, i, i, 'c', L'你');

	TEST("%#8d", i);
	TEST("%08d", i);
	TEST("%+#8d", i);
	TEST("%-08d", i);

	TEST("%d %hd", 32768, 32768);
	TEST("%d %hhd", 257, 257);
	TEST("%d %ld", LONG_MAX, LONG_MAX);
	TEST("%d %lld", LONG_MAX, LONG_MAX);
	TEST("%d %jd", 2147483648, 2147483648);

	TEST("%.5s", "Hello World");
	TEST("%.5d", i);
	TEST("%.5x", i);
	TEST("%.5o", i);
	TEST("%.5e", 42.0);
	TEST("%.5f", 42.0);
	TEST("%.5g", 0.000042);
	TEST("%.5g", 420000.0);
	TEST("%.5g", 99999.0);
	TEST("%.5a", 42.0);

	TEST("%E", 42.0);
	TEST("%F", 42.0);
	TEST("%G", 42.0);
	TEST("%A", 42.0);

	int a,b,c,d,e,f;
	ft_printf("12%n45%n78%n\n", &a, &b, &c);
	printf("12%n45%n78%n\n", &d, &e, &f);
	ft_printf("(Real,FT) (%i,%i) (%i,%i) (%i,%i)\n\n", d,a,e,b,f,c);

	TEST("%*.*f", 10, 3, 42.0);
	TEST("%1$d %1$x %1$o %2$e %2$f %2$g %2$g", 42, 42.0);
	TEST("%2$*1$d", 2, 1);
	TEST("%*d", 2, 1);

	setlocale(LC_NUMERIC, "");
	TEST("%f %'f", 10000000.0, 10000000.0);
	TEST("%d %'d", 10000000, 10000000);

	g = 42.0;
	lg = 42.0;
	TEST("%f %Lf", g, lg);
	TEST("%a %La", g, lg);

	ft_printfln("%6W|%s|%5w|%s|%4W|%s|%3w|%s|%2W|%s|%1w|%s|%w","H","E","L","L","O","W");
	ft_printfln("%b", 42);
	t_list *list;
	char	str[] = "Hello how are you doing ?";
	list = ft_strsplit_tolst(str,' ');
	ft_printfln("%r", list);
	ft_printfln("%*Q", 100, '-');
	long	date[6] = {
		16, 53, 06, 22, 11, 2015
	};
	ft_printfln("%*.*y", 1, 6, date);
	ft_printfln("%T", ft_datetoepoch(date));
	ft_printfln("%1T", ft_datetoepoch(date));
	ft_printfln("%2T", ft_datetoepoch(date));

	int	tabs[10] = {0, 23, 150, 255, 12, 16,  21, 42};
	long	tab[3][2] = {{1 , 2}, {3, 12324}, {5, 6}};
	ft_printfln("%*.*y", 3, 2, tab);

	ft_printf("%*m", sizeof(date), date);
	ft_printf("%*m", ft_strlen(str) + 5, str);

	ft_printfln("%q", 32300000000.0);	

	char *res;
	i = ft_asprintf(&res, "%s", "Hello World");
	ft_printfln("%s|%d", res, i);
	ft_printfln("%s|%d", ft_rasprintf(&i, "%s", "Hello World"), i);
	(void)ac;
	(void)av;
	return (0);
}
