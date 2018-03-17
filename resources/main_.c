/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:35:12 by rnugroho          #+#    #+#             */
/*   Updated: 2018/02/28 19:35:23 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>

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
			printf("\e[1;32m|%s|\e[0m\n", ft_dst);								\
		}																		\
	}

int		main(int ac, char **av)
{
	char	*pf_dst;
	char	*ft_dst;
	int		pf;
	int		ft;
	double 	x = 3.14;
	wchar_t	s[4];

	t_list *list;

	TEST("%*d", 2, 1);
	TEST("%2$*1$d", 2, 1);
	ft_printfln("%*Q", 100, '-');
	TEST("%*d %*d", 6, 5, 4, 3, 2, 1);	
	TEST("%2$d %2$d", 6, 5, 4, 3, 2, 1);	

	TEST("%*d", 6, 5, 4, 3, 2, 1);
	TEST("%*5d", 6, 5, 4, 3, 2, 1);
	TEST("%2$*6$d", 6, 5, 4, 3, 2, 1);
	TEST("%*d", 2, 1);
	TEST("%2$*1$d", 2, 3);
	TEST("%2$d", 5, 4, 3, 2, 1);	

	TEST("%2$5d", 5, 4, 3, 2, 1);
	TEST("%2$5.8d", 5, 4, 3, 2, 1);
	TEST("%2$d %3$d %d %5$d", 1, 2, 3 ,4 ,5, 6);
	TEST("%2$d %3$s %d %5$d", 1, 2, "Hello" ,4 ,5, 6);
	TEST("%d %3$s %d %5$d", 1, 2, "Hello" ,4 ,5, 6);
	TEST("%1$d %1$u %1$d %1$x", 152);
	TEST("%1$f %1$F %1$g %1$a", 0.2);
	TEST("16-Bonus _%-2147483648.99h+08h#.04i_", '*');

	list = ft_strsplit_tolst("Hello how are you doing",' ');
	ft_printfln("%r", list);

	long	date[6] = {
		16, 53, 06, 22, 11, 2015
	};
	ft_printfln("%*.*y", 1, 6, date);
	int	tabs[10] = {0, 23, 150, 255, 12, 16,  21, 42};
	ft_printf("%*m", sizeof(date), date);
	long	tab[3][2] = {{1 , 2}, {3, 12324}, {5, 6}};
	ft_printfln("%*.*y", 3, 2, tab);

	ft_printfln("%*R", 10, '-');
	long	tab2[6][6] = {{12324 , 2, 12324 , 2, 1 , 2}, {3, 12324, 5, 6 ,5, 6}, {5, 6, 5, 6, 5, 6},
					{1 , 2, 1 , 2, 1 , 2}, {3, 12324, 5, 6 ,5, 6}, {5, 6, 5, 6, 5, 6}};
	ft_printf("%*.*y\n", 6, 6, tab2);

	ft_printf("%q\n", 32300000000000000.0);
	printf("%d\n", ft_datetoepoch(date));
	ft_printf("%T\n", ft_datetoepoch(date));
	ft_printf("%1T\n", ft_datetoepoch(date));
	ft_printf("%2T\n", ft_datetoepoch(date));

	setlocale(LC_NUMERIC, "");
	TEST("%20.'d", 1000000);
	TEST("%20.'u", -1000000);
	TEST("%20.d", 1000000);
	TEST("%20.u", -1000000);
	TEST("%20'f", 24564564.333);
	TEST("%20f", 24564564.333);
	TEST("%C", 0x6f);
	TEST("%C", 0x11ffff);
	TEST("%C", (wint_t)-2);
	TEST("%C", 0xd800);
	TEST("%C", 0xdb02);
	TEST("%C", 0xdfff);
	TEST("%C", 0xbffe);
	TEST("%lc", 253);
	TEST("%C", 256);
	TEST("%-1C", 2250);

	TEST("%8C et coco %C titi %lc", 3250, 0x11ffff, 'a');
	TEST("%---8C et coco %1C titi", 3250, 0xffff);
	TEST("%6C et coco %C titi %C tyty", 3250, 0xd800, 'u');
	printf("yo%2C%-12lc et %C titi %C tyty\n", 'u', 254, 256, 'a');
	ft_printf("yo%2C%-12lc et %C titi %C tyty\n", 'u', 254, 256, 'a');
	printf("yo%2C%-12lc et %C titi %C tyty\n", 'u', 254, 256, 'a');

	// setlocale(LC_ALL, "");
	s[0] = 0x53;
	s[1] = 0x3abc;
	s[2] = 0x81000;
	s[3] = '\0';
	TEST("%S", s);

	s[0] = 0x53;
	s[1] = 0xd800;
	s[2] = 0x81000;
	s[3] = '\0';
	TEST("%S", s);

	s[0] = 'a';
	s[1] = 254;
	s[2] = 'b';
	s[3] = '\0';
	TEST("%S", s);

	s[0] = 254;
	s[1] = 256;
	s[2] = 'b';
	s[3] = '\0';
	TEST("%S", s);

	s[0] = 0x53;
	s[1] = 0x3abc;
	s[2] = 0x81000;
	s[3] = '\0';
	TEST("%.5ls", s);

	s[0] = 'S';
	s[1] = 254;
	s[2] = 'u';
	s[3] = '\0';
	TEST("%.2ls", s);

	ft_printf("\e[36m|%s|\e[0m\n", "Test");

	ft_printf("%1z|%s|%z\n","Test");

	ft_printf("%w|%s|%w\n","Test");
	ft_printf("%1w|%s|%w\n","Test");
	ft_printf("%2w|%s|%w\n","Test");
	ft_printf("%3w|%s|%w\n","Test");
	ft_printf("%4w|%s|%w\n","Test");
	ft_printf("%5w|%s|%w\n","Test");
	ft_printf("%6w|%s|%w\n","Test");

	ft_printf("%6w|%s|%5w|%s|%4w|%s|%3w|%s|%2w|%s|%1w|%s|%w\n","Test","Test","Test","Test","Test","Test");
	
	ft_printf("%0W|%s|%w\n","Test");
	ft_printf("%1W|%s|%w\n","Test");
	ft_printf("%2W|%s|%w\n","Test");
	ft_printf("%3W|%s|%w\n","Test");
	ft_printf("%4W|%s|%w\n","Test");
	ft_printf("%5W|%s|%w\n","Test");
	ft_printf("%6W|%s|%w\n","Test");
	s[0] = 'a';
	s[1] = 250;
	s[2] = 'b';
	s[3] = '\0';
	TEST("%-4S", s);

	s[0] = 'a';
	s[1] = 256;
	s[2] = 'b';
	s[3] = '\0';
	TEST("%9ls", s);

	s[0] = 0x53;
	s[1] = 0x3abc;
	s[2] = 0x81000;
	s[3] = '\0';
	TEST("%9.6ls %S", s, (wchar_t *)'a');

	char *ret;
	ft_asprintf(&ret, "%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256);
	ft_printf("%s\n", ret);

	TEST("%#16zO", 0);
	TEST("%#16zo", 0);
	TEST("1-Simple String.", 0);
	TEST("2-Stringception _%s_", "Hello World");
	TEST("3-Stringception _%20s_", "Hello World");
	TEST("4-Stringception _%-20s_", "Hello World");
	TEST("5-Stringception _%20.5s_", "Hello World");
	TEST("6-Stringception _%-20.5s_", "Hello World");
	TEST("7-Stringception _%020s_", "Hello World");
	TEST("8-Stringception _%0-.20s_", "Hello World");
	TEST("9-Stringception _%20s_", "Hello World");
	TEST("10-NULL string _%s_", NULL);
	TEST("11-NULL string _%4s_", NULL);
	TEST("12-NULL string _%.4s_", NULL);
	TEST("13-NULL string _%S_", NULL);
	TEST("14-NULL string _%4S_", NULL);
	TEST("15-NULL string _%l.4s_", NULL);
	
	TEST("16-Bonus _%-2147483648.99h+08h#.04i_", '*');
	TEST("17-Nothing _%20.10",0);
	TEST("18-Nothing _%20.10__%i",0,42);
	TEST("19-Nothing _%20.10&_",0);
	TEST("1A-Nothing _%20.10@_",0);
	TEST("1B-Nothing _%20.10`_",0);
	TEST("1C-Nothing _%20.10%_",0);
	TEST("1D-Number _%015#X_", 0xDEADBEEF);
	TEST("1E-Zero _%+i_", 0);
	TEST("1F-Zero _%0+i_", 0);
	TEST("1G-Zero _%.0+i_", 0);
	TEST("1H-Zero _%.0+u_", 0);
	TEST("1I-Zero _%10.0i_", 0);
	TEST("1J-Zero _%10.0+u_", 0);
	TEST("1K-Zero _%-10.0+i_", 0);
	TEST("1L-Advanced _%i_%10i_%.5i_%10.5i_%010i_%.0i_",-42,-42,-42,-42,-42,0);
	TEST("1M-Advanced _%u_%10u_%.5u_%10.5u_%010u_%.0u_",-42,-42,-42,-42,-42,0);
	TEST("1N-Advanced _%#x_%10#x_%.5#x_%10.5#x_%010#x_%.0#x_",-42,-42,-42,-42,-42,0);
	TEST("1O-Advanced _%#X_%10#X_%.5#X_%10.5#X_%010#X_%.0#X_",-42,-42,-42,-42,-42,0);
	TEST("1P-Advanced _%#o_%10#o_%.5#o_%10.5#o_%010#o_%.0#o_",-42,-42,-42,-42,-42,0);
	TEST("1Q-%", 0);
	TEST("1R-%.0z", 0);
	TEST("1S-Zero _%010.0+#o_", 0);
	TEST("1T-Advanced _%#p_%10#p_%.5#p_%10.5#p_%010#p_",-42,-42,-42,-42,-42);
	TEST("1U-Zero %#x", 0);
	TEST("1V-Zero %#.x %#.0x", 0, 0);
	TEST("1W-Wide char %C", 0x0065);
	TEST("1X-Hexa a%xb%xc%xd", 0, 55555, 1000000);
	TEST("1Y-Hexa a%Xb%Xc%Xd", 0, 55555, 1000000);
	TEST("1Z-Octal a%ob%oc%od", 0, 55555, 1000000);
	TEST("20-Octal _%o_%#o_%0o_%0#o_%.0o_%.0#o_%0.0o_%0.0#o_", 0, 0, 0, 0, 0, 0, 0, 0);
	TEST("21-Pointers _%p_%#p_%0p_%0#p_%.0p_%.0#p_%0.0p_%0.0#p_", 0, 0, 0, 0, 0, 0, 0, 0);
	TEST("22-Pointers _%p_%#p_%0p_%0#p_%.0p_%.0#p_%0.0p_%0.0#p_", -42, -42, -42, -42, -42, -42, -42, -42);
	TEST("23-Wildcard _%*s_%*s_", 5, "Hello world", 50, "Hello world");
	TEST("24-Wildcard _%.*s_%.*s_", 5, "Hello world", 50, "Hello world");
	TEST("25-Wildcard _%*.*s_%*.*s_", 5, 5, "Hello world", 50, 50, "Hello world");
	TEST("26-Wildcard _%*.*s_%*.*s_", 50, 5, "Hello world", 5, 50, "Hello world");
	TEST("27-Wildcard _%*.*s_%*.*s_", 50, -5, "Hello world", -5, 50, "Hello world");
	TEST("28-Char {%05.c}", 0);
	TEST("A-Stringception _%20s_", "Hello World");
	TEST("B-Stringception _%20.s_", "Hello World");
	TEST("C-Stringception _%-#20s_", "Hello World");
	TEST("D-Integer _%hi_", -61234);
	TEST("D-Integer _%hhi_", -61234);
	TEST("E-Integer _%hhu_", -61234);
	TEST("F-Integer _%hhhi_", -61234);
	TEST("G-Integer _%hhhu_", -61234);
	TEST("H-Integer _%hhhhi_", -61234);
	TEST("I-Integer _%hhhhu_", -61234);
	TEST("J-Integer [p] _%#.10hhhx_", -61234);
	TEST("K-Integer _%lx_", 0xDEADBEEF);
	TEST("K-Integer _%lX_", 0xDEADBEEF);
	TEST("L-Pointer _%p_", &pf);
	TEST("M-Pointer _%hhp_", &pf);
	TEST("N-Pointer _%p_", &pf);
	TEST("O-Pointer _%hhp_", &pf);
	TEST("P-Combo _%20i_", -'*');
	TEST("Q-Combo [lp]_%20.10i_", -'*');
	TEST("R-Combo [p]_%.10i_", -'*');
	TEST("S-Combo [l]_%020i_", -'*');
	TEST("T-Combo [lp]_%#20.10x_", '*');
	TEST("U-Combo _%-20i_", -'*');
	TEST("V-Combo _%-20.10i_", -'*');
	TEST("W-Combo _%-.10i_", -'*');
	TEST("X-Combo _%-020i_", -'*');
	TEST("Y-Combo _%-#20.10x_", '*');
	TEST("Z-Combo _%s_", "Helloλ");
	TEST("1Z-Octal a%ob%oc%od", 0, 55555, 1000000);
	TEST("1Z-Octal a%Ob%Oc%Od", 0, 55555, 1000000);
	TEST("20-Octal _%o_%#o_%0o_%0#o_%.0o_%.0#o_%0.0o_%0.0#o_", 0, 0, 0, 0, 0, 0, 0, 0);
	TEST("28-Char {%05.c}", 65);
	TEST("28-Char {%05.C}", 65);
	TEST("28-Char {%5.C}", 65);
	TEST("{%.3f}{%F}", 1.42, -1.42);
	TEST("{%.3f}{%F}", 1.419, -1.419);
	TEST("{% S}", L"(null)");
	TEST("{%05.*d}", 15, 42);
	TEST("{%05.*d}", -15, 42);
	TEST("%.2s is a string", "");
	TEST("%-.2s is a string", "");
	TEST("{%*d}", -5, 42);
	TEST("{%*u}", -5, 42);
	TEST("{%05.%}", 0);
	TEST("{%05.S}", L"42 c est cool");
	TEST("@main_ftprintf: %####0000 33..1..#00d\n", 256);
	TEST("%#.3o", 1);
	TEST("%#o", 1);
	TEST("%#.3i", 1);
	TEST("{%*d}", 5, 42);
	TEST("{%05.s}", 0);
	ft_printf("1Z-Binary %b\n", 700);
	int a,b,c,d,e,f;
	ft_printf("~ Flag%nWooWo% %[% 20.010-5n]%n\n", &a, &b, &c);
	printf("~ Flag%nWooWo% %[% 20.010-5n]%n\n", &d, &e, &f);
	if (a != d || b != e || c != f)
		ft_printf("FAIL : (Real,FT) (%i,%i) (%i,%i) (%i,%i)\n", d,a,e,b,f,c);
	else
		ft_printf("SUCCESS : (Real,FT) (%i,%i) (%i,%i) (%i,%i)\n", d,a,e,b,f,c);
	TEST("%.f", -1.22e-9);
	TEST("%e", 1222e9);
	TEST("%e", -1e9);
	TEST("%e", -1e-9);
	TEST("%.2e", 0);
	TEST("%E", 1222e9);
	TEST("%E", -1e9);
	TEST("%E", (-1e-9));
	TEST("%.2E", 0);
	TEST("%.e", 0);
	TEST("%.e", -1.22e-9);
    TEST("%g",x);
	TEST("%04.2f", x);
	TEST("%04.1e", x);

	
	TEST("{%f}{%F}", 1444565444646.6465424242242, 1444565444646.6465424242242);

	TEST("%4.2g", 0.10000000000001);
	TEST("%g", 0.10000000000001);

	TEST("%g", 0.00010000000000001);
	TEST("%g", 0.00001000000000001);
	TEST("%g", 0.00000010000000001);


	TEST("%4.2f", 0.10000000000001);
	TEST("%f", 0.10000000000001);

	TEST("%f", 0.00010000000000001);
	TEST("%f", 0.00001000000000001);
	TEST("%f", 0.00000010000000001);
	TEST("%03.2d", 0);
	TEST("%03.2d", 1);
	TEST("%%");
	TEST("% ");
	TEST("% h");

	TEST("%04.2g", 1222e9);
	TEST("%04.1g", 1222e9);
	TEST("%04.g", 1222e9);
	TEST("%g", -1e9);
	TEST("%g", -1e-9);
	TEST("%.2g", 0);
	TEST("%G", 1222e9);
	TEST("%G", -1e9);
	TEST("%G", (-1e-9));
	TEST("%.2G", 0);
	TEST("%.g", 0);
	TEST("%.g", -1.22e-9);

	TEST("%X", -60);
	TEST("%x", 15);
	TEST("%x", 3141593);
	TEST("%X", 2);
	TEST("%X", 3);

	TEST("aA: %a", 0.12);
	TEST("%a", 0.1);
	TEST("%a", 0.2);
	TEST("%a", 0.3);
	TEST("%a", 1.12);
	TEST("%a", 0.12);
	TEST("%f", 0.02);
	TEST("%a", 0.53);
	TEST("%a", 1.06);
	TEST("%a", 2.12);

	TEST("%04.1a", 1222e9);
	TEST("%04.a", 1222e9);
    TEST("%a",x);
	TEST("%a", -1e-9);
	TEST("%.a", -1.22e-9);
	TEST("%.2a", 0);

	TEST("%#0.3o", 0);
	TEST("%#0.3o", 1);
	TEST("%#.3o", 1);
	TEST("%9.o", 482);
	TEST("%#09.0o", 482);
	TEST("%.3o", 1);
	TEST("%#0#4lo", 0);
	TEST("%n", 0);
	
	TEST("%lc, %lc\n", L'ÊM-^ZM-^V', L'ÿ≠');
	TEST("%#0.3o", 0);
	TEST("%lc", 0xa2);
	TEST("%C", 0xa2);
	TEST("1%n", 0)
	setlocale(LC_ALL, "");

	TEST("%hhC, %hhC", 0, L'Á±≥');
	TEST("%.4S", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B")
	TEST("%C", L'ÁM-^L´');
	TEST("{%030S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	TEST("{%*d}", -5, 42);
	TEST("{%30S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	char cc;
	TEST("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C","bonjour", 42, &cc, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	
	TEST("%#o", 0)
	TEST("%.a", 0);

	// Todo

	TEST("Hex Significant cut: %.5g", 0.00);
	TEST("Hex Significant cut: %a", 1e9);
	TEST("Hex Significant cut: %a", -1e9);
	TEST("Hex Significant cut: %a", 0);
	TEST("%a", -1e9);

	TEST("Hex Round Problem: %04.1a", 26);
	TEST("Hex Round Problem: %04.2a", 1222e9);
	TEST("Hex Round Problem: %04.3a", 1222e9);

	TEST("Hex Capital Problem: %.2A", 1222e9);
	TEST("Hex Capital Problem: %.3A", 1222e9);
	TEST("Hex Capital Problem: %.4A", 1222e9);
	TEST("Hex Capital Problem: %.5A", 1222e9);
	// TEST("Hex Capital Problem: %.6A", 1222e9);
	TEST("Hex Capital Problem: %.7A", 1222e9);
	TEST("Hex Capital Problem: %.8A", 1222e9);

	TEST("Hex Capital Problem: %.2G", 1222e9);
	TEST("Hex Capital Problem: %.3G", 1222e9);
	TEST("Hex Capital Problem: %.4G", 1222e9);
	TEST("Hex Capital Problem: %.5G", 1222e9);
	TEST("Hex Capital Problem: %.6G", 1222e9);
	TEST("Hex Capital Problem: %.7G", 1222e9);
	TEST("Hex Capital Problem: %.8G", 1222e9);
	TEST("Hex Capital Problem: %.2A", 0);

	TEST("%2.2a", 15);
	TEST("%2.3a", 15);
	TEST("%2.4a", 15);
	TEST("%2.5a", 15);
	// TEST("%2.6a", 15);
	TEST("%2.7a", 15);

	TEST("%s", "The End");
	(void)ac;
	(void)av;
	return (0);
}
