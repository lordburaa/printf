#include "main.h"
/**
 * handle_print - hadnle the format
 * @format: format
 * @index: index
 * * @list: argumet list
 * Return: number of byetes writen
 */
int handle_print(const char *format, int *index, va_list list)
{
	int len_unknow, i;
	int printed_chars = -1;
	format_t fmt_types = {
		{'c', print_char}, {'s', print_string},
		{'%', print_percent}, {'\0', NULL}};
	for (i = 0; fmt_types.format != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].ptr(list));
	if (fmt_typed[i].format == '\0')
	{
		if (fmt[*index] == '\0')
			return (-1);
		len_unknow += write(1, "%%", 1);
		if(format[*index - 1] == ' ')
			len_unknow += write(1, " ", 1);
		len_unknow += write(1, &format[*index], 1);
		return (len_unknow);
	}
	return (printed_chars);
}
