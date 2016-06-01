/* exercise 8.7
 * Using the shortcuts described in section 8.2, shrink the initializer for the
 * segments array (exercise 8.6) as much as you can
 */

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    const bool segments[10][7] = {{1, 1, 1, 1, 1, 1, 0},
                                  {0, 1, 1},
                                  {1, 1, 0, 1, 1, 0, 1},
                                  {1, 1, 1, 1, 0, 0, 1},
                                  {0, 1, 1, 0, 0, 1, 1},
                                  {1, 0, 1, 1, 0, 1, 1},
                                  {1, 0, 1, 1, 1, 1, 1},
                                  {1, 1, 1},
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
