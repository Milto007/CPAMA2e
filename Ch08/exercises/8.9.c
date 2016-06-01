/* exercise 8.9
 * using the array of exercise 8.8, write a program fragment that computes the
 * average temperature for a month (averaged over all days of the month and all
 * hours of the day)
 */

#include <stdio.h>

int main(void) {
    double temperature_readings[30][24];

    int i, j, sum = 0;

    // give values to each element in the array
    for (i = 0; i < 30; i++){
        for (j = 0; j < 24; j++) {
            temperature_readings[i][j] = j;
        }
    }

    // add each element to a sum value
    for (i = 0; i < 30; i++){
        for (j = 0; j < 24; j++) {
            sum += temperature_readings[i][j];
        }
    }

    // print result average by dividing sum by total num of elements
    printf("the average for the month is %f\n", (float) sum / (30 * 24));

    return 0;
}
