# 7 Basic Types
This chapter dicusses remaining basic types. Only seen
int and float so far.

## 7.1 Integer Types
Two numeric types:
- integers types
- floating types

Integers are whole numbers, floating types can have fractional part.
Each type can be signed or unsigned. 

> Signed has leftmost bit = 0 for negative, = 1 for positive. 
> 
> largest 16-bit number is:
> 0111 1111 1111 1111
> has value 32,767 (or 2^15 - 1)
> 
> largest 32-bit number is:
> 0111 1111 1111 1111 1111 1111 1111 1111
> has value 2,147,483,647 (or 2^31 - 1)
> 
> By default, integers are signed.

int type is usually 32 bits but varies on CPUs.
long type and short type are integers with more and less bits

These six combinations provide different types:
- short int
- unsigned short int
- int
- unsigned int
- long int
- unsigned long int

Other combos or just synonyms (i. e. long signed int == long int). Order
is communative (i. e. unsigned short int == short unsigned int). 

C standard has certain requirements for ints. For example, 
range of short int <= range of int <= range of long int.

Use <limits.h> header to see ranges

### Integer Types in C99
C99 provides long long int and unsigned long long int due to new 64-bit
processors. Must be at least 64-bits wide.

C99 allows for custom extended integer types (i. e. 128-bit integer types)

### Integer Constants
constants - numbers that appear in the text of a program, not read, 
written, or computed C.

> Octal and Hexadecimal Numbers
> octal written using digits 0-7 representing power of 8
> 237 -> 2*8^2 + 3*8^1 + 7*8^0 = 159
> hexadecimal written using digits 0-9 and letters A-F (for 10-15) 
> representing a power of 16.
> 1AF -> 1 * 16^2 + 10 * 16^1 + 15 * 16^0 = 256 + 160 + 15 = 431

Decimal - contains digits 0-9 but cannot begin with a 0
Octal - contains digits 0-8 but must begin with a 0
Hexadecimal - contains digits 0-9 and letters A-F and must begin with 0x
Note: hex numbers can have uppercase or lowercase letters.

Compiler will try to store number in smallest type (int before 
unsigned int before long int etc.). Force compiler to treat constant
as long integer using L (or l).

15L 0377L 0x7fffL

Similarly, force unsigned using U

15U 03777U 0x7fffU

and the two can be combined to force long unsigned as in 0xffffffffUL
Order of L and U doesn't matter

### Integer Constants in C99
In C99, integer constants that end in LL or ll have type long long int
and adding a U or u before or after the l's is an unsigned long long int

#### Integer Overflow
If arithmetic result is too large to represent, it's called an overflow
Overflow behavior depends on if the integer is signed or unsigned.
Signed:
- program behavior undefined

Unsigned: 
- result is correct answer mod 2^n
where n is the number of bits used to store result

Example:
1 + unsigned 16-bit number 65,535 is guaranteed to be 0

#### Reading and Writing Integers
If overflow is occuring, fix by adjusting int to long int but be sure
to check effect on the rest of the program.

If var is called in printf or scanf, the format string will need to be
changed (%d is only for int).

unsigned integer: use u, o, or x instead of d
- u is for decimal representation
- o is for octal representation
- x is for hex representation
>   unsigned int u;
>
>   scanf("%u", &u);    /* reads    u in base 10   */
>   printf("%u", u);    /* writes   u in base 10  */
>   scanf("%o", &u);    /* reads    u in base 8    */ 
>   printf("%o", u);    /* writes   u in base 8   */
>   scanf("%x", &u);    /* reads    u in base 16   */
>   printf("%x", &u);   /* write    u in base 16   */ 

short integer: use h in front of d, o, u, or x
>   short s;
>   
>   scanf("%hd", &s);
>   printf("%hd", s);

long integer: use l in front of d, o, u, or x
>   long l;
>
>   scanf("%ld", &l);
>   printf("%ld", l);

long long integer: use ll in front of d, o, u, or x
>   long long ll;
>
>   scanf("%lld", &ll);
>   printf("%lld", ll);

### Summing a series of numbers (revisited)
Summing a series of integers could lead to overflow. If integers
are 16 bits long, this could happen:

> This program sums a series of integers.
> Enter integers (0 to terminate): 10000 20000 30000 0
> The sum is: -5536

The correct answer of 60 000 wouldn't fit in an int so overflow
occured. Since it was a signed int, the outcome is undefined. Let's
switch to a long variable

See sum2.c

>   /* Sums a series of numbers (using long variables) */
>
>   #include <stdio.h>
>
>   int main(void) {
>       long n, sum = 0;
>       
>       printf("This program sums a series of integers\n");
>       printf("Enter integers (0 to terminate: ");
>
>       scanf("%ld", &n);
>       while (n != 0) {
>           sum += n;
>           scanf("%ld", &n);
>       }
>       printf("The sum is: %ld\n", sum);
>
>       return 0;
>   }

declared n and sum to be long variables instead of int and
changed specifiers in scanf and printf to %ld instead of %d

## 7.2 Floating Types
C provides three floating types corresponding to different
floating-point formats

- float         single-precision floating point
- double        double-precision floating point
- long double   extended-precision floating point

float is best when precision isn't critical
double provides greater precision, enough for most programs
long double supplies ultimate precision, rarely used

precision of float, double, and long double vary by machine but most
use IEEE 754

> IEEE Standard 754
> provides two primary formats for floating-point numbers
> - single precision (32-bits) 
> - double precision (64-bits)
> numbers are stored in a form of scientific notation with three parts:
> - sign
> - exponent
> - fraction
> num of bits reserved for exponent determines how large numbers can be
> num of bits in fraction determines precision
>
> single-precision format:
> - exponent is 8-bits long
> - fraction is 23-bits
> - sign is 1-bit
> - max value about 3.40 * 10^38 with a precision of 6 decimal digits
> 
> Single extended precision and double extended precision also
> specified but not given number of bits except:
> - single extended type must occupy at least 43 bits 
> - double extended type must occupy at least 79 bits

see <float.h> header file for macros that define characteristics of 
floating types

In C99, floating types have two categories:
- real floating types
-- float
-- double
-- long double
- complex floating types
-- float _Complex
-- double _Complex
-- long double _Complex

### Floating constants
Can be written many ways such as:

> 57.0  57  57.0e0  57E0    5.7e1   5.7e+1  .57e2   570.e-1

if an exponent is present, must be preceded by E or e with an 
optional + or - to indicate sign

by default, floating constants are stored as double-precision numbers
To indicate only single precision is desired, use F (or f) at the end
To indicate double precision is desired, use L (or l) at the end

> 57.0F     vs      57.0L

C99 has a provision for writing floating constants in hex. usually
begins with 0x or 0X. rarely used.

### Reading and writing floating-point numbers
conversion specifiers for single-precision floating-point numbers
are %e, %f, and %g. double and long double require different ones

reading double: use l in front of e, f, or g
>   doube d;
>   
>   scanf("%lf", &d);

use l only in scanf; printf can use e, f, and g for float or doubles
C99 allows use of l in both

reading or writing long doubel: use L in front of e, f, or g
>   long double ld;
>
>   scanf("%Lf", &ld);
>   printf("Lf", ld);

## 7.3 Character Types
character type is char which can vary by machine since each may have
different underlying character sets

> ASCII is most popular character set
> 7-bit code capable of representing 128 characters
> digits 0-9 are represented as codes 011 0000 to 011 1001
> uppercase A to Z are represented as codes 100 0001 to 101 1010
>
> ASCII often extended to a 256 character code called Latin-1

variable of type char can be assigned any single character
>   char ch;
>
>   ch = 'a';   /* lower-case a */
>   ch = 'A';   /* upper-case A */
>   ch = '0';   /* zero         */
>   ch = ' ';   /* space        */

Note: characters are enclosed in single quotes, not double quotes

### Operations on characters
C treats characters as small integers. In ASCII, character 'a' has value
97, 'A' has value 65, '0' has value 48, and ' ' has value 32. 

Character constants have int type instead of char.

When a char appears in a computation, C uses its integer value

>   char ch;
>   int i;
>
>   i = 'a'     /* i is now 97      */
>   ch = 65;    /* ch is now 'A'    */
>   ch = ch + 1 /* ch is now 'B'    */
>   ch++;       /* ch is now 'c'    */

chars can be compared like numbers

>   if ('a' <= ch && ch <= 'z')
>       ch = ch - 'a' + 'A';

These comparisons depend on character set in use so it may vary
across machines.

since chars are used as numbers, these properties can be taken
into account in clever ways

>   for (ch = 'A'; ch <= 'Z'; ch++)

but can lead to meaningless expressions not caught by the compiler

>   'a' * 'b' / 'c'

and can hamper portablility. the for loop example assumes A to Z
have consecutive codes

### Signed and unsigned characters
Since chars can be used as integers, chars exist as signed and unsigned
C standard does not specify if char is signed or unsigned. If sign
matters, best to specify as in:
>   signed char sch;
>   unsigned char uch;

DO NOT ASSUME char IS SIGNED OR UNSIGNED BY DEFAULT

C89 uses term integral types to refer to integers, chars and enumerated
C99 instead expands integer types to include chars and enumerated types
In C99, _Bool is considered unsigned integer type

### Arithmetic types
arithmetic types - integer types and floating types
C89 Integral types:
- char
- signed integer types (signed char, short int, int, long int)
- unsigned integer types (unsigned char, unsigned short int, 
unsigned int, unsigned long int
- enumerated types

C89 Floating types: 
- float, double, long double

C99 Integer types:
- char
- signed integer types, both standard (signed char, short int, int
long int, long long int) and extended
- unsigned integer types, both standard (unsigned char, unsigned short int,
unsigned int, unsigned long int, unsigned long long int, _Bool) and
extended
- enumerated types

C99 Floating types:
- real floating types (float, double, long double)
- complex types (float _Complex, double _Complex, long double _Complex)

### Escape sequences
a char is usually one character in single quotes but special characters
(i. e. newline) can't be written as such. Instead, they are written
using escape sequences.

types: character escape sequences and numeric escapes 

> Alert (bell)          \a
> Backspace             \b
> Form feed             \f
> New line              \n
> Carriage return       \r
> Horiztonal tab        \t
> Vertical tab          \v
> Backslash             \\ 
> Question mark         \?
> Single quote          \'
> Double quote          \"

Numeric escapes are used for the ASCII characters that are not
included in the section above, nonprinting, or beyond the 128 characters

To write a numeric escape:
1. look up char's octal or hex value in a table (ASCII escape char is
decimal val 27, 33 in octal, and 1B in hex)
2. octal escape sequence - use '\' followed by number, 0 is not needed
i. e. \33 or \033
3. hex escape sequence - use '\x' followed by hex number. x is lowercase
i. e. \x1b or \x1B

trigraph squences provide a wat to represent characters such as #, [, ],
\, ^, {, and more that are not on keyboards in certain countries. C99
adds universal character names similar to escape sequences that can
be used in identifiers

### Character-handling functions
A previous example showed how to change a lower-case letter to and upper-
case one, but it was not the best method. Instead, use C's toupper 
library function
>   ch = toupper(ch_);      /* converts ch to upper case */

toupper checks if its argument is a lower-case letter, if so, it returns
the corresponding upper-case letter otherwise it returns the same
argument it was given. The example stores the result in ch

>   if (toupper(ch) == 'A') ..

is another way of handling this idea.

Programs with toupper must include <ctype.h>
>   #include <ctype.h>

### Reading and writing characters using scanf and printf
Use %c conversion specifier in scanf and printf

>   char ch;
>   scanf("%c", &ch);   /* reads a single character */
>   printf("%c", ch);   /* writes a single character */

scanf doesn't skip white-space characters before reading a char. To force
it to skip white space before reading a char, put a space before %c:
>   scanf(" %c", &ch);  /* skips white space, then reads ch */

scanf with a white space will skip zero or more white-space chars.
Use scanf to detect end of an input line
>   do {
>       scanf("%c", &ch);
>   } while (ch != '\n');

when scanf is called the next time, it will read the first char
on the next input line

### Reading and writing characters using getchar and putchar
we can use getchar and putchar instead of scanf and printf. 
putchar writes a single character:
>   putchar(ch);

getchar reads one character and returns it. To save the char, use
assignment to store it in a variable:
>   ch = getchar(); /* reads a character and stores it in ch */

getchar returns an int, not a char. getchar does not skip white spaces

getchar and putchar are much simpler than scanf and printf and implemented
as macros so they are much faster. getchar also allows for clever uses

>   do {
>       scanf("%c", &ch);
>   } while (ch != '\n');

can be written as 

>   do {
>       ch = getchar();
>   } while (ch != '\n');

which can be condensed to 

>   while ((ch = getchar()) != '\n')
>       ;

this loop reads a char, stores it in ch, and tests if not equal to the
new-line character. If so, it continues to the empty body, and then 
reads a character again.

the variable can even be removed

>   while(getchar() != '\n')    /* skips rest of line */
>       ;

very common C idiom. for example, can be used to skip blanks

>   while ((ch = getchar()) == ' ')     /* skips blanks */

loop terminates when ch encounters first nonblank character

> Be careful of using scanf and getchar together. scanf will
> often "peak" ahead but not actually read some characters
> such as the newline character. Then the getchar call will
> read the newline instead of what was intended
>   printf("Enter an integer: ");
>   scanf("%d", &i);
>   printf("Enter a command: ");
>   command = getchar();    /* command will = '\n' */

### Determine the length of a message
write a program that calculates the length of a message.

> Enter a message: Brevity is the soul of wit.
> Your message was 27 character(s) long.

length includes space and punctuation but not new-line character
see length.c

>   /* Determines length of a message */
>   #include <stdio.h>
>
>   int main(void) {
>       char ch;
>       int len = 0;
>
>       printf("Enter a message: ");
>       ch = getchar();
>       while (ch != '\n') {
>           len++;
>           ch = getchar();
>       }
>       printf("Your message was %d character(s) long.\n", len);
>
>       return 0;
>   }

recall the while and getchar idioms from before. the program can be
made shorter. see length2.c

>   /* Determines length of a message */
>
>   #include <stdio.h>
>
>   int main(void) {
>       int len = 0;
>       
>       printf("Enter a message: ");
>       while (getchar() != '\n')
>           len++;
>       printf("Your message was %d character(s) long.\n", len);
>
>       return 0;
>   }

## 7.4 Type Conversion
Computers can only perform arithmetic if the operands are the same size
(i. e. 32-bit + 32-bit, not 16-bit + 32-bit)

C allows basic types to mix and the compiler will generate instructions
to convert operands to different types for the hardware. A 16-bit short
and a 32-bit int are added, compiler will convert short to 32 bits.
int + float will have compiler make int into float format

These automatic conversions are called implicit conversions. 

C allows programmers to make explicit conversions as well using the
cast operator

implicit conversions are performed when:
- operands in arithmetic or logical expression don't have the
same type
- type of the expression on the right of assignment != type on left
- type of argument in function call != type of corresponding parameter
- type of expression in a return statement != functions return type

### The usual arithemetic conversions
if f has type float and i has type int, usual arithmetic conversion will
be applied in f + i because the types don't match

safer to convert i to float than convert f to int

strategy is to convert operands to 'narrowest' type. one type is 
narroer than another if it requires fewer bytes to store. Types are made
to match by converting the narrower of the two types to the other type. 
process is called 'promotion'. 

integral promotion - converts a character or short int to type int

type of either operating is float:
use diagram to see which type is narrower
> long double
>    ^
>    |
> double
>    ^
>    |
> float

neither operand is type float:
perform integral promotion on both operands, then use diagram below
to find which type is narrower
> unsigned long int
>    ^
>    |
> long int
>    ^
>    |
> unsigned int
>    ^
>    |
>   int

special case: long int and unsigned int have same length, both are
converted to unsigned long int

> comparing signed and unsigned operands can lead to programming problems
> comparing unsigned int and signed int using < operator can 
> cause erroneous results since signed int will be made unsigned and
> thus have a 'larger value' than the other operand. example:
>
>   /* assume 32-bit machine */
>   unsigned int u = 10;    /* will not change value */
>   signed int i = -10;     /* will be converted to 4 294 967 296 */
>
>   i < u       /* result is false instead of expected true */

larger example:
>   char c;
>   short int s;
>   int i;
>   unsigned int u;
>   long int l;
>   unsigned long int ul;
>   float f;
>   double d;
>   long double ld;
>
>   i = i + c;      /* c is converted to int                */
>   i = i + s;      /* s is converted to int                */
>   u = u + i;      /* i is converted to unsigned int       */
>   l = l + u;      /* u is converted to long int           */
>   ul = ul + l;    /* l is converted to unsigned long int  */
>   f = f + ul;     /* ul is converted to float             */
>   d = d + f;      /* f is converted to double             */
>   ld = ld + d;    /* d is converted to long double        */

### Conversion during assignment
usual arithemetic conversions don't apply to assignment.
C follows rule that expression on the right side is converted to 
type of the variable on the left side
>   char c;
>   int i;
>   float f;
>   double d;
>
>   i = c;      /* c is converted to int    */
>   f = i;      /* i is converted to float  */
>   d = f;      /* f is converted to double */

examples of issues:

>   int i;
>   i = 842.97  /* i is now 842     */
>   i = -842.97 /* i is now -842    */

and can result in meaningless resutls:

>   c = 10000;      /* outside type range. WRONG    */
>   i = 1.0e20;     /* outside type range. WRONG    */
>   f = 1.0e100;    /* outside type range. WRONG    */

to avoid issues with integers and floating points, append the f
suffix to a floating-point constant to assign it to a float var
>   f = 3.14159f;

otherwise, the above would be stored as a double and the compiler
may issue warning during compilation.

### Implicit conversions in C99
implicit conversions rules in C99 different than C89 due to new 
types (i. e. _Bool, long long, etc.).

C99 gives integer conversion rank:
1. long long int, unsigned long long int
2. long int, unsigned long int
3. int, unsigned int
4. short int, unsigned short int
5. char, signed char, unsigned char
6. _Bool

C99 has integer promotions (not C89's integral promotions)
- type of either operand is floating type (if not complex), rules
same as before
- neither operand type is floating, perform integer promotion
on both operands. if more is needed, use the following rules:
- if operands signed/unsigned match, convert operand whose type has
lesser integer conversion rank to the other
- if unsigned operand has >= rank to signed operand, convert signed
operand to unsigned operand
- if signed operand can rep all values of the type of unsigned operand,
convert unsigned operand to the type of the signed operand
- else convert both operands to unsigned type corresponding to type
of signed operand

All arithmetic types can be converto to _Bool type. result of conversion
is 0 if original value, 1 otherwise

### Casting
For greater control, C provides casts. has form
> ( type-name ) expression

type-name specifies type expression should be converted to
example:
>   float f, frac_part;
>
>   frac_part = f - (int) f;

this example shows f is converted to int, then converted back to float
before the subtraction takes place. f is then subtracted from the
second f which no longer has the fractional part and stored as a float
in frac_part

casting can be used to overrule compiler

>   float quotient;
>   int dividend, divisio;
>
>   quotient = dividend / divisor;

here, result is stored in float but the division is done on integers.
In order to perform the division on floats (and get accurate number),
casting can be used

>   quotient = (float) dividend / divisor;

only one needs a cast since this will force the compiler to convert
the second automatically.

C regards ( type-name ) as a unary operator which have higher
precedence than binary operators
>   (float) dividend / divisor

is seen as 
>   ((float) dividend) / divisor

casts can be used to avoid overflow.

>   long i;
>   int j = 1000;
>
>   i = j * j;  /* overflow may occur */

even though i is a long, overflow can occur since j is an int, the 
immediate result will be an int that is then converted to a long

>   i = (long) j * j;

note that the cast must occur before multipication
>   i = (long) (j * j);     /* WRONG */

## 7.5 Type definitions
previously used #define to create macro to define BOOL type
>   #define BOOL int

type definition is a better method. of form
>   typedef int Bool;

name of type being defined is last. capital first letter is convention,
not required
>   Bool flag;  /* same as int flag */

compiler treats Bool as synonym for int; flag is still an int

### Advantages of type definitions
can make program more understandable
>   typedef float Dollars;
>
>   Dollars cash_in, cash_out;

more informative than
>   float cash_in, cash_out;

can also make future modifications easy. if Dollars should be double
instead of float, only 1 place to modify
>   typedef doouble Dollars;

### Type definitions and portability
typedefs help portability since types can have different ranges
>   int i;
>   i = 100000;

ok on machine where int is 32-bits but will fail on machine where
int is 16-bits
> For greater portability, consider using typedef to define new names
> for integer types

using numbers than can range from 0 to 50 000 works with long type
but int type is more useful since they are faster and take up less space
use typedef
>   typedef int Quantity;
>
>   Quanitity q;

then if you need to move to machine with shorter integers, change
typedef only
>   typdef long Quantity;

doesn't guarantee working chagnes though since scanf and printf 
would require different conversion specifiers (%d for int, %ld for long)

C library uses typedef to create names for types that can vary
from one C implementation to another. usually end in _t. examples:
>   typedef long int ptrdiff_t;
>   typedef unsigned long int size_t;
>   typedef int wchar_t;

In C99, <stdint.h> header uses typedef to define names for integer
types with particular number of bits. for example, int32_t is
signed integer type with exactly 32 bits.

## The sizeof operator
sizeof allows program to determine how much memory is required to store
values of a particular type. of form:
>   sizeof ( type-name )

result is an insigned int representing number of bytes required to 
store a value belonging to type-name. sizeof(char) always = 1
but other sizes may vary. on 32-bit machine, sizeof(int) usually = 4

sizeof can be used on constants, variables, and expressions in general
if i and j are int variables, and sizeof(i) is 4, sizeof(i + j) is 4.
parenthesis not required but useful to avoid confusion
>   sizeof i + j;   /* will compute sizeof(i) + j, not sizeof( i + j) */

type of sizeof expression is implementation defined type name size_t.
C89, it's best to convert to value to known type before printing
best to cast to unsigned long, then print using %lu
>   printf("Size of int: %lu\n", (unsigned long) sizeof(int));

C99, size_t can be > unsigned long, but printf capable of displaying
size_t value directly (no cast). use %z with usual integer code 
(typically u)
>   printf("Size of int: %zu\n", sizeof(int));  /* C99 only */


