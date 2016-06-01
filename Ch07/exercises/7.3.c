/* problem 7.3
 * which of the following are not legal types in C?
 * (a) short unsigned int
 * (b) short float
 * (c) long double
 * (d) unsigned long
 */

#include <stdio.h>

int main(void) {
    /* (a) valid
     * (b) invalid - only int can be short
     * (d) valid - can double be long?
     * (e) valid
     */

    short unsigned int a = 1;
    //short float b = 1;        // produces warning during compilation
    long double c = 1;
    unsigned long d = 1;

    return 0;
}
