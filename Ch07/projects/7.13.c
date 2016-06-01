/* project 7.13
 * write a program that calculates the average word length for a sentence.
 * > Enter a sentence: It was deja vu all over again.
 * > Average word length: 3.4
 *
 * for simplicity, your program should consider a punctuation mark to be
 * part of the word to which it is attached. Display the average word
 * length to one decimal place
 */

#include <stdio.h>

int main(void) {
    char ch;
    int letter_count = 0, space_count = 0;

    printf("Enter a sentence: ");
    while ((ch = getchar()) != '\n') {
        // add to either num of space or num of letters
        switch (ch) {
            case ' ':
                space_count++;
                break;
            default:
                letter_count++;
                break;
        }
    }
    
    // add 1 to num of spaces (word count) since it ends it '\n', not space
    printf("Average word length: %.1f\n", (float) letter_count / (space_count + 1));

    return 0;
}
