#include "main.h"
/**
* handle_str - prints string to stdout
* @str: the string to be printed
* Return: return number of printed characters
*/

int handle_str(char *str)
{
	int count = 0;

	while (*str != '\0')
	{
	_putchar((int)*str);
	++count;
	++str;
	}
	return (count);
}
