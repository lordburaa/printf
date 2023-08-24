#include "main.h"
/**
 * handle_print - prints arguments
 * @fmt: format
 * @ind: ind
 * @flag: flag
 * @wdth: width
 * @size: size
 * @precision: precision
 * @lists: lists
 * Return:  1 or 2
 */
int handle_print(const  char *fmt, int *ind, va_list lists,
		char buffer[], int flags, int width, int precision, int sized)
{
	int j, unknown_ln = 0, display_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'x', print_hexa_upper}, {'p', print_int}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (j = 0; fmt_types[j].fmt != '\0'; j++)
		if (fmt[*ind] == fmt_types[j].fmt)
			return (fmt_types[i].fn(lists, buffer, flag, wdth, precision, sized));
	if (fmt_types[j].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
			unknown_ln += write(1, "%%", 1);
			if (fmt[*ind - 1] == ' ')
				unknown_ln += write(1, " ", 1);
			else if (wdth)
			{
				--(*ind);
				while (fmt[*ind] != ' ' && fmt[*ind] != '%')
					--(*ind);
				if (fmt[*ind] == ' ')
					--(*ind);
				return (1);
			}
			unknown_ln += write(1, &fmt[*ind], 1);
			return (unknown_ln);
		}
		return (display_chars);
}
