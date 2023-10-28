#include "main.h"
/**
 * _printf - printf function
 * @format: format
 * Return: printed chars
 */
int _printf(const char *format, ...)
{
	va_list list;
	int i;
	int prnt = 0;
	int out_chars = 0;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
			out_chars++;
		else
		{
			++i;
			prnt = handle_print(format, &i, list, buffer);
			if (prnt == -1)
				return (-1);
			out_chars += prnt;
		}
	}
	va_end(list);
	return (out_chars);
}
