#include <unstid.h>
/**
 * _putchar - write chsr c
 * @c: char
 * Return: 1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
