#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str_contains(char c)
{
    static char conversions[] = "sSpdDioOuUxXcC";
    int         i;

    i = 0;
    while (conversions[i])
    {
        if (c == conversions[i++])
            return (1);
    }
    return (0);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		temp_n;
	size_t	len;
	char	sign;

	sign = (n < 0) ? -1 : 1;
	len = 2 + (n < 0);
	temp_n = n;
	while ((n = n / 10))
		len++;
	n = temp_n;
	if ((str = (char *)malloc(sizeof(char) * len--)) == NULL)
		return (NULL);
	str[len--] = '\0';
	str[len--] = sign * (n % 10) + '0';
	while ((n = n / 10))
		str[len--] = sign * (n % 10) + '0';
	if (sign < 0)
		str[len] = '-';
	return (str);
}

void    putnbr(int n)
{
    if(n >= 10)
    {
        putnbr(n / 10);
        putnbr(n % 10);
    }
    else
    {
        putchar(n + '0');
    }
}

int flags(char flag, char *search)
{
    while (*search)
    {
        if (*search == flag)
            return (1);
        search++;
    }
    return (0);
}

void    handle_d_i(char *f, int d_i)
{
    int i;
    int l_justfy;
    int force_pos;
    int num_digits;

    l_justfy = flags('-', f);
    force_pos = flags('+', f);
    i = atoi(f + (l_justfy + force_pos));
    num_digits = strlen(ft_itoa(i));
    if (force_pos)
        i = i - (num_digits + 1);
    if (l_justfy)
    {
        if (force_pos)
            putchar('+');
        putnbr(d_i);
        while (--i > 0)
            putchar(' ');
    }
    else
    {
        while (--i > 0)
            putchar(' ');
        if (force_pos)
            putchar('+');
        putnbr(d_i);
    }
}

void    ft_printf(char *format, ...)
{
    char    *traverse;
    va_list arg;
    int     i;
    char    *flags; 

    va_start(arg, format);
    i = 0;
    flags = malloc(strlen(format));
    traverse = format;
    while (*traverse)
    {
        if (*traverse == '%')
        {
            i = 0;
            traverse++;
            bzero(flags, strlen(flags));
            while (!str_contains(*traverse))
                flags[i++] = *traverse++;
            if (*traverse == 'd' || *traverse == 'i')
                handle_d_i(flags, va_arg(arg, int));
            // handle more flags
        }
        else
            putchar(*traverse);
        traverse++;
    }
    va_end(arg);
}

int     main(void)
{
    ft_printf("|%-+9d|%13d\n", 18,9 );
    printf("|%-+9d|%13d", 18,9 );
    return (0);
}