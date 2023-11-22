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
	int buff_ind = 0;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
			{
				print_buffer(buffer, &buff_ind);
			}
			out_chars++;
		}
		else
		{
			++i;
			prnt = handle_print(format, &i, list, buffer);
			if (prnt == -1)
				return (-1);
			out_chars += prnt;
		}
	}
	if (buff_ind != 0)
		print_buffer(buffer, &buff_ind);
	va_end(list);
	return (out_chars);
}
/**
 * print_buffer - print buffer
 * @buffer: storing buffer
 * @buff_ind: size of buffer
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind >= 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
