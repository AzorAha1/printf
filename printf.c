#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
#include <stdint.h>
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
	int length = snprintf(output,BUFFER_SIZE, "%d", i);

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
	int length = snprintf(output, BUFFER_SIZE, "%f", flo);
	
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

	if (ch == NULL)
	{
		write(1, "(null)", 1);
		return;
	}
	write(1, ch, strlen(ch));
}
/**
 * print_u - function name
 * @arguments: parameters
 * Description - this is the description
 * Return: return type
 */
void print_u(va_list arguments)
{
	unsigned int u = va_arg(arguments, unsigned int);
	char output[BUFFER_SIZE];
	int length = snprintf(output, BUFFER_SIZE, "%u", u);

	write(1, output, length);
}
/**
 * print_o - function name
 * @argument: parameter
 * Description - this is the description
 * Return: return type
 */
void print_o(va_list arguments)
{
	unsigned int o = va_arg(arguments, unsigned int);
	char output[BUFFER_SIZE];
	int length = snprintf(output, BUFFER_SIZE, "%o", o);

	write(1, output, length);
}
/**
 * print_x - function name
 * @argument: parameter
 * Description - this is the description
 * Return: return type
 */
void print_x(va_list arguments)
{
	unsigned int x = va_arg(arguments, unsigned int);
	char output[BUFFER_SIZE];
	int length = snprintf(output, BUFFER_SIZE, "%x", x);
	
	write(1, output, length);
}
/**
 * print_hex - function name
 * @argument: parameter
 * Description - this is the description
 * Return: return type
 */
void print_hex(va_list arguments)
{
        unsigned int x = va_arg(arguments, unsigned int);
        char output[BUFFER_SIZE];
        int length = snprintf(output, BUFFER_SIZE, "%X", x);

        write(1, output, length);
}
/**
 * print_percent - function name
 * @argument: parameter
 * Description - this is the description
 * Return: return type
 */
void print_percent(va_list arguments)
{
	char c;

        (void)arguments;
	c = '%';
        write(1, &c, 1);
}
/**
 * print_address - function name
 * @argument: parameter
 * Description - this is the description
 * Return: return type
 */
void print_address(va_list arguments)
{
        void *p = va_arg(arguments, void *);
	char output[BUFFER_SIZE];
	int length = snprintf(output, BUFFER_SIZE, "%p", p);

	write(1, output, length);
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
				print_char(arguments);
				length +=1;
			}
			else if (format[i] == 's')
			{
				print_string(arguments);
				length += strlen(va_arg(arguments, char*));
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				print_int(arguments);
				length += snprintf(NULL, 0, "%d", va_arg(arguments, int));
			}
			else if (format[i] == 'f')
			{
				print_double(arguments);
				length += snprintf(NULL, 0, "%f", va_arg(arguments, double));
			}
			else if (format[i] == 'u')
			{
				print_u(arguments);
				length += snprintf(NULL, 0, "%u", va_arg(arguments, unsigned int));
			}
			else if (format[i] == 'o')
			{
				print_o(arguments);
				length += snprintf(NULL, 0, "%o", va_arg(arguments, unsigned int));
			}
			else if (format[i] == 'x')
			{
				print_x(arguments);
				length += snprintf(NULL, 0, "%x", va_arg(arguments, unsigned int));
			}
			else if (format[i] == 'X')
			{
				print_hex(arguments);
				length += snprintf(NULL, 0, "%X", va_arg(arguments, unsigned int));
			}
			else if (format[i] == '%')
			{
				print_percent(arguments);
				length += 1;
			}
			else if (format[i] == 'p')
			{
				print_address(arguments);
				length += snprintf(NULL, 0, "%p", va_arg(arguments, void*));
			}
			else
			{
				write(1, "%", 1);
				write(1, &format[i], 1);
				length += 2;
			}
		}
		else
		{
			write(1, &format[i], 1);
			length += 1;
		}
	}
	va_end(arguments);
	return (length);
}
