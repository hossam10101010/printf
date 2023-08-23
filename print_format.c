#include "main.h"
/**
* handle_format- checks for the format specifier after '%'
* @ap: list of variadic arguments
* @spec: the format specifier to be checked by @print_format
* Return: return number of printed characters
*/

int handle_format(char spec, va_list ap)
{
	int count = 0;

	if (spec == 'c')
	count += _putchar(va_arg(ap, int));
	else if (spec == 's')
	count += handle_str(va_arg(ap, char *));
	else if (spec == 'i' || spec == 'd')
	count += handle_digit((long)(va_arg(ap, int)), 10);
	else if (spec == 'x')
	count += handle_hexa((long)(va_arg(ap, unsigned int)), 16, 'x');
	else if (spec == 'X')
	count += handle_hexa((long)(va_arg(ap, unsigned int)), 16, 'X');
	else if (spec == 'u')
	count += handle_digit((long)(va_arg(ap, unsigned int)), 10);
	else if (spec == 'o')
	count += handle_digit((long)(va_arg(ap, unsigned int)), 8);
	else if (spec == 'p')
	{
	count += write(1, "0x", 2);
	count += handle_digit((long)(va_arg(ap, void *)), 16);
	}
	else if (spec == 'b')
	count += handle_digit((long)(va_arg(ap, void *)), 2);
	else if (spec == '%')
	count += _putchar('%');
	else
	count += write(1, &spec, 1);
	return (count);
}
