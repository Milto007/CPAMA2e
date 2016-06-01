/* probelm 7.13
 * assume that a program contains the following declarations
 * >    char c = '\1';
 * >    short s = 2;
 * >    int i = -3;
 * >    long m = 5;
 * >    float f = 6.5f;
 * >    double d = 7.5;
 *
 * Give the value and type of each expression listed below
 * (a) c * i    (c) f / c   (e) f - d
 * (b) s + m    (d) d / s   (f) (int) f
 */

#include <stdio.h>

int main(void) {
    char c = '\1'; // decimal value 1, octal value 1, hex value 0x1
    short s = 2;
    int i = -3;
    long m = 5;
    float f = 6.5f;
    double d = 7.5;

    /* (a)
     * c will be converted to int, result is an int
     * c * i == 1 * -3 == -3
     */
    printf("part a is %d\n", c * i);

    /* (b)
     * s will be converted to a long, result is a long
     * s + m == 2 + 5 = 7;
     */
    printf("part b is %ld\n", s + m);

    /* (c)
     * c will be converted to a float, result is a float
     * note: printf converts to a double for printing
     */
    printf("part c is %f\n", f / c); 

    /* (d)
     * s will be converted to a double, result is a double
     */
    printf("part d is %f\n", d / s);

    /* (e)
     * f will be converted to a double, result is a double
     */
    printf("part e is %f\n", f - d);

    /* (f)
     * f is casted to an int, result is an int
     */
    printf("part f is %d\n", (int) f);

    return 0;
}
