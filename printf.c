#include <unistd.h>
#include <stdarg.h>

int _putchar(char c)
{
    return write(1, &c, 1);
}

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
                for (j = 0; str[j] != '\0'; j++)
                {
                    _putchar(str[j]);
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
    return length;
}

