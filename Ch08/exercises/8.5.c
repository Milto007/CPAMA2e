/* exercise 8.5
 * the Fibonacci numners are 0, 1, 1, 2, 3, 4, 8, 13, ... where each
 * number is the sum of the two preceding numbers. write a program
 * fragment that declares an array named fib_numbers of length 40
 * and fills the array with the first 40 Fibonacci numners. Hint:
 * fill in the first two numbers individually, then use a loop to
 * compute the remaining numbers
 */

#include <stdio.h>

int main(void) {
    // initialze first two numbers
    int first = 0, second = 1, current, i;
    // initialize array
    int fib_numbers[40] = {[0] = first, [1] = second};

    // loop through array and fill in remaining slots
    for (i = 2; i < 40; i++) {
        current = first + second;
        fib_numbers[i] = current;
        first = second;
        second = current;
    }

    // print array contents for verification
    for (i = 0; i < 40; i++) {
        printf("The number in place %d is %d\n", i, fib_numbers[i]);
    }

    return 0;
}


