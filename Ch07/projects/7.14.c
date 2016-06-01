/* project 7.14
 * write a program that uses Newton's method to compute the square root of a
 * positive floating-point number:
 * > Enter a positive number: 3
 * > Square root: 1.73205
 *
 * let x be the number entered by the user. Newton's method requires an
 * initial guess y for the square root of x (we'll use y = 1). Successive
 * guesses are found by computing the average of y and y/x. The following
 * table shows how the square root of 3 would be found:
 * --------------------------------------------------------------
 * |    x   |   y       |       x/y     |   avg of y and x/y    |
 * --------------------------------------------------------------
 * |    3   |   1       |       3       |   2                   |
 * |    3   |   2       |       1.5     |   1.75                |
 * |    3   |   1.75    |       1.71429 |   1.73214             |   
 * |    3   |   1.73214 |       1.73196 |   1.73205             |   
 * |    3   |   1.73205 |       1.73205 |   1.73205             |
 * --------------------------------------------------------------
 *
 *  note that the values of y get progressively closer to the true
 *  square root of x. for greater accuracy, your program should use variables
 *  of type `double` rather than `float`. have the program terminate when
 *  the absolute value of the difference between the old value of y
 *  and the new value of y is less than the product of 0.00001 and y.
 *  Hint: call the `fabs` function to find the absolute valyue of a `double`.
 *  (You'll need to include the <math.h> header a the beginningn of your
 *  program in order to use `fabs`).
 */

#include <stdio.h>
#include <math.h>

#define LIMIT 0.00001

int main(void) {
    double x, y_0, y_1, avg;

    printf("Enter a positive number: ");
    scanf("%lf", &x);
    
    // initialize guess and sqrt values
    y_0 = 1;
    y_1 = (y_0 + (x / y_0)) / 2;


    while (fabs(y_0 - y_1) > LIMIT) {
        y_0 = y_1;
        y_1 = (y_0 + (x / y_0)) / 2;
    }

    printf("Square root: %.5f\n", y_1);

    return 0;
}
