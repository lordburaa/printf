#ifndef MAIN_P
#define MAIN_P

/** HEADER FILE ***/
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


#define UNUSED(x) (void)(x)
/********** STRUTRE *******/

typedef struct {
	char format;
	int (*ptr)(va_list list);
} format_t;


int _printf(const char *format, ...);



/**** PRINT CHAR ******/
int print_char(va_list types);
int print_string(va_list types);
int print_percent(va_list types);



/****************WRITE HANDLE ******************/
int handle_wchar(char c);



/** HABDLE PRINT **/
int handle_print(const char *format, int *indext, va_list list);


#endif
