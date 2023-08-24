#include "main.h"
void print_buffer(char buffer[], int *buff_indx);
/**
  * _printf - print function
  * @format: format.
  * Return: print character
  */
int _printf(const char *format, ...)
{
	int i, display = 0, display_chars = 0;
	int flag, width, precision, size, buff_indx = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_indx++] = format[i];
			if (buff_ind == BUFF_SIZE)
				printf_buffer(buffer, &buff_indx);

			display_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_indx);
			flags = get_flags(format, &i);
			precision = get_precision(format, &i, args);
			width = get_width(format, &i, args);
			size = get_size(format, &i);
			++i;
			display = handle_print(format, &i, args, buffer, flags, width, precision, size);
			if (display == -1)
				return (-1);
			display_chars += diaplay;
		}
	}
	print_buffer(buffer, &buff_indx);
	va_end(args);
	return (display_chars);

}
/**
 * print_buffer - printd the content of the buffer if exist
 * @buffer: array char
 * @buff_ind: index 
 */
void print_buffer(char buffer[], int *buff_indx)
{
	if (*buff_indx > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_indx = 0;
}
