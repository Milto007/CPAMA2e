/* Problem 7.1. From section 7.1
 * Give decimal value of each of the following integer constants 
 * (a) 077
 * (b) 0x77
 * (c) 0XABC
 */

#include <stdio.h>
int main(void) {


    /* (a)
     * 7 * 8^0 == 7 * 1 == 7;
     * 7 * 8^1 == 7 * 8 == 56;
     * 0 * 8^2 == 8;
     *
     * 7 + 56 == 63;
     */

    int my_a = 63;
    int actual_a = 077;

    printf("My answer for (a) is %d\n", my_a);
    printf("The decimal value of (a) is %d\n", actual_a);

    /* (b)
     * 7 * 16^0 == 7 * 1;
     * 7 * 16^1 == 7 * 16;
     *
     * (7 * 1) + (7 * 16);
     */

    int my_b = (7 * 1) + (7 * 16);
    int actual_b = 0x77;

    printf("My answer for (b) is %d\n", my_b);
    printf("The decimal value of (b) is %d\n", actual_b);

    /* (c)
     * C = 12 * 16^0 == 12 * 1;
     * B = 11 * 16^1 == 11 * 16;
     * A = 10 * 16^2;
     *
     * 12 + (11 * 16) + (10 * 16 * 16);
     */

    int my_c = 12 + (11 * 16) + (10 * 16 * 16);
    int actual_c = 0XABC;

    printf("My answer for (c) is %d\n", my_c);
    printf("The decimal value of (c) is %d\n", actual_c);

    return 0;
}

