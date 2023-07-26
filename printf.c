#include <unistd.h>
#include <stdarg.h>
#include "main.h"
#include <stdio.h>
/**
 * _putchar - function name
 * @c: c
 * Description - Description
 * Return: returnd
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
void print_s(char *str)
{
	int j;
       	if (str == NULL)
	{
		_putchar('(');
		_putchar('n');
		_putchar('u');
		_putchar('l');
		_putchar('l');
		_putchar(')');
	}
	else
	{
		for (j = 0; str[j] != '\0'; j++)
		{
			_putchar(str[j]);
		}	
	}

}
/**
 * _printf - function name
 * @format: format
 * Description - Description
 * Return: return
 */
int _printf(const char *format, ...)
{
	va_list arguments;
	int length = 0;
	int i;
	int j;
	char *str;

	va_start(arguments, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			length++;
		}
		else
		{
			i++;
			if (format[i] == '\0')
			{
				_putchar('%');
				length++;
				break;
			}
			else if (format[i] == 'c')
			{
				char c = va_arg(arguments, int);

				_putchar(c);
				length++;
			}
			else if (format[i] == 's')
			{
				str = va_arg(arguments, char*);
				print_s(str);

				if (str == NULL)
				{
					length += 6;
				}
				for (j = 0; str[j] != '\0'; j++)
				{
					_putchar(str[j]);
					length++;
				}
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				int num = va_arg(arguments, int);
				char output[BUFFER_SIZE];
				int conversion_length;

				conversion_length = snprintf(output, BUFFER_SIZE, "%d", num);
				if (conversion_length < 0 || conversion_length >= BUFFER_SIZE)
				{
					return (-1);
				}
				for (j = 0; output[j] != '\0'; j++)
				{
					_putchar(output[j]);
					length++;
				}
				
			}
			else if (format[i] == '%')
			{
				_putchar('%');
				length++;
			}
			else
			{
				_putchar('%');
				_putchar(format[i]);
				length += 2;
			}
		}
	}
	va_end(arguments);
	return (length);
}

