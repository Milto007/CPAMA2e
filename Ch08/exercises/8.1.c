/* exercise 8.1
 * We discussed using the expression sizeof(a) / sizeof(a[0]) to
 * calculate the number of elements in an array. The expression
 * sizeof(a) / sizeof(t) where t is the type of a's elements 
 * would also work, but it's considered an inferior technique. Why?
 */


#include <stdio.h>

int main(void) {
    double a[10];

    /* both methods work but the first is preferred because it
     * is easier to understand its purpose. In addition, it 
     * allows the type of a to change without having to edit
     * the code later. For example, changing from type int
     * to type dounle will produce the same result without editing
     */
    printf("Size of array is %ld (correct)\n", sizeof(a) / sizeof(a[0]));

    // since a was changed from int to double, this is incorrect
    printf("Size of array is %ld (incorrect)\n", sizeof(a) / sizeof(int));

    return 0;
}

