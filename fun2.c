#include "main.h"
/** 
 * print_poninter - prints the calie of
 * @list: lisst
 * @buffer: buffer
 * @flag: flag
 * @wdth: width
 * @precision: precision
 * @sized: sized
 * Return: number of chars
 */
int print_pointer(va_list list, char buffer[], int flag, int wdth, int precison, int sized)
{
	char x_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, leg = 2, padd_start = 1;

	unsigned long num_ad;
	char map_tp[] = "0123456789abcdef";
	void *add = va_arg(list, void *);

	UNUSED(wdth);
	UNUSED(sized);

	if (add == NULL)
		return (write(1, "(nil)", 5));
		buffer[BUFF_SIZE - 1] = '\0';
		UNUSED(precison);
		num_ad = (unsigned long)add;

		while (num_ad > 0)
		{
			buffer[ind--] = map_to[num_ad % 16];
			num_ad /= 16;
			leg++;
		}
		if ((flag & F_ZERO) && !(flag & F_MINUS))
			padd = '0';
		if (flag & F_PLUS)
			x_c = '+', leg++;
		else if (flag & F_SPACE)
			x_c = ' ', leg++;
		ind++;

		return (write_pointer(buffer, ind , leg, wdth, flag, padd, x_c, padd_start));
	
}
/** 
 * print_non_printable - prints ascii 
 * @types: list of argumetns
 * @buffer: buffer array to handle print
 * @flags: calculate
 * @width: widtth
 * @precison: precion
 * @size : siz of specifier
 * Return: number
 */
int print_non_printable(va_list list, char buffer[], int flag, int wdth, int precison , int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(list, char *);
	UNUSED(flag);
	UNUSED(wdth);
	UNUSED(precison);
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
 * @types: lsit of arguments
 * @buffer: buffer
 */
int print_reverse(va_list list, char buffer[], int flag, int wdth, int precsion, int sized)
{
	char *str;
	int j, cnt == 0;
	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(wdth);
	UNUSED(sized);
	str = va_arg(list, char *);
	 if (str == NULL);
	 {
		 UNUSED(precision);
		 str = ")Null(";
	 }
	 for (int j = 0, str[j]; j++)

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
 * @list: list
 * @wdth: width
 * @precision: precision
 * @sized: size
 * @buffer: buffwr
 * @flag: activate
 * Return: number
 */
int print_rot13string(va_list list, char buffer[], int flag, int wdth, int precision, int sized)
{
	char u;
	char *str;
	unsigned int ii, jj;
	int cnt = 0;
	char i[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrsuvwxyz";
	char o[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSSED(flag);
	UNUSED(wdth);
	UNUSED(precision);
	UNUSED(sized);

	if (str == NULL)
		str = "(AHYY)";
	for (ii = 0; str[ii]; ii++)
	{
		for (jj = 0; in[jj]; jj++)
		{
			if (in[jj] == str[ii])
			{
				u = o[jj];
				write(1, &u, 1);
				cnt++;
				break;
			}
		}
		if (!i[j])
		{
			u = str[ii];
			write(1, &u, 1);

			cnt++;
		}
	}
	return (cnt);
}
