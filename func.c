#include "main.h"
#include <stdio.h>
/**
 * print_char - print char
 * @types: list of argument
 * @buffer: buffer
 * Return: list of arimgent
 */
int print_char(va_list types, char buffer[], int *buff_ind)
{
	char c = va_arg(types, int);

	print_buffer(buffer, buff_ind);
	return (handle_wchar(c));
}
/**
 * print_string - print string
 * @types: list of argument
 * @buffer: buffer
 * Return: nubmer of string
 */
int print_string(va_list types, char buffer[], int *buff_ind)
{
	int leng = 0;
	char *ptr = va_arg(types, char *);

	UNUSED(buff_ind);
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
int print_percent(va_list types, char buffer[], int *buff_ind)
{
	UNUSED(types);
	print_buffer(buffer, buff_ind);
	return (write(1, "%%", 1));
}
