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
int print_int(va_list types, char buffer[], int *buff_ind)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	int n = va_arg(types, int);
	unsigned int num;
	int k = 0;
	UNUSED(buff_ind);

	num = (unsigned int)n;
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
	return (write_number(is_negative, &i, buffer, k));
}

int print_binary(va_list types, char buffer[], int *ind)
{
	unsigned int n, m, sum;
	unsigned int a[32];
	int count, i;
	

	
	n = va_arg(types, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		buffer[(*ind)] = '0' + 0;
		if (sum)
		{
			++(*ind);
			buffer[(*ind)] = a[i] + '0';
			count++;
		}
	}
	return (count);
}
