/* project 7.4
 * write a program that translates an alphabetic phone number into
 * numeric form:
 * > Enter a phone number: CALLATT
 * > 2255288
 *
 * in case you don't have a telephone nearby, here are the letters:
 * 2=ABC
 * 3=DEF
 * 4=GHI
 * 5=JKL
 * 6=MNO
 * 7=PQRS
 * 8=TUV
 * 9=WXYZ 
 *
 * if the original phone number contains nonalphanumeric characters
 * (digits or punctuation, for example), leave them unchanged.
 *
 * > Enter phone number: 1-800-COL-LECT
 * > 1-800-265-5328
 *
 * you may assume that any letters entered by the user are upper case
 */

#include <stdio.h>
#include <ctype.h>

int main(void) {
    
    char ch;

    // prompt user
    printf("Enter a phone number: ");

    // loop until then end of the line
    while ((ch = getchar()) != '\n') {
        ch = toupper(ch);
        // if a letter, change to appropriate number, else print as is
        if (ch >= 'A' && ch <= 'Z') {
           switch (ch){
                case 'A': case 'B': case 'C':
                   ch = 2;
                   break;
                case 'D': case 'E': case 'F':
                   ch = 3;
                   break;
                case 'G': case 'H': case 'I':
                   ch = 4;
                   break;
                case 'J': case 'K': case 'L':
                   ch = 5;
                   break;
                case 'M': case 'N': case 'O':
                    ch = 6;
                    break;
                case 'P': case 'Q': case 'R': case 'S':
                   ch = 7;
                   break;
                case 'T': case 'U': case 'V':
                   ch = 8;
                   break;
                case 'W': case 'X': case 'Y': case 'Z':
                    ch = 9;
                    break;
            }
            // print as decimal number
            printf("%d", ch);
        } else {
            // not letter, print as is
            printf("%c", ch);
        }
    }
    // print a newline at end
    printf("\n");

    return 0;
}
