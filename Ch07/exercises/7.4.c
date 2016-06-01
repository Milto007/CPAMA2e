/* problem 7.4
 * if c is a variable of type char, which one of the following
 * statements is illegal?
 * (a) i += c; i has type int
 * (b) c = 2 * c - 1;
 * (c) putchar(c);
 * (d) printf(c);
 */

#include <stdio.h>

int main(void) {
    char c = 'a';
    /* (a)
     * statement is valid, converts char to int then performs
     * addition. result will be c's ASCII value + i which can be
     * printed as a char again if desired and a valid ASCII value
     */
    int i = 1;
    i += c;
    printf("%c becomes %d which is also %c\n", c, i, i);

    /* (b)
     * statement is valid. converts c to int, performs operations,
     * then converts back to char. note, overflow can occur and
     * may result in invalid ASCII value
     */
    char d; 
    d = 2 * c - 1;
    printf("start with %c then end with %c which may not print\n", c, d);
    printf("int value b is %d\n", d);

    /* (c)
     * statement is valid
     */
    putchar(c);
    printf(" . adding this part to help with printing on terminal\n");

    /* (d)
     * statement is invalid. printf requires formatting information.
     * should be a string in quotes with conversion identifiers for 
     * variables to be substituted
     */

    //printf(c);
    // properly it's 
    printf("the correct way to display part (d) is:\n");
    printf("%c\n", c);

    return 0;
}
