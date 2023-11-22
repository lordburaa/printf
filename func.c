#include "main.h"
#include <stdio.h>
/**
 * print_char - print char
 * @types: list of argument
 * @buffer: buffer
 * @buff_ind: buffer index
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
 * @buff_ind: buffer ind
 * Return: nubmer of string
 */
int print_string(va_list types, char buffer[], int *buff_ind)
{
	int leng = 0;
	char *ptr = va_arg(types, char *);

	print_buffer(buffer, buff_ind);
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
 * @buff_ind: buffer ind
 * Return: number of hcar printed
 */
int print_percent(va_list types, char buffer[], int *buff_ind)
{
	UNUSED(types);
	print_buffer(buffer, buff_ind);
	return (write(1, "%%", 1));
}
/**
 * printf_int - print integer
 */
int print_int(va_list types, char buffer[])
{
	int is_negative = 0;
	int i = BUFF_SIZE - 2;

	int n = va_arg(types, int);

	if (n < 0)
	{
		num = (unsigned int)((-1) * n);
		is_negative = 1;
	}
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_number(is_engaive, i, buffer));
}
