#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <string.h>

int _printf(const char *format, ...);
int print_integer(va_list arglist);

#endif /* MAIN_H */

