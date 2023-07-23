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
void print_int(va_list arguments, char *output, int *length)
{
	int i = va_arg(arguments, int);
	*length = sprintf(output, "%d", i);

	write(1, output, *length);
}
/**
 * print_double - function name
 * @arguments: takes arguments
 * Description - this is the description
 * Return: return type
 */
void print_double(va_list arguments, char *output, int *length)
{
	double flo = va_arg(arguments, double);
	*length = sprintf(output, "%f", flo);

	write(1, output, *length);
}
/**
 * print_string - function name
 * @arguments: takes arguments
 * Description - this is the description
 * Return: return type
 */
void print_string(va_list arguments, char *output, int *length)
{
	char *ch = va_arg(arguments, char*);

	if (ch == NULL)
	{
		*length = write(1, "(nil)", 5);
	}
	else
	{
		*length = sprintf(output, "%s", ch);
		write(1, output, *length);
	}
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
	char output[40];
	int length;

	length = 0;
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
				char c = va_arg(arguments, int);

				length = write(1, &c, 1);
			}
			else if (format[i] == 's')
			{
				print_string(arguments, output, &length);
			}
			else if (format[i] == 'd')
			{
				print_int(arguments, output, &length);
			}
			else if (format[i] == 'f')
			{
				print_double(arguments, output, &length);
			}
			else if (format[i] == 'r')
			{
				length = write(1, "%r", 2);
			}
		}
		else
		{
			length =  write(1, &format[i], 1);
		}
	}
	va_end(arguments);
	return (length);
}
