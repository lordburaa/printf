#include "main.h"
#include <stdio.h>
/**
 * print_char - print char
 * @types: list of argument
 * @buffer: buffer
 * Return: list of arimgent
 */
int print_char(va_list types, char buffer[])
{
	char c = va_arg(types, int);

	return (handle_wchar(c, buffer));
}
/**
 * print_string - print string
 * @types: list of argument
 * @buffer: buffer
 * Return: nubmer of string
 */
int print_string(va_list types, char buffer[])
{
	int leng = 0;
	char *ptr = va_arg(types, char *);

	UNUSED(buffer);
	if (ptr == NULL)
	{
		ptr = "(null)";
	}
	while (ptr[leng] != '\0')
		leng++;
	return (write(1, ptr, leng));
}
/**
 * print_percent - prints pecent sign
 * @types: list of argument
 * @buffer: buffer
 * Return: number of hcar printed
 */
int print_percent(va_list types, char buffer[])
{
	UNUSED(types);
	UNUSED(buffer);
	return (write(1, "%%", 1));
}
