#include <stido.h>
#include "main.h"

int handle_wchar(char c)
{
	return (write(1, &c, 1));
}
