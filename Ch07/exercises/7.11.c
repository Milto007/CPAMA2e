/* problem 7.11
 * suppose that i is a variable of type int, f is a variable of type float,
 * and d is a variable of type doube. what is the type of the expression
 * i * f / d?
 */

#include <stdio.h>

int main(void) {
    /*
     * first, i will be converted to a float and multiplied by f
     * then, the result, a float, will convert to a double and then
     * be divided by d. the final result will be a double.
     */

    int i;
    float f;
    double d;
    i = 1;
    f = 10.0f;
    d = 10.0;

    printf("the result has size %lu\n", sizeof(i * f / d));

    return 0;
}
