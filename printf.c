#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
/**
 * print_char - function name
 * @arguments: takes arguments
 * Description - this is the description
 * Return: return type
 */
void print_r(va_list arguments)
{
	(void)arguments;
	write(1, "%r", 2);
}
void print_char(va_list arguments)
{
	char c;

	c = va_arg(arguments, int);
	write(1, &c, 1);
}
/**
 * print_int - function name
 * @arguments: takes arguments
 * Description - this is the description
 * Return: return type
 */
void print_int(va_list arguments)
{
	int i = va_arg(arguments, int);
	char output[BUFFER_SIZE];
	int length = sprintf(output, "%d", i);

	write(1, output, length);
}
/**
 * print_double - function name
 * @arguments: takes arguments
 * Description - this is the description
 * Return: return type
 */
void print_double(va_list arguments)
{
	double flo = va_arg(arguments, double);
	char output[BUFFER_SIZE];
	int length = sprintf(output, "%f", flo);

	write(1, output, length);
}
/**
 * print_string - function name
 * @arguments: takes arguments
 * Description - this is the description
 * Return: return type
 */
void print_string(va_list arguments)
{
	char *ch = va_arg(arguments, char*);
	write(1, ch, strlen(ch));
}
/**
 * _printf - function name
 * @format: takes cahr
 * Description - this is the description
 * Return: return type
 */
int _printf(const char *format, ...)
{
	va_list arguments;
	int i;
	int format_l;

	format_l = strlen(format);
	va_start(arguments, format);
	for (i = 0; i < format_l; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				break;
			}
			else if (format[i] == 'c')
			{
				print_char(arguments);
			}
			else if (format[i] == 's')
			{
				print_string(arguments);
			}
			else if (format[i] == 'd')
			{
				print_int(arguments);
			}
			else if (format[i] == 'f')
			{
				print_double(arguments);
			}
			else if (format[i] == 'r')
			{
				print_r(arguments);
			}
			else
			{
				write(1, "%", 1);
				write(1, &format[i], 1);
			}
		}
		else
		{
			write(1, &format[i], 1);
		}
	}
	va_end(arguments);
	return (0);
}
