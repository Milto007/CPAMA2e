/* problem 7.12
 * suppose that i is a variable of type int, f is a variable of type
 * float, and d is a variable of type double. explain what conversions
 * take place during the execution of the following statement:
 * >    d = i + f;
 */

#include <stdio.h>

int main(void) {
    /*
     * first, i and f are converted to the same type. In this case,
     * i is converted to a float.
     * Then, the expression is executed. Finally, the result is
     * converted to a double and saved in the variable d.
     */

    int i = 1;
    float f = 1.1f;
    double d;

    unsigned int sz_d;

    printf("i is %lu, f is %lu, and d is %lu\n", 
            sizeof(i), sizeof(f), sizeof(d));

    d = i + f;
    sz_d = sizeof(i + f);
    printf("the expression has size %u\n", sz_d);

    printf("The result is %f which has size %lu\n", d, sizeof(d));

    return 0;
}
