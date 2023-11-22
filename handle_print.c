#include "main.h"
/**
 * handle_print - hadnle the format
 * @format: format
 * @index: index
 * @list: argumet list
 * @buffer: buffer
 * Return: number of byetes writen
 */
int handle_print(const char *format, int *index, va_list list, char buffer[], int *buff_ind)
{
	int len_unknow = 0, i;
	int printed_chars = -1;

	format_t fmt_types[] = {
		{'c', print_char}, {'s', print_string},
		{'%', print_percent}, {'\0', NULL}};

	for (i = 0; fmt_types[i].format != '\0'; i++)
		if (format[*index] == fmt_types[i].format)
			return (fmt_types[i].ptr(list, buffer, buff_ind));
	if (fmt_types[i].format == '\0')
	{
		if (format[*index] == '\0')
			return (-1);
		len_unknow += write(1, "%%", 1);
		if (format[*index - 1] == ' ')
			len_unknow += write(1, " ", 1);
		len_unknow += write(1, &format[*index], 1);
		return (len_unknow);
	}
	return (printed_chars);
}
