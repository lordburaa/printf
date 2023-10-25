#include "main.h"

int handle_print(const char *format, int *index, va_list list)
{
	int i = 0;
	int printed_chars = -1;
	format_t fmt_types = {
		{'c', print_char}, {'s', print_string}};
	for (i = 0; fmt_types.format != '\0'; i++)
	{
		if(fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].ptr(list));
		if (fmt_typed[i].format == '\0')
		{
			if (fmt[*index] == '\0')
				return (-1);
		}

	}

return (printed_chars);

}
