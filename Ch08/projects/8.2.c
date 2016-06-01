/* project 8.2
 * modify repdigit.c program of section 8.1 so that it prints a table showing how
 * many times each digit appears in the number
 * > Enter a number: 41271092
 * > Digit:         0  1  2  3  4  5  6  7  8  9
 * > Occurance:     1  2  2  0  1  0  0  1  0  1
 */
 
#include <stdio.h>

int main(void) {
    // create flag for presence and array to track which are repeated
    int digit, i, digit_seen[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    long long n;

    printf("Enter a number: ");
    // note: number limit determined by long long size
    scanf("%lld", &n);

    // go through number and add 1 to array space for each digit
    while (n > 0) {
        digit = n % 10;
        digit_seen[digit] += 1;
        n /= 10;
    }

    // loop through array and print value at each digit space
    printf("Digit:      0   1   2   3   4   5   6   7   8   9\n");
    printf("Occurances: ");
    for (i = 0; i < sizeof(digit_seen) / sizeof(digit_seen[0]); i++) {
        printf("%d   ", digit_seen[i]);
    }

    printf("\n");
    return 0;
}

