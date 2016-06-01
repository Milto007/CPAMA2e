/* project 8.1
 * modify repdigit.c program of section 8.1 so that is shows which digits
 * (if any) were repeated:
 * > Enter a number: 939577
 * > Repeated digit(s): 7 9
 */
 
#include <stdbool.h> /* C99 only */
#include <stdio.h>

int main(void) {
    // create flag for presence and array to track which are repeated
    bool present = false, digit_seen[10][2] = {false};
    int digit, i;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    // go through number and mark if num is seen in row 0, repeat in row 1
    while (n > 0) {
        digit = n % 10;
        if (!digit_seen[digit][0]) {
            digit_seen[digit][0] = true;
            n /= 10;
        } else if (!digit_seen[digit][1]) {
            digit_seen[digit][1] = true;
            n /= 10;
        }
    }

    for (i = 0; i < sizeof(digit_seen) / sizeof(digit_seen[0]); i++) {
        // loop through row 1 and print the digit of any 'true'
        if (digit_seen[i][1]) {
            // mark flag if repeated digit exists
            present = true;
            printf("Repeated digit(s): ");
            // repeated digits present, print marked digits
            for (; i < sizeof(digit_seen) / sizeof(digit_seen[0]); i++) {
                if (digit_seen[i][1])
                    printf("%d ", i);
            }
        }
    }

    // if the presence flag is true, repeated digits, else no repeated digits
    if (present)
        printf("\n");
    else
        printf("No repeated digits.\n");

    return 0;
}
