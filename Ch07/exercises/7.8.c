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
     * hex value is 0x8
     */

    char a = '\b';
    printf("part a, my answer is 0x8\n");
    printf("part a, decimal value is %d, hex is %x\n", a, a);

    /* (b)
     * \n is a newline charater
     * decimal value is 10
     * octal value is 012
     * hex vaue is 0xa
     */

    char b = '\n';
    printf("part b, my answer is 0xa\n");
    printf("part b, decimal value is %d, hex is %x\n", b, b);

    /* (c)
     * \r is a carriage return
     * decimal value is 13
     * octal value is 015
     * hex value is 0xd
     */

    char c = '\r';
    printf("part c, my answer is 0xd\n");
    printf("part b, decimal value is %d, hex is %x\n", c, c);

    /* (d)
     * \t is a tab
     * decimal value is 9
     * octal value is 011
     * hex value is 0x9
     */
    
    char d = '\t';
    printf("part d, my answer is 0x9\n");
    printf("part d, decimal value is %d, hex is %x\n", d, d);

    return 0;
}

