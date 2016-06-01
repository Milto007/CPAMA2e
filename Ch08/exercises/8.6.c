/* exercise 8.6
 * Calculators, watches, and other electronic devices often rely on 
 * seven-segment displays for numerical output. To form a digit, 
 * such devices "turn on" some of the seven segments while leaving
 * others "off":
 *
 *  _       _   _       _   _   _   _   _
 * | |  |    |   | | | |   |     | | | | |
 * | |  |  |-   -| - |  -| |-|   | |-|  -|
 *  -       -   -    |      -       -   
 *
 *  Suppose that we want to set up an array that remembers which
 *  segments should be "on" for each digit. Let's number the segments
 *  as follows:
 *
 *    0
 *    -
 *  5|6|1
 *   |-|
 *  4|3|2
 *    -
 * Here's what the array might look like, with each row representing
 * one digit:
 * const int segments[10][7] = {{1, 1, 1, 1, 1, 1, 0}, ...};
 * I've given you the first row of the initializer, fill in the rest.
 */

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    const bool segments[10][7] = {{1, 1, 1, 1, 1, 1, 0},
                                  {0, 1, 1, 0, 0, 0, 0},
                                  {1, 1, 0, 1, 1, 0, 1},
                                  {1, 1, 1, 1, 0, 0, 1},
                                  {0, 1, 1, 0, 0, 1, 1},
                                  {1, 0, 1, 1, 0, 1, 1},
                                  {1, 0, 1, 1, 1, 1, 1},
                                  {1, 1, 1, 0, 0, 0, 0},
                                  {1, 1, 1, 1, 1, 1, 1},
                                  {1, 1, 1, 1, 0, 1, 1}};
    int i, j;

    // two for loops are needed to go through each element
    for (i = 0; i < 10; i++) {
        printf("row [%d} values are ", i);
        for (j = 0; j < 7; j++) {
            printf("%d", segments[i][j]);
        }
        printf("\n");
    }

    return 0;
}
