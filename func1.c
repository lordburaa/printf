#include "main.h"
/**
 * print_cotal - prints unsgined number in onctal notaotion
 * @types: lists of arguments
 * @buffer: buffer array to handle pirnt
 * Return: number of char printed
 */
int print_cotal(va_list types, char buffer[])
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	/*
	 * unsigned long int int_num = num;
*/
	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}
	i++;

	return (1);
}
