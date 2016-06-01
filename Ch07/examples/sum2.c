/* Sums a series of numbers (using long variables) */

#include <stdio.h>

int main(void) {
    long n, sum = 0;

    printf("This program sums a series of integers.\n");
    printf("Enter integers (0 to terminate): ");

    scanf("%ld", &n);
    while (n != 0) {
        sum += n;
        scanf("%ld", &n);
    }
    // declared n and sum to be long but changed scanf and printf to
    // %ld instead of %d
    printf("The sum is: %ld\n", sum);

    return 0;
}
