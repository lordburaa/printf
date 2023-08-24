#include "main.h"
/**
 * get_precision - calculate
 * @format: formated string in which to print
 * @k: list of argumetns
 * @lists: list of argumetns
 * Return: precison
 */
int get_precision(const char *format, int *k, va_list lists)
{
	int curr = *k + 1;
	int prc = -1;

	if (format[curr] != '.')
		return (precision);

	prc = 0;
	for (curr += 1; format[curr] != '\0'; curr++)
	{
		if (is_digit(format[curr]))
		{
			prc *= 10;
			prc += format[curr] - '0';
		}
		else if (format[curr] == '*')
		{
			curr++;
			prc = va_arg(lists, int);
			break;
		}
		else
			break

	}
	*k = curr - 1;
	return (prc);
}
