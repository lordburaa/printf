#include "main.h"
/**
 * handle_wchar - prints a string
 * @c: char types
 * Return: number of char  printed
 */
int handle_wchar(char c)
{
	char buffer[2];
	int i = 0;

	buffer[i] = c;
	i++;
	buffer[i] = '\0';
	return (write(1, &buffer[0], 1));
}

int write_number(int is_negative, int *ind, char buffer[])
{	
	
	UNUSED(is_negative);
	return (write_num(ind, buffer));
}
/**
 * write_num - write number 
 * @ind: index
 * @buffer: buffer to check
 * @length: length to read from the buffer
 * Return: number of the string writen
 */
int write_num(int *ind, char buffer[])
{

	print_buffer(buffer, ind);
	return(1);
}
