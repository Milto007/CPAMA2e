/* problem 7.14
 * does the following statement always compute the frational part of f
 * correctly (assuming that f and frac_part are float variables)?
 *
 * >    fract_part = f (int) f;
 * 
 * If not, what's the problem?
 */

#include <stdio.h>

int main(void) {
    float f, frac_part;

    /*
     * in some cases, the number cannot be represented very well
     * due to the finite nature of hardware. this mean that in some
     * cases, the conversion to an int will work, but the original
     * float number is not accurate and thus a subtraction will
     * result in 0 rather than the real fraction. To prove this, 
     * try using a double in an instance where this doesn't work
     *
     * Offical answer: No. Converting f to int will fail if the value
     * stored in f exceeds the largest value of type int.
     */
    f = 1000000000.999;
    printf("the number is %f, int is %d  and the result is %f\n", 
            f, (int) f, f - (int) f);

    double d, new_frac;
    d = 1000000000.999;
    printf("the number is %f, int is %d, result is %f\n",
            d, (int) d, d - (int) d);

    return 0;
}

