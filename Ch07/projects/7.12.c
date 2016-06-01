/* project 7.12
 * write a program that evaluates an expression:
 * > Enter an expression: 1+2.5*3
 * > Value of expression: 10.5
 *
 * the operands in the expression are floating-point numbers; the operators
 * are +,-,*, and /. the expression is evaluated from left to right (no 
 * operator takes precedence over any other operator).
 */

#include <stdio.h>

int main(void) {
    // since the number of operators and operands is unknown,
    // perform loop where a two values are computed and saved
    // as the new first value to move on to the next two values
    // until the end of the line
    char op;
    float val1, val2;

    printf("Enter an expression: ");

    // initially scan first operand (num) and operator
    scanf(" %f %c", &val1, &op);
    
    // don't grab next operator until after the loop
    do {
        // in loop scan next operand (num)
        scanf(" %f", &val2);

        // perform operation on both values, save as new val1
        switch(op) {
            case '+':
                val1 += val2;
                break;
            case '-':
                val1 -= val2;
                break;
            case '*':
                val1 *= val2;
                break;
            case '/':
                val1 /= val2;
                break;
        }
        // skip any white space, save next operator in op
        while ((op = getchar()) == ' ')
            ;

    } while (op != '\n');

    printf("Value of expression: %.1f\n", val1);

    return 0;
}
