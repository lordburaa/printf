#include "main.h"
/**
 * print_unsigned - print
 * @lists: list of arguments
 * @buffer: buffer
 * @flag: flag
 * @precision: precision specification
 * @wdth: get width
 * @sized: size of
 * Return: number
 */
int print_unsigned(va_list lists, char buffer[], int flag,
		int wdth, int precision, int sized)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(lists, unsigned long int);

	num = convert_size_unsgnd(num, sized);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_unsgnd(0, i, buffer, flag, wdth, precision, sized));
}
/**
 * print_octal - prints an unsined
 * @lists: list of arguments
 * @buffer: calculates active falgs
 * @flag: flags
 * @wdth: width
 * @precision: prescionspecificsrion
 * @sized: size of spe
 * Return: numner of char
 */
int print_octal(va_list lists, char buffer[], int flag,
		int wdth, int precision, int sized)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(lists, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(wdth);
	num = convert_size_unsgnd(num, sized);
	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /=  8;
	}
	if (flag & F_HASH && int_num != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsgnd(0, i, buffer, flag, wdth, precision, sized));
}
/**
 * print_hexadecimal - print
 * @lists: list of
 * @flag: flag
 * @buffer: buffer
 * @flag: flag
 * @wdth: width
 * @precision: precision
 * @sized: size
 * Return: 1
 */
int print_hexadecimal(va_list lists, char buffer[], int flag,
		int wdth, int precision, int sized)
{
	return (print_hexa(lists, "0123456789abcdef", buffer, flag,
				'x', wdth, precision, sized));
}
/**
 * print_hexa_upper - print unsigned number in upper hexa decimal
 * @lists: list of arguments
 * @buffer: buffer
 * @flag: flag
 * @wdth: width
 * @precision: precision
 * @sized: size
 * Return: number
 */
int print_hexa_upper(va_list lists, char buffer[], int flag,
		int wdth, int precision, int sized)
{
	return (print_hexa(lists, "0123456789ABCDEF", buffer, flag, 'X',
				wdth, precision, int sized));
}
/**
 * print_hexa - prints
 * @lists: list  of arg
 * @m_to: array of valuse
 * @buffer: buffer aray is handle print
 * @wdth: get width
 * @precision: precision
 * @sized: sizd
 * @flag: flag
 * @fg_ch: calclul
 * Return: num
 */
int print_hexa(va_list lists, char m_to[], char buffer[],
		int flag, char fg_ch, int wdth, int precision, int sized)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(lists, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(wdth);

	num = convert_size_unsgnd(num, sized);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = m_to[num % 16];
		num /= 16;
	}
	if (flag & F_HASH && init_num != 0)
	{
		buffer[i--] = fg_ch;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsgnd(0, i, buffer, flag, wdth, precision, sized));
}
