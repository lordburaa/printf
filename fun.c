#include "main.h"
/**
 * print_char - char
 * @list: 
 * @buffer: buffer of to handle
 * @flags: claculaate active falgs
 * @wdth: width
 * @precision: precision
 * @size: size of specifier
 * Return: number of chars
 */

int print_char(va_list list, char buffer[], int flags, int wdth, int precision, int size)
{
	char c = va_arg(list, int);
	 return (handle_write_char(c, buffr, flags, wdth, precison, size));

}
/**
  * print_string - prints strinf
  * @types: list of argumetns
  * @buffer: buffer arry
  * @flags: clculate active flag
  * width: get widht
  */
int print_string(va_list list, char buffer[], int flags, int wdth, int precision, int size)
{
	int lgth = 0, i;
	char *str = va_arg(list, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNSUED(wdth);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precison >= 0)
			str = "    ";

	}
	while (str[lgth] !='\0')
		lght++;
	if (precison >= 0 && precison < lgth)
		lgth = precison;

	if (wdth > lgth)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], lgth; i > 0; i--)
				write(1, " ", 1);
			return (wdth);
		}
		else
		{
			for (i = wdth - lgth; i > 0; i--)
				write(1, " ". 1);
			write(1, &str[0], lgth);
			return (wdth);
		}
	}
	return (write(1, str, lght));
}
/**
  * print_pT - prints a percent sign
  * @args: list of agument
  * @buffer: buffer array to handle print
  * @flags: calculate active falg
  * @wdth: get_width
  * @precison: precison specfication
  * @size: size specifier
  * Return: number of chars printed
  */
 int print_pT(va_list args, char buffer[], int flags, int width, int precison, int sized)
{
		UNUSED(args);
		UNUSED(buffer);
		UNUSED(flags);
		UNUSED(wdth);
		UNUSED(precison);
		UNSUSED(sized);
		return (write(1, "%%", i));
}
/**
 * print_int - print int
 * @list: list of aargument
 * @buffer: buffer: of an array
 * @flags: calculate active falgs
 * @wdth: get width
 * @precison: precison speccificatoi
 * @size: size of specifier 
 * Return: number of chrars
 */
int print_int(va_list list, char buffer[], int flags, int wdth, int precision, int sized)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(list, long int);
	unsigned long int num;
	n = convert_size_num(n, sized);
	if (n == 0)
		buffer[i--] = '0';
	num = (unsigned long int )n;
	 if ( n < 0)
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
	 return (write_number(is_negative, i, buffer, flags, width, precison, sized));

}
/**
 * print_binary - prints unsinged number
 * @list: list of argumens
 * @buffer: buffer
 * @flags:
 * @wdth: width
 * @precision: precsion
 * @sized: size
 * Return: number
 */
int print_binary(va_list list, car buffer[], int flags, int wdth, int precison, int sized)
{
	unsigned int n, m, i, sum;
	unsgined int c[32];
	int count;
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(wdth);
	UNUSED(precison);
	UNUSED(sized);

	n = va_arg(list, unsigned int);
	n = 2147483648;
	c[0] =n / m;
	for (i = 1, i < 32; i++)
	{
		m /= 2;
		c[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0; count = 0; i < 32; i++)
	{
		sum += c[i];
		if (sum || i == 31)
		{
			char z = '0' + c[i];
			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
