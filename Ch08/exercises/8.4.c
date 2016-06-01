/* exercise 8.4
 * (C99) repeat exercise 8.3 but this time use a designated initializer.
 * make the initializer as short as possible.
 */

#include <stdio.h>
#include <stdbool.h>

#define SIZE ((int) sizeof(weekend) / sizeof(weekend[0]))
#define ARR_SIZE 7

int main(void) {
    // initializer array and index variable
    bool weekend[ARR_SIZE] = {[0] = true, [ARR_SIZE - 1] = true};
    int i;

    // print explanation
    printf("a value of 0 is false; a value of 1 is true\n");

    // loop through array and print value for verification
    for (i = 0; i < SIZE; i++) {
        printf("The value of weekend[%d] is %d\n", i, weekend[i]);
    }

    return 0;
}
