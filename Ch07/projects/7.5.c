/* project 7.5
 * in the SCRABBLE Crossword Game, players form words using small tiles,
 * each containing a letter and a face value. The face value varies
 * from one letter to another based on the letter's rarity. Here
 * are the face values:
 * 1: AEILNORSTU
 * 2: DG
 * 3: BCMP
 * 4: FHVWY
 * 5: K
 * 8: JX
 * 10: QZ
 * write a program that comutes the value of a word by summing the 
 * values of its letters:
 *
 * > Enter a word: pitfall
 * > Scrabble value: 12
 *
 * your program should allow any mixture of lower-case and upper-case 
 * letters in the word. Hint: use the toupper library function.
 */

#include <stdio.h>
#include <ctype.h>

int main(void) {

    char ch;
    int sum = 0;

    // prompt user
    printf("Enter a word: ");

    // loop until then end of the line
    while ((ch = getchar()) != '\n') {
        ch = toupper(ch);

        // only leters give points
        if (ch >= 'A' && ch <= 'Z') {
            switch (ch) {
                case 'D': case 'G':
                    sum += 2;
                    break;
                case 'B': case 'C': case 'M': case 'P':
                    sum += 3;
                    break;
                case 'F': case 'H': case 'V': case 'W': case 'Y':
                    sum +=4;
                    break;
                case 'K':
                    sum +=5;
                    break;
                case 'J': case 'X':
                    sum += 8;
                    break;
                case 'Q': case 'Z':
                    sum += 10;
                    break;
                default:
                    // default is 1 point letters
                    sum++;
                    break;
            }
        }
    }
    // print the final sum
    printf("Scrabble value: %d\n", sum);

    return 0;
}

