#include "main.h"
/**
 * print_char - char
 * @lists: list
 * @buffer: buffer of to handle
 * @flag: claculaate active falgs
 * @wdth: width
 * @precision: precision
 * @sized: size of specifier
 * Return: number of chars
 */
int print_char(va_list lists, char buffer[], int flag,
		int wdth, int precision, int sized)
{
	char d = va_arg(lists, int);

	return (handle_write_char(d, buffer, flag, wdth, precision, sized));
}
/**
  * print_string - prints strinf
  * @lists: list of argumetns
  * @buffer: buffer arry
  * @flag: clculate active flag
  * @wdth: get widht
  * @precision: precison
  * @sized: size
  * Return: chars
  */
int print_string(va_list lists, char buffer[], int flag,
		int wdth, int precision, int sized)
{
	int leg = 0, i;
	char *str = va_arg(lists, char *);

	UNUSED(buffer);
	UNUSED(flag);
	UNSUED(wdth);
	UNUSED(precision);
	UNUSED(sized);
	if (str == NULL)
	{
		str = "(null)";
		if (precison >= 6)
			str = "    ";

	}
	while (str[leg] != '\0')
		leg++;
	if (precision >= 0 && precision < leg)
		leg = precision;

	if (wdth > leg)
	{
		if (flag & F_MINUS)
		{
			write(1, &str[0], leg);
			for (i = wdth - leg; i > 0; i--)
				write(1, " ", 1);
			return (wdth);
		}
		else
		{
			for (i = wdth - leg; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], leg);
			return (wdth);
		}
	}
	return (write(1, str, leg));
}
/**
  * print_pT - prints a percent sign
  * @lists: list of agument
  * @buffer: buffer array to handle print
  * @flag: calculate active falg
  * @wdth: get_width
  * @precision: precison specfication
  * @sized: size specifier
  * Return: number of chars printed
  */
int print_percent(va_list lists, char buffer[], int flag,
		 int wdth, int precision, int sized)
{
		UNUSED(lists);
		UNUSED(buffer);
		UNUSED(flag);
		UNUSED(wdth);
		UNUSED(precision);
		UNUSED(sized);
		return (write(1, "%%", i));
}
/**
 * print_int - print int
 * @lists: list arg
 * @buffer: buffer: of an array
 * @flag: calculate active falgs
 * @wdth: get width
 * @precision: precison specificatoin
 * @sized: size of specifier
 * Return: number of chrars
 */
int print_int(va_list lists, char buffer[], int flag,
		int wdth, int precision, int sized)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(lists, long int);
	unsigned long int num;

	n = convert_size_number(n, sized);
	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;
	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;

	return (write_number(is_negative, i, buffer, flag, wdth, precision, sized));
}
/**
 * print_binary - prints unsinged number
 * @lists: list of argumens
 * @buffer: buffer
 * @flag: flag
 * @wdth: wdth
 * @precision: precsion
 * @sized: size
 * Return: number
 */
int print_binary(va_list lists, car buffer[], int flag,
		int wdth, int precision, int sized)
{
	unsigned int n, m, i, sum;
	unsigned int c[32];
	int cnt;

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(wdth);
	UNUSED(precision);
	UNUSED(sized);

	n = va_arg(lists, unsigned int);
	m = 2147483648;
	c[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		c[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, cnt = 0; i < 32; i++)
	{
		sum += c[i];
		if (sum || i == 31)
		{
			char z = '0' + c[i];

			write(1, &z, 1);
			cnt++;
		}
	}
	return (cnt);
}
