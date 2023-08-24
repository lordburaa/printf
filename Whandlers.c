#include "main.h"
/**
 * handle_write_char - pritn string
 * @c: char types
 * @buffer: bifeer arry to hndle printd
 * @flag: calculate
 * @wdth: get width
 * @precision: presion specifier
 * @sized: size specifier
 * Return: number of char s printed
 */
int handle_write_char(char c, char buffer[], int flag,
		int wdth, int precision, int sized)
{
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);
	if (flag & F_ZERO)
		padd = '0';
	buffer[i++] = c;
	buffer[i] = '\0';
	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < wdth - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padd;
		if (flag & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], wdth - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], wdth - 1) +
					write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}
/**
 * write_number - prints a string
 * @is_negative: list of arguments
 * @ind: char types
 * @buffer: buffer aray to handle print
 * @flag: clalcultaes flag
 * @wdth: get widht
 * @precision: precison ps
 * @sized: size pf psecifies
 * Return: numbr of chars printed
 */
int write_number(int is_negative, int ind, char buffer[],
		int flag, int wdth, int precision, int sized)
{
	int leg = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(sized);
	if ((flag & F_ZERO) && !(flag & F_MINUS))
		padd = '0';
	if (is_negative)
		x_ch = '-';
	else if (flag & F_PLUS)
		x_ch = '+';
	else if (flag & F_SPACE)
		x_ch = ' ';
	return (write_num(ind, buffer, flag, wdth, precision, leg, padd, x_ch));
}
/**
 * write_num - writee a number using a buffer
 * @ind: index at which
 * @buffer: buffer
 * @flag: flag
 * @wdth: width
 * @precision: precison
 * @leg: number lenght
 * @padd: padding char
 * @x_c: extra char
 * Return: number of printed chars
 */
int write_num(int ind, char buffer[], int flag, int wdth,
		int precision, int leg, char padd, char x_c)
{
	int i, padd_start = 1;

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && wdth == 0)
		return (0);
	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (precision > 0 && precision < leg)
		padd = ' ';
	while (precision > leg)
		buffer[--ind] = '0', leg++;
	if (x_c != 0)
		leg++;
	if (wdth > leg)
	{
		for (i = 1; i < wdth - leg + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flag & F_MINUS && padd == ' ')
		{
			if (x_c)
				buffer[--ind] = x_c;
			return (write(1, &buffer[ind], leg) + write(1, &buffer[1], i - 1));
		}
		else if (!(flag & F_MINUS) && padd == ' ')
		{
			if (x_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], leg));
		}
		else if (!(flag & F_MINUS) && padd == '0')
		{
			if (x_c)
				buffer[--padd_start] = x_c;
			return (write(1, &buffer[padd_start], i - padd_start) +
					write(1, &buffer[ind], leg - (1 - padd_start)));
		}
	}
	if (x_c)
		buffer[--ind] = x_c;
	return (write(1, &buffer[ind], leg));
}
/**
 * write_unsnd_unsgnd - unsigned number
 * @is_negative: num negstive
 * @ind: index
 * @flag: flag
 * @buffer: buffer
 * @precision: precision
 * @wdth: width
 * @sized: size
 * Return: number of char
 */
int write_unsgnd(int is_negative, int ind, char buffer[],
		int  flag, int wdth, int precision, int sized)
{
	int leg = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);
	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);
	if (precision > 0 && precision < leg)
		padd = ' ';
	while (precision > leg)
	{
		buffer[--ind] = '0';
		leg++;
	}
	if ((flag & F_ZERO) && !(flag & F_MINUS))
		padd = '0';

	if (wdth > leg)
	{
		for (i = 0; i < wdth - leg; i++)
			buffer[i] = padd;
		buffer[i] = '\0';

		if (flag & F_MINUS)
		{
			return (write(1, &buffer[ind], leg) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], leg));
		}
	}
	return (write(1, &buffer[ind], leg));
}
/**
 * write_pointer - writes memoroy adress
 * @buffer: arrays of chars
 * @ind: index at which
 * @leg: lenght of number
 * @wdth: width specifier
 * @flag: flags specifier
 * @padd: char repersesnting the padding
 * @x_c: chsr repersetnation extra char
 * @padd_start: index at which padding should start
 * Return: number of written chars
 */
int write_pointer(char buffer[], int ind, int leg, int wdth,
		int flag, char padd, char x_c, int padd_start)
{
	int i;

	if (wdth > leg)
	{
		for (i = 3; i < wdth - leg + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flag & F_MINUS && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (x_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], leg) + write(1, &buffer[3], i - 3));
		}
		else if (!(flag & F_MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (x_c)
				buffer[--ind] = x_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], leg));
		}
		else if (!(flag & F_MINUS) && padd == '0')
		{
			if (x_c)
				buffer[--padd_start] = x_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
					write(1, &buffer[ind], leg - (1 - padd_start) - 2));
		}

	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (x_c)
		buffer[--ind] = x_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
