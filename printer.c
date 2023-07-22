#include <unistd.h>
#include "main.h"
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - writes the character c to stdout
 * @format: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _printf(const char *format, ...)
{
	int i;

	va_list arguments;
	va_start(arguments, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{

			i++;
			if (format[i] == '\0')
			{
				break;
			}
		}
		if (format[i] == 'd')
		{
			int c = va_arg(arguments, int);
			char output[40];
			int length = sprintf(output, "%d", c);
			write(1, output, length);
		}
		else if (format[i] == 's')
		{
			char *c = va_arg(arguments, char*);
			char output[40];
			int length = sprintf(output, "%s", c);
			write(1, output, length);
		}
		else if (format[i] == 'f')
		{
			double c = va_arg(arguments, double);
			char output[40];
			int length = sprintf(output, "%f", c);
			write(1, output, length);
		}
		else if (format[i] == 'c')
		{
			int c = va_arg(arguments, int);
			putchar(c);
		}
	}
	va_end(arguments);
	return(0);
}
