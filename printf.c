#include <unistd.h>
#include <stdarg.h>
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
				char *str = va_arg(arguments, char*);

				if (str == NULL)
				{
					_putchar('(');
					_putchar('n');
					_putchar('u');
					_putchar('l');
					_putchar('l');
					_putchar(')');
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
				int divisor = 1;
				int temp = num;

				if (num < 0)
				{
					_putchar('-');
					length++;
					num = -num;
				}
				for (temp = num; temp < 9; temp /= 10)
				{
					divisor *= 10;
				}
				for (; divisor > 0; divisor /= 10)
				{
					int digit = num / divisor;

					_putchar(digit + '0');
					length++;
					num %= divisor;
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

