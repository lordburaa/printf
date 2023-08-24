#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)

#define BUFF_SIZE 1024

#define F_HASH 8
#define F_ZERO 4
#define F_MINUS 1
#define F_PLUS 2
#define F_SPACE 16



#define S_LONG 2
#define S_SHORT 1
/**
  * struct fmt - struct op
  * @fmt: the format
  * @fn: the functoin associtated
  */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};
/**
 * typedef struct fmt 
 * @fmt: the format
 * @fmt_t:
 functon 
 */
typedef struct fmt fmt_t;
int _printf(const char *forrmat, ...);
int handle_printf(consr char *fmt, int *i, va_list lists, char buffer[], int flag, int wdth, int precison, int sized);

int print_char(va_list lists, char buffer[], int flag, int wdth, int precision, int sized);
int print_string(va_list lists, char buffer[], int flag, int wdth, int precision, int sized);
int print_percent(va_list lists, char buffer[], int flag, int wdth, int precision, int sized);

int pritn_(va_list lists, char buffer[], int flag, int wdth, int precision, int sized);
int print_binary(va_list lists, char buffer[], int flag, int wdth, int precision, int sized);
int print_unsigned(va_list lists, char buffer[], int flag, int wdth, int precision, int sized);
int print_octal(va_list lists, char buffer[], int flag, int wdth, int precison, int sized);
int print_hexadecimal(va_list lists, char buffer[], int flag, int wdth, int precision, int sized);
int print_hexa_upper(va_list lists, char buffer[], int flag, int wdth, int precision, int sized);
int print_hexa(va_list lists, char buffer[], int flag, int wdth, int precision, int sized);
int print_non_printable(va_list lists, char buffer[], int flag, int wdth, int precision, int sized);
int print_pointer(va_list lists, char buffer[], int flag, int wdth, int precision, int sized);

int get_falgs(const char *format, int *k);
int get_width(const cahr *format, int *k, va_list list);
int get_precision(const char *format, int *k, va_list list);
int get_size(const char *format, in *k);


int print_reverse(va_list lists, char buffer[], int flag, int wdth, int precision, int sized);
int print_rot13string(va_list list, char buffer[], int flag, int wdth, int precision, int sized);

int handle_write_char(char c, char buffer[], int flag, int wdth, int precision, int sized);
int write_number(int is_posistive, int ind, char buffer[], int flag, int wdth, int precision, int sized);
int write_num(int num, char buff[], int flag, int wdth, int precision, int leg, char padd, char extra_c);
int write_pointer( char buffer[], int ind, int leg, int wdth, int flag, char padd, char x_c, int padd_start);

 int write_unsgnd(int is_negative, int ind, char buffer[], int flag, int wdth, int precision , int sized);

 int is_prinable (char);
 int append_hexa_code(char, char[], int);
 int is_digit(char);
 long int convet_size_number(long int num, int size);
 long int convert_size_unsgnd(unsigned long int num, int size);
#endif
