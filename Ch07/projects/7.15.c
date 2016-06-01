/* project 7.15
 * write a program that computes the factorial of a positive integer:
 * > Enter a positive integer: 6
 * > Factorial of 6: 720
 *
 * (a) use a `short` variable to store the value of a factorial. What
 * is largest value of `n` for which the program correctly prints
 * factorial of `n`?
 * (b) repeat part (a) using an `int` variable instead.
 * (c) repeat part (a) using a `long` variable instead.
 * (d) repeat part (a) using a `long long` variable instead (if your
 * compiler supports the `long long` type).
 * (e) repeat part (a) using a `float` variable instead
 * (f) repeat part (a) using a `double` variable instead
 * (g) repeat part (a) using a `long double` variable instead
 *
 * in cases (e)-(g), the program will display a close approximation
 * of the factorial, not necessarily the exact valuej
 */

#include <stdio.h>

int main(void) {
    int usr_input, tmp_input;
    int max_short = 7, max_int = 12, max_long = 20, max_long_long = 20;
    int max_float = 34, max_double = 170, max_long_double = 1754;
    short int   result_short = 1;
    int         result_int = 1;
    long        result_long = 1;
    long long   result_long_long = 1;
    float       result_float = 1;
    double      result_double = 1;
    long double result_long_double = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &usr_input);
    
    // short int
    tmp_input = usr_input;

    while (abs(tmp_input) > 0) {
        result_short *= tmp_input;
        tmp_input--;
    }

    // int
    tmp_input = usr_input;

    while (abs(tmp_input) > 0) {
        result_int *= tmp_input;
        tmp_input--;
    }

    // long 
    tmp_input = usr_input;

    while (abs(tmp_input) > 0) {
        result_long *= tmp_input;
        tmp_input--;
    }

    // long long  
    tmp_input = usr_input;

    while (abs(tmp_input) > 0) {
        result_long_long *= tmp_input;
        tmp_input--;
    }

    // float 
    tmp_input = usr_input;

    while (abs(tmp_input) > 0) {
        result_float *= tmp_input;
        tmp_input--;
    }
    
    // double 
    tmp_input = usr_input;

    while (abs(tmp_input) > 0) {
        result_double *= tmp_input;
        tmp_input--;
    }
    // long double 
    tmp_input = usr_input;

    while (abs(tmp_input) > 0) {
        result_long_double *= tmp_input;
        tmp_input--;
    }

    printf("Factorial of %d using a short int:  %d\n", usr_input, result_short);
    printf("Factorial of %d using a int:        %d\n", usr_input, result_int);
    printf("Factorial of %d using a long int:   %ld\n", usr_input, result_long);
    printf("Factorial of %d using a long long:  %lld\n", usr_input, result_long_long);
    printf("Factorial of %d using a float:      %f\n", usr_input, result_float);
    printf("Factorial of %d using a double:     %lf\n", usr_input, result_double);
    printf("Factorial of %d using a long double: %Lf\n", usr_input, result_long_double);

    printf("\n");

    printf("Largest input using short int is    %d\n", max_short);
    printf("Largest input using int is          %d\n", max_int);
    printf("Largest input using long int is     %d\n", max_long);
    printf("Largest input using long long is    %d\n", max_long_long);
    printf("Largest input using float is        %d\n", max_float);
    printf("Largest input using double is       %d\n", max_double);
    printf("Largest input using long double is  %d\n", max_long_double);

    return 0;
}
