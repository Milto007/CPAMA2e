/* write a program that prints the values of sizeof(int), 
 * sizeof(short), sizeof(long), sizeof(float), sizeof(double), and
 * sizeof(long double).
 */

#include <stdio.h>

int main(void) {
    int i = 0;
    short s = 0;
    long l = 0;
    float f = 0.0f;
    double d = 0.0;
    long double ld = 0.0;

    // the result of a sizeof() call is a long unsigned int
    // which we will cast to int for C89 compatilbility
    // for C99, can avoid casting and use %zu directly
    printf("sizeof(int) is %d\n", (int) sizeof(int));
    printf("sizeof(short) is %d\n", (int) sizeof(short));
    printf("sizeof(long) is %d\n", (int) sizeof(long));
    printf("sizeof(float) is %d\n", (int) sizeof(float));
    printf("sizeof(double) is %d\n", (int) sizeof(double));
    printf("sizeof(long double) is %d\n", (int) sizeof(long double)); 

    return 0;
}
