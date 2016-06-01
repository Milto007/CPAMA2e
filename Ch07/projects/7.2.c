/* project 7.2
 * modify the square2.c program of section 6.3 so that it pauses after
 * every 24 squares and displays the follwing message:
 * > Press enter to continue...
 * after displaying the message, the program should use getchar to
 * read a character. getchar won't allow the program to continue
 * until the user presses the Enter key.
 */

#include <stdio.h>

int main(void) {
    int i, n;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);
    // must read the carriage return first entered with number
    getchar();

    for (i = 1; i <= n; i++) {
        if (i % 24 == 0) {
            printf("Press the Enter key...");
            // no need to check for \r since Enter is necessary?
            getchar();
        }
        printf("%10d%10d\n", i, i * i);
    }

    return 0;
}
