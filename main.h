#ifndef MAIN_P
#define MAIN_P



/** HEADER FILE ***/
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

/** SIZE **/

#define S_LONG 2
#define S_SHORT 1
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
int print_int(va_list types, char buffer[], int *buff_ind);



/**** LOW LEVEL ***/
int print_binary(va_list types, char buffer[], int *ind);


/****************WRITE HANDLE ******************/
int handle_wchar(char c);
int write_number(int is_negative, int *ind, char buffer[], int length);
int write_num(int *ind, char buffer[], int length);


/** HABDLE PRINT **/
int handle_print(const char *format, int *index, va_list list, char buffer[], int *buff_ind);


#endif
