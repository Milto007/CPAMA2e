/* problem 7.6
 * for each of the following items of data, specify which one of the
 * types char, short, int, or long is the smallest one
 * guaranteed to be large enough to store the item.
 * (a) days in a month
 * (b) days in a year
 * (c) minutes in a day
 * (d) seconds in a day
 */

#include <stdio.h>

int main(void) {
    /* (a)
     * max days in a month = 31. char is smallest
     */

    /* (b)
     * max days in a year = 366, short is smallest
     */

    /* (c)
     * minutes in a day = 60 * 24 == 1440, short is smallest
     */

    /* (d)
     * seconds in a day = 1440 * 60 == 86,400, int is smallest
     */

    char a = 31;
    short b = 366;
    short c = 1440;
    int d = 86400;

    printf("a is %d, b is %d, c is %d, d is %d\n", a, b, c, d);

    return 0;
}
