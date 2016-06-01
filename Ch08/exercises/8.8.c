/* exercise 8.8
 * write a declaration for a two-dimensional array named temperature_readings that
 * stores one month of hourly temperature readings. (for simplicity, assume that 
 * a month has 30 days.) the rows of the array should represent days of the month; 
 * the columns should represent hours of the day
 */

#include <stdio.h>

int main(void) {
    double temperature_readings[30][24];

    int i, j;

    for (i = 1; i < 31; i++){
        printf("This is day %d. ", i);
        for (j = 0; j < 24; j++) {
            printf("hour %d ", j);
        }
        printf("\n");
    }

    return 0;
}
