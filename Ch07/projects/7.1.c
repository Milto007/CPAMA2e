/* project 7.1
 * the square2.c program of section 6.3 will fail (usually by printing 
 * strange answer) if i * i exceeds the max value of int. run the
 * program and determine the smallest value of n that causes failure.
 * try changing the type of i to short and running the program again.
 * don't forget to update the conversion specifications in the call
 * of printf!. then try long. from these experiments, what can you
 * conclude about the number of bits used to store integer types on
 * your machine?
 */

#include <stdio.h>

int main(void) {

    int i, n;
    /*
    printf("This program prints a table of squares.\n");
    printf("Enter number of entires in table: ");
    scanf("%d", &n);

    for (i = i; i <= n; i++)
        printf("%10d%10d\n", i, i * i);
    */

    i = 46340;      // sqrt(2^31)
    n = i * i;
    printf("largest square int possible is %d, so i is %d\n", n, i);

    short int s, m;
    s = 181;        // sqrt(2^15)
    m = s * s;
    printf("largest square short possible is %d, so i is %d\n", m, s);

    long int l, o;
    l = 3037000499; // sqrt(2^63)
    o = l * l;
    printf("largest square long possible is %ld, so i is %ld\n", o, l);

    return 0;
}
