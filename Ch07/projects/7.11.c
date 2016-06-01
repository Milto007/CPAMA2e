/* project 7.11
 * write a program that takes a first name and last name entered by the 
 * user and displays the last name, a comma, and the first initial
 * followed by a period:
 *
 * > Enter a first and last name: Lloyd Fosdick
 * > Fosdick, L.
 *
 * the user's input may contain extra spaces before the first name, between
 * the first and last names, and after the last name.
 */

#include <stdio.h>
#include <ctype.h>

int main(void) {
    char first, last;

    printf("Enter a first and last name: ");

    // store first initial then ignore the remaining first name
    scanf(" %c", &first);
    while (getchar() != ' ')
        ;

    // get next char and print until end of line
    while ((last = getchar()) != '\n') {
        // ignore any extra spaces before and after last name
        if (last != ' ')
            printf("%c", last);
    }

    // print comma, space, first initial, and period
    printf(", %c.\n", first);

    return 0;
}
