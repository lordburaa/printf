#include "main.h"
/**
 * print_char - print char
 * @types: list of argument
 * Return: list of arimgent
 */
int print_char(va_list types, char buffer[])
{
	char c = va_arg(types, int);
	return (write(1, c, 1));
}
/**
 * print_string - print string
 * @types: list of argument
 * Return: nubmer of string
 */
int print_string(va_list types)
{
	int leng++;
	char *ptr = va_arg(types, char *);
	
	while (str[leng] != '\0')
		leng++;

	return (write(1, ptr, leng));
}
/**
 * print_percent - prints pecent sign
 * @types: list of argument
 * Return: number of hcar printed
 */
int print_percent(va_list types)
{
	UNUSED(types);
	return (write(1, "%%", 1));
}
