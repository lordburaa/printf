#ifndef MAIN_P
#define MAIN_P



/** HEADER FILE ***/
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 1000
#define UNUSED(x) (void)(x)
/********** STRUTRE *******/

typedef struct {
	char format;
	int (*ptr)(va_list list, char buffer[]);
} format_t;


int _printf(const char *format, ...);



/**** PRINT CHAR ******/
int print_char(va_list types, char buffer[]);
int print_string(va_list types, char buffer[]);
int print_percent(va_list types, char buffer[]);



/****************WRITE HANDLE ******************/
int handle_wchar(char c, char buffer[]);



/** HABDLE PRINT **/
int handle_print(const char *format, int *index, va_list list, char buffer[]);


#endif
