#include "main.h"
/**
 ** handle_wchar - prints a string
 * @c: char types
 * Return: number of char  printed
 */
int handle_wchar(char c)
{
	return (write(1, &c, 1));
}
