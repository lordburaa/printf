#include "main.h"
/**
 * handle_write_char  - handle string
 * @c: char to be checked
 * Return: the nubmer of the string to writen
 */

int handle_wirte_char(char c)
{	
	char buffer[i++] = c;
	buffer[i] = '\0';

	return (write(1, &buffer[0], 1));
}
