#ifndef MAIN_P
#define MAIN_P

/********** STRUTRE *******/

struct ft_c{
	char format;
	int (*format_t)(va_list list);
};


int _printf(const char *format, ...);



/**** PRINT CHAR ******/
int printf_char(va_list types);


/****************WRITE HANDLE ******************/
int handle_write_char(char c);



#endif
