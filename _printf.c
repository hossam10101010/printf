#include "main.h"
/**
* _printf - a custom function alternative to printf
* ap: list of variadic arguments
* @format: string of variadic arguments
* Return: return number of printed characters
*/


int _printf(const char *format, ...)
{
	va_list ap;
	int count = 0;
	int i = 0;
	const char validspec[] = "diouxXfsbpc%";

	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format == NULL || (format == "%" || format == "%\0"))
		return (0);
		if (format[i] == '%')
		{
			if (format[i + 1] == ' ')
			return (0);
			if (format[i + 1] != '\0')
			{
				int valid_spec = 0;
				unsigned int j = 0;

				for (j = 0; j < sizeof(validspec); j++)
				{
					if (format[i + 1] == validspec[j])
					{
						valid_spec = 1;
						break;
					}
				}
				if (valid_spec)
				{
					count += handle_format(format[i + 1], ap);
					i++;
				}
				else
				count += write(1, &format[i], 1);
			}
		}
		else
		count += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}
