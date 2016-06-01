/* project 7.9
 *
 * write a program that asks the user for a 12-hour time, then displays
 * the time in a 24-hour form:
 * >    Enter a 12-hour time: 9:11 PM
 * >    Equivalent 24-hour time: 21:11
 * See Programming Project 8 for a description of the input format
 */

#include <stdio.h>

int main(void) {
    char half;
    int hour, minute, result;

    printf("Enter a 12-hour time: ");
    scanf("%d:%d %c", &hour, &minute, &half);

    // test for am or pm, adjust hour as necessary
    if (half == 'a' || half == 'A') {
        // ensures 12 am is shown as 00
        hour = hour % 12;
    } else {
        // ensures 12 pm is shown as 12, others increase by 12
        hour = (hour % 12) + 12;
    }

    // print result
    printf("Equivalent 24-hour time: %.2d:%.2d\n", hour, minute);

    return 0;


}
