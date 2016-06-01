/* which of the following are not legal constants in C? Classify
 * each legal constant as either integer or floating point
 * (a) 010E2
 * (b) 32.1E+5
 * (c) 0790
 * (d) 100_00
 * (e) 3.978e-2
 */

#include <stdio.h>

int main(void) {
    /* (a)
     * 010E2 is a legal floating-point constant
     */

    float a = 010E2;
    printf("checking a is %f\n", a);

    /* (b)
     * 32.1E+5 is a legal floating-point constant
     */

    float b = 32.1E+5;
    printf("checking b is %f\n", b);

    /* (c)
     * 0790 is an illegal integer constant. 9 is not
     * a valid octal number
     */
    
    //int c = 0790;
    // printf("checking c is %d\n", c);     // warns 9 is not valid octal

    /* (d)
     * 100_00 is an illegal integer constant. _ is not a valid 
     * character for an integer
     */

    //int d = 100_00;
    //printf("checking d is %d\n", d);      // warns _00 not valid suffix

    /* (e)
     * 3.978e-2 is a valid floating-point constant
     */

    float e = 3.978e-2;
    printf("checking e is %f\n", e);

    return 0;
}
