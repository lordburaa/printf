#ifndef MAIN_P
#define MAIN_P



/** HEADER FILE ***/
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)
/********** STRUTRE *******/

typedef struct {
	char format;
	int (*ptr)(va_list list, char buffer[], int *buff_ind);
} format_t;


int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buff_ind);



/**** PRINT CHAR ******/
int print_char(va_list types, char buffer[], int *buff_ind);
int print_string(va_list types, char buffer[], int *buff_ind);
int print_percent(va_list types, char buffer[], int *buff_ind);



/****************WRITE HANDLE ******************/
int handle_wchar(char c);



/** HABDLE PRINT **/
int handle_print(const char *format, int *index, va_list list, char buffer[], int *buff_ind);


#endif
