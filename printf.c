#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
/**
 * print_char - function name
 * @arguments: takes arguments
 * Description - this is the description
 * Return: return type
 */
void print_char(va_list arguments)
{
	char c;

	c = va_arg(arguments, int);
	putchar(c);
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
	char output[40];
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
	char output[40];
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
	char output[40];
	int length = sprintf(output, "%s", ch);

	if (ch == NULL)
	{
		printf("(nil)");
		return;
	}
	write(1, output, length);
}
/**
 * print_all - function name
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
				putchar('%');
				putchar('r');
			}
		}
		else
		{
			putchar(format[i]);
		}
	}
	va_end(arguments);
	return (0);
}
