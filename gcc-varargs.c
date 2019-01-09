/*
 *
 * gcc-varargs.c - Passing a vairable number of parameters.
 *
 * Copyright(C) 2018   MEJT
 *
 * Demonstrates how to pass a vairable mumber of parameters to a function.
 *
 * Compile using 'cc varargs'
 * and link with 'link varargs, sys$library:vaxcrtl.olb/lib'
 *
 * This  program is free software: you can redistribute it and/or modify  it
 * under  the  terms of the GNU General Public License as published  by  the
 * Free  Software  Foundation, either version 3 of the License, or (at  your
 * option) any later version.
 *
 * This  program  is  distributed in the hope that it will  be  useful,  but
 * WITHOUT   ANY   WARRANTY;   without  even   the   implied   warranty   of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
 * Public License for more details.
 *
 * You  should have received a copy of the GNU General Public License  along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * 08 Jan 19         - Initial version - MEJT
 *
 */
  
#include <stdio.h>
#include <stdlib.h> /* EXIT_SUCCESS */
#include <stdarg.h>

int variable(const char *format, ...)
{
    va_list args;
    int count;

    va_start(args, format);

    count = 0;
    while (*format != '\0') {
        switch (*format++) {
            case 's':
                fprintf(stdout, "arg[%d]: %s\n", count, va_arg(args, const char *));
                break;
            case 'd':
                fprintf(stdout, "arg[%d]: %d\n", count, va_arg(args, int));
                break;
            case 'f':
                fprintf(stdout, "arg[%d]: %f\n", count, va_arg(args, double));
                break;
        }
        count += 1;
    }
    va_end(args);
    return 0;
}

void error(const char* format, char* _file, int _line, ... )
{
  va_list arglist;

  fprintf(stderr, "Error: %s line: %d - ", _file, _line);
  va_start(arglist, _line);
  vfprintf(stderr, format, arglist);
  va_end(arglist);
}

int main(void)
{
  variable ("sd", "Example", 3, 3.1416);
  error ("%s %d %s\n", __FILE__, __LINE__, "Operation failed", 100, "times" );
  exit (EXIT_SUCCESS);
}

