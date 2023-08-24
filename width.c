#include "man.h"
/**
 * get_width - width
 * @format: format string in which to print the arguments
 * @k: list of arguments to protnted
 * @lists: list of arguments
 * Return: width.
 */
int get_width(const char *format, int *k, va_list lists)
{
	int curr;
	int wdth = 0;

	for (curr = *k + 1; format[curr] != '\0'; curr++)
	{
		if (is_digit(format[curr]))
		{
			wdth *= 10;
			wdth += format[curr] - '0';
		}
		else if (format[curr] == '*')
		{
			curr++;
			wdth = va_arg(lists, int);
			break;
		}
		else
			break;
	}
	*k = curr - 1;
	return (wdth);
}
