/* project 7.10
 * write a program that counts the number of vowels (a, e, i, o, u) in a sentece:
 * > Enter a sentence: And that's they way it is.
 * > Your sentence contains 6 vowels.
 */

#include <stdio.h>
#include <ctype.h>

int main(void) {
    int total = 0;
    char ch;

    printf("Enter a sentence: ");
    ch = getchar();
    while (ch != '\n')
    {
        ch = toupper(ch);

        switch (ch){
            case 'A': case 'E': case 'I': case 'O': case 'U':
                total += 1;
        }
        ch = getchar();
    }

    printf("Your sentence contains %d vowels\n", total);

    return 0;
}
