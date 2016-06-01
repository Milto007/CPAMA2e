/* modify programming project 6 from chapter 3 so that the user may
 * add, subtract, multiply, or divide two fractions (by entering
 * either +, -, *, or / between fractions).
 */

/* project 3.6
 * modify addfrac.c program of section 3.2 so that the user enters
 * both fractions at the same time, separated by a plus sign:
 * > Enter two fractions separated by a plys sign: 5/6+3/4
 * > The sum is 38/26
 */

/* Adds two fractions */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int num1, denom1, num2, denom2, result_num, result_denom;
    char ch;

    // ask user for input in correct form
    printf("Enter fractions in form num1/denom1<op>num2/denom2:  ");
    
    // interpret user input
    scanf("%d/%d%c%d/%d", &num1, &denom1, &ch, &num2, &denom2);

    // determine operation and calc result
    switch (ch) {
        case '+':
            result_num = num1 * denom2 + num2 * denom1;
            result_denom = denom1 * denom2;
            break;
        case '-':
            result_num = num1 * denom2 - num2 * denom1;
            result_denom = denom1 * denom2;
            break;
        case '*':
            result_num = num1 * num2;
            result_denom = denom1 * denom2;
            break;
        case '/':
            result_num = num1 * denom2;
            result_denom = denom1 * num2;
            break;
        default:
            printf("Incorrect input.\n");
            exit(1);
    }
    // print result
    printf("The sum is %d/%d\n", result_num, result_denom);

    return 0;
}
