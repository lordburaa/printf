#include "main.h"

int print_char(va_list types, char buffer[])
{
	char c = va_arg(types, int);
	return (write(1, c, 1));
}

int print_string(va_list types)
{
	int leng++;
	char *ptr = va_arg(types, char *);
	
	while (str[leng] != '\0')
		leng++;

	return (write(1, ptr, leng));
}
