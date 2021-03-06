/* Exercise 7-3
 * Revise minprintf to handle more of the
 * other facilities of printf.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int main()
{
    char *a = "Hello world!";
    minprintf("%s", a);
    return 0;
}

/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...)
{
    va_list ap; /* points to each unnamed arg in turn */
    char *p, *sval;
    int ival;
    double dval, uval;
    void *pval;

    va_start(ap, fmt); /* make ap point to 1st unnamed arg */
    for (p = fmt; *p; p++){
        if (*p != '%'){
            putchar(*p);
            continue;
        }

        switch(*++p){
        case 'd':
            ival = va_arg(ap, int);
            printf("%d", ival);
            break;


        case 'f':
            dval = va_arg(ap, double);
            printf("%f", dval);
            break;

        case 's':
            for (sval = va_arg(ap, char *); *sval; sval++)
                putchar(*sval);
            break;

        case 'u':
            uval = va_arg(ap, unsigned int);
            printf("%u", uval);
            break;

        case 'e':
            dval = va_arg(ap, double);
            printf("%e", dval);
            break;

        case 'p':
            pval = va_arg(ap, void *);
            printf("%p", pval);
            break;

        default:
            putchar(*p);
            break;
        }
    }

    va_end(ap); /* clean up when done, must be called at the end */
}
