#include "main.h"
/**
 * get_size - calculaate the size of the aegumnet
 * @format: format
 * @k: list of arguments to be pritned
 * Return: precision
 */
int get_size(const char *format, int *k)
{
	int curr = *k + 1;
	int size;

	size = 0;
	if (format[curr] == 'l')
		size = S_LONG;
	else if (format[curr] == 'h')
		size = S_SHORT;
	if (size == 0)
		*k = curr - 1;
	else
		*k = curr;
	return (size);
}
