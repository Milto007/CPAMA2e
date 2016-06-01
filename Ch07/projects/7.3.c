/* project 7.3
 * modify the sum2.c program of section 7.1 to sum a series of
 * double values
 */

#include <stdio.h>

int main(void) {
    // changed type from long to double
    double n, sum = 0;

    printf("This program sums a series of doubles.\n");
    printf("Enter integers (0 to terminate): ");

    // anywhere the conversion specifier said %ld is now %lf
    scanf("%lf", &n);
    while (n != 0) {
        sum += n;
        scanf("%lf", &n);
    }

    printf("The sum is: %lf\n", sum);

    return 0;
}
