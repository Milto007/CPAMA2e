/* exercise 8.2
 * The Q&A section shows how to use a letter as an array subscript.
 * Describe how to use a digit (in character form) as a subscript.
 */

#include <stdio.h>

int main(void) {
    char combined[10];
    char first = '9', second = '4';

    // adjust for offset of numbers by subtracting from '0'
    combined['9' - '0'] = 9;
    combined[second - '0'] = 4;

    // since numbers are all in a row starting with 0, subtracting
    // the character 0 will return a number between 0 and 9

    printf("the number in location %c is %d\n", first, combined[9]); 
    printf("the number in location %c is %d\n", 
            second, combined[second - '0']); 

    return 0;
}
