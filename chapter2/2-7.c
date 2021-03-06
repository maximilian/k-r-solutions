/* Exercise 2-7
 * Write a function invert(x,p,n) that returns x with the n bits
 * that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving
 * the others unchanged.
 */

#include <stdio.h>
#include <stdlib.h>

unsigned invert(unsigned x, int p, int n);
int main()
{
	printf("%u\n", invert(120, 4, 2));

    return 0;
}

unsigned invert(unsigned x, int p, int n){

    unsigned mask;


    /* Mask the bits we want and shift to desired position */
    mask = ~(~0 << n) << (p + 1 - n);

    /* Exclusive OR to invert bits */
    return x ^ mask;
    }
