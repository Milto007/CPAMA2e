/* problem 7.9
 * suppose that i and j are variables of type int. What is the type 
 * of the expression i / j + 'a'?
 */

#include <stdio.h>

int main(void) {
    /* the expression will be of type int. the char 'a' will be
     * converted to int
     */
    int i;
    int j;

    unsigned int d = sizeof(i / j + 'a');

    printf("the size of the expression is %u\n", d);
    printf("since the size is 4 bytes (32-bits), type is int\n");

    return 0;
}
