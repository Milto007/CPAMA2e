/* problem 7.7
 * for each of the following character escapes, give the equivalent
 * octal escape. (Assume that the character set is ASCII). Consult 
 * Appendix E if necessary
 */

#include <stdio.h>

int main(void) {
    /* (a)
     * \b is a backspace
     * value is 8 
     * octal value is 010
     */

    char a = '\b';
    printf("part a, my answer is 10\n");
    printf("part a, decimal value is %d, octal is %o\n", a, a);

    /* (b)
     * \n is a newline charater
     * decimal value is 10
     * octal value is 012
     */

    char b = '\n';
    printf("part b, my answer is 12\n");
    printf("part b, decimal value is %d, octal is %o\n", b, b);

    /* (c)
     * \r is a carriage return
     * decimal value is 13
     * octal value is 015
     */

    char c = '\r';
    printf("part c, my answer is 15\n");
    printf("part b, decimal value is %d, octal is %o\n", c, c);

    /* (d)
     * \t is a tab
     * decimal value is 9
     * octal value is 011
     */
    
    char d = '\t';
    printf("part d, my answer is 11\n");
    printf("part d, decimal value is %d, octal is %o\n", d, d);

    return 0;
}

