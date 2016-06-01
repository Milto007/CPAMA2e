/* which one of the following is not a legal way to write the number 65?
 * Assume that the character set is ASCII
 * (a) 'A'
 * (b) 0b1000001
 * (c) 0101
 * (d) 0x41
 */

#include <stdio.h>

int main(void) {
    /* (a)
     * valid. print using integer conversion identifier %d
     */
    char a = 'A';
    printf("value of part a is %d\n", a);

    /* (b)
     * valid. the 0x is like 0x in hexadecimal for bits
     */
    char b = 0b1000001;
    printf("value of part b is %d\n", b);

    /* (c)
     * valid. stored as octal notation.
     * 1 * 8^0 + 0 * 8^1 + 1 * 8^2 == 8 * 8 + 1 == 64 + 1 == 65;
     */
    char c = 0101;
    printf("value of part c is %d\n", c);

    /* (d)
     * valid. 4 * 16 + 1 == 65.
     */
    char d = 0x41;
    printf("value of part d is %d\n", d);

    return 0;
}
