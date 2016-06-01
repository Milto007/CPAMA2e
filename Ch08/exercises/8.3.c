/* exercise 8.3
 * write a declaration of an array named weekend containing seven
 * bool values. Include an initializer that makes the first and
 * last balues true; all other values should be false
 */

#include <stdio.h>
#include <stdbool.h>

#define SIZE ((int) sizeof(weekend) / sizeof(weekend[0]))
#define ARR_SIZE 7

int main(void) {
    // initializer array and index variable
    bool weekend[ARR_SIZE] = {1, 0, 0, 0, 0, 0, 1};
    int i;

    // print explanation
    printf("a value of 0 is false; a value of 1 is true\n");

    // loop through array and print value for verification
    for (i = 0; i < SIZE; i++) {
        printf("The value of weekend[%d] is %d\n", i, weekend[i]);
    }

    return 0;
}
