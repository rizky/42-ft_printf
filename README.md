%[argument_index$][flags][width][.precision]conversio

Tasks
- You have to manage the following conversions: sSpdDioOuUxXcC
- You must manage %%
- You must manage the flags #0-+ and space
- You must manage the minimum field-width
- You must manage the precision
- You must manage "length modifier" flags hh, h, l, ll, j, et z.

Bonus

- More detailed conversions management: eE, fF, gG, aA, n.
- More detailed flags management: *, $, L, ’.
- Non-existing flags management: %b to print in binary, %r to print a string of non- printable characters, %k to print a date in any ordinary ISO format etc.
- Management of alter tools for colors, fd or other fun stuff like that :)

WideChar Exeption

- if MB_CUR_MAX = 1 then treat as 1 byte (x - 256)
- U+DC00 to U+DFFF
- U+D800 to U+DBFF

Guides
- https://github.com/tvisenti/Ft_Printf/blob/master/inc/ft_printf.h
- http://en.cppreference.com/w/cpp/io/c/fprintf
- quote flag https://stackoverflow.com/questions/1449805/how-to-format-a-number-from-1123456789-to-1-123-456-789-in-c
- http://www.cplusplus.com/reference/cstdio/printf/
- Wildcard http://man7.org/linux/man-pages/man3/printf.3.html
- https://forum.intra.42.fr/topics/15759/messages

New Custom Conversions
- DateTime Conversion (%T)
- LinkedList Conversion (%r)
- Array Convesion (%y)
- Color Specifier (%w & %W)
- Byte Size Specifie (%q)
- Repetitif Char Conversion (%R)
- Binary (%b)

Adds-On
- ft_dprintfln
- ft_dprintf
- ft_asprintf
- ft_rasprintf
- Color Management
- ft_date
- fta

# ft_printf

As printf in C:  
\#include \<ft_printf.h\>  
int ft_printf(const char *format, ...);


<h2>Format:</h2>
%[flags][width][.precision][length]specifier


<h2>Specifier:</h2>
<b>sSpdDioOuUxXcCbneEfFgGaA</b>

<h2>Flags:</h2>
<b>\#0-+ and space</b>
<table>
  <tr>
    <td>-</td>
    <td>Left-justify within the given field width; Right justification is the default (see width sub-specifier).</td>
  </tr>
  <tr>
    <td>+</td>
    <td>Forces to preceed the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a - sign.</td>
  </tr>
  <tr>
    <td>(space)</td>
    <td>If no sign is going to be written, a blank space is inserted before the value.</td>
  </tr>
  <tr>
    <td>#</td>
    <td>Used with o, x or X specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero.
Used with a, A, e, E, f, F, g or G it forces the written output to contain a decimal point even if no more digits follow. By default, if no digits follow, no decimal point is written.</td>
  </tr>
  <tr>
    <td>0</td>
    <td>Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).</td>
  </tr>
</table>

<h2>Width:</h2>
Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger.

<h2>Precision:</h2>
For integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0.
For a, A, e, E, f and F specifiers: this is the number of digits to be printed after the decimal point (by default, this is 6).
For g and G specifiers: This is the maximum number of significant digits to be printed.
For s: this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered.
If the period is specified without an explicit value for precision, 0 is assumed.

<h2>Length sub-specifier:</h2>
<table>
  <tr>
    <td><b>length</b></td>
    <td><b>d i</b></td>
    <td><b>u o x X</b></td>
    <td><b>f F e E g G a A</b></td>
    <td><b>c</b></td>
    <td><b>s</b></td>
    <td><b>p</b></td>
  </tr>
  <tr>
    <td>hh</td>
    <td>int</td>
    <td>unsigned int</td>
    <td>double</td>
    <td>int</td>
    <td>char*</td>
    <td>void*</td>
  <tr>
    <td>h</td>
    <td>short int</td>
    <td>unsigned short int</td>
    <td></td>
    <td></td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>l</td>
    <td>long int</td>
    <td>unsigned long int</td>
    <td></td>
    <td>wint_t</td>
    <td>wchar_t*</td>
    <td></td>
  </tr>
  <tr>
    <td>ll</td>
    <td>long long int</td>
    <td>unsigned long long int</td>
    <td></td>
    <td></td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>j</td>
    <td>intmax_t</td>
    <td>uintmax_t</td>
    <td></td>
    <td></td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>z</td>
    <td>size_t</td>
    <td>size_t</td>
    <td></td>
    <td></td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>L</td>
    <td></td>
    <td></td>
    <td>long double	</td>
    <td></td>
    <td></td>
    <td></td>
  </tr>
</table>
