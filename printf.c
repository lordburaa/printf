#include "main.h"
void print_buffer(char buffer[], int *buff_ind);
int _printf(const char *format, ...);
/**
  * _printf - print function
  * @format: format.
  * Return: print character
  */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flag, wdth, precision, sized, buff_ind = 0;
	va_list lists;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(lists, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);

			display_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flag = get_flags(format, &i);
			precision = get_precision(format, &i, lists);
			wdth = get_width(format, &i, lists);
			sized = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, lists, buffer,
					flag, wdth, precision, sized);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(lists);
	return (printed_chars);
}
/**
 * print_buffer - printd the content of the buffer if exist
 * @buffer: array char
 * @buff_indx: index
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
