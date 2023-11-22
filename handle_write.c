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
