/* problem 7.10
 * supposed that i is a variable of type int, j is a variable of type
 * long, and k is a variable of type unsigned int. What is the type
 * of the expression i + (int) j * k?
 */

#include <stdio.h>

int main(void) {
    /* first, j would be converted to an int due to casting.
     * then, j * k would be executed which would be an int *
     * and unsigned int resulting in an unsigned int.
     * Finally, it would be added to the int i which would convert
     * i to an unsigned int and the result would be an unsigned int
     */

    int i;
    long j;
    unsigned int k;

    i + (int) j * k;

    i = 1;
    j = 10;
    k = -10;
    
    printf("the result of k and j part is %ld\n", (int) i * j);
    printf("the final result is signed %d or unsigned %u\n", 
            i + (int) j * k, i + (int) j * k); 

    return 0;
}

