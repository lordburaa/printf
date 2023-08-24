#include "main.h"
/**
  * is_printable - evaluates if a char is printabke
  * @c: char to be evaluates
  * Return: 1 if c is printbla otherwise
  */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
/**
 * append_hexa_code - append ascii in hexadecimal code to buffer
 * @buffer: array of chars
 * @i: index atwhixh to start appending
 * @ascii_code: ascii cose
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char m_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;
	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = m_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];
	return (3);
}
/**
 * is_digit - verifies if a char is a digit
 * @c: char to evaluates
 * Return: 1 if c is a digit
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/**
 * convert_size_number -cats a number to the specifies size
 * @num: number to be casted
 * @sized: size
 * Return: casted value of num
 */
long int convert_size_number(long int num, int sized)
{
	if (sized == S_LONG)
		return (num);
	else if (sized == S_SHORT)
		return ((short)num);
	return ((int)num);
}
/**
 * convert_size_unsgnd - casts number to specigies size
 * @num : numebr indicarrion tupe to be ated
 * @sized: types to be casted
 * Return: value
 */
long int convert_size_unsgnd(unsigned long int num, int sized)
{
	if (sized == S_LONG)
		return (num);
	else if (sized == S_SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);
}
