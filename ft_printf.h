#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#define	__need_size_t
#define __need_wchar_t
#include <stddef.h>
#include <stdarg.h>

/* Precision.	*/
/* Width.	*/
/* Format letter.	*/
/* L flag.	*/
/* h flag.	*/
/* l flag.	*/
/* # flag.	*/
/* Space flag.	*/
/* - flag.	*/
/* + flag.	*/
/* ' flag.	*/
/* For special use.	*/
/* hh flag.	*/
/* Nonzero for wide character streams.	*/
/* I flag.	*/
/* Floating-point argument is ABI-compatible
 with IEC 60559 binary128.	*/
/* Unused so far.	*/
/* Bits for user-installed modifiers.	*/
/* Padding character.	*/

struct printf_info
{
	int prec;
	int width;
	wchar_t spec;
	unsigned int is_long_double:1;
	unsigned int is_short:1;
	unsigned int is_long:1;
	unsigned int alt:1;
	unsigned int space:1;
	unsigned int left:1;
	unsigned int showsign:1;
	unsigned int group:1;
	unsigned int extra:1;
	unsigned int is_char:1;
	unsigned int wide:1;
	unsigned int i18n:1;
	unsigned int is_binary128:1;
	unsigned short int user;
	wchar_t pad;
};

enum
{
	PA_INT,
	PA_CHAR,
	PA_WCHAR,
	PA_STRING,
	PA_WSTRING,
	PA_POINTER,
	PA_FLOAT,
	PA_DOUBLE,
	PA_LAST
};

#endif
