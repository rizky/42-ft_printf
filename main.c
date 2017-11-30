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

    l_justfy = flags('-', f);
    force_pos = flags('+', f);
    i = atoi(f + (l_justfy + force_pos));
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