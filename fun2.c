#include "main.h"
/**
 * print_pointer - prints the calie of
 * @lists: lisst
 * @buffer: buffer
 * @flag: flag
 * @wdth: width
 * @precision: precision
 * @sized: sized
 * Return: number of chars
 */
int print_pointer(va_list lists, char buffer[], int flag,
		int wdth, int precision, int sized)
{
	char x_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, leg = 2, padd_start = 1;
	unsigned long num_add;

	char m_to[] = "0123456789abcdef";
	void *add = va_arg(lists, void *);

	UNUSED(wdth);
	UNUSED(sized);

	if (add == NULL)
		return (write(1, "(nil)", 5));
		buffer[BUFF_SIZE - 1] = '\0';
		UNUSED(precision);
		num_add = (unsigned long)add;

		while (num_add > 0)
		{
			buffer[ind--] = m_to[num_add % 16];
			num_add /= 16;
			leg++;
		}
		if ((flag & F_ZERO) && !(flag & F_MINUS))
			padd = '0';
		if (flag & F_PLUS)
			x_c = '+', leg++;
		else if (flag & F_SPACE)
			x_c = ' ', leg++;
		ind++;

		return (write_pointer(buffer, ind, leg, wdth, flag, padd, x_c, padd_start));
}
/**
 * print_non_printable - prints ascii
 * @lists: list of argumetns
 * @buffer: buffer array to handle print
 * @flag: calculate
 * @wdth: widtth
 * @precision: precion
 * @sized : siz of specifier
 * Return: number
 */
int print_non_printable(va_list lists, char buffer[], int flag,
		int wdth, int precision, int sized)
{
	int i = 0, offset = 0;
	char *str = va_arg(lists, char *);

	UNUSED(flag);
	UNUSED(wdth);
	UNUSED(precision);
	UNUSED(sized);
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);
		i++;
	}
	buffer[i + offset] = '\0';
	return (write(1, buffer, i + offset));
}
/**
 * print_reverse - prints reverse string
 * @lists: lsit of arguments
 * @buffer: buffer
 * @flag: flag
 * @wdth: width
 * @precision: precision
 * @sized: size
 * Return: 1
 */
int print_reverse(va_list lists, char buffer[], int flag,
		int wdth, int precision, int sized)
{
	char *str;
	int j, cnt == 0;

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(wdth);
	UNUSED(sized);
	str = va_arg(lists, char *);
	if (str == NULL)
	{
		UNUSED(precision);
		str = ")Null(";
	}
	for (j = 0, str[j]; j++)
		;
	for (j = j - 1; j >= 0; j--)
	{
		char t = str[j];

		write(1, &t, 1);
		cnt++;
	}
	return (cnt);
}
/**
 * print_rot13string - prints
 * @lists: list
 * @wdth: width
 * @precision: precision
 * @sized: size
 * @buffer: buffwr
 * @flag: activate
 * Return: number
 */
int print_rot13string(va_list lists, char buffer[], int flag,
		int wdth, int precision, int sized)
{
	char u;
	char *str;
	unsigned int ii, jj;
	int cnt = 0;
	char i[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrsuvwxyz";
	char o[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(lists, char *);
	UNUSED(buffer);
	UNUSSED(flag);
	UNUSED(wdth);
	UNUSED(precision);
	UNUSED(sized);

	if (str == NULL)
		str = "(AHYY)";
	for (ii = 0; str[ii]; ii++)
	{
		for (jj = 0; i[jj]; jj++)
		{
			if (i[jj] == str[ii])
			{
				u = o[jj];
				write(1, &u, 1);
				cnt++;
				break;
			}
		}
		if (!i[jj])
		{
			u = str[ii];
			write(1, &u, 1);

			cnt++;
		}
	}
	return (cnt);
}
