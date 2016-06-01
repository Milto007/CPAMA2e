# Selection Statements
C has many operators, few statements
statements have 3 categories:
- selection: the if and switch statements allow progs to select an execution path
- iteration: the while, do, and for statements allow support looping
- jump: the break, continue, and goto statements cause unconditional jump elsewhere

compound statements group several statements into a single one
null statement performs no action

## logical expressions
several statements (i. e. if) must test the value of an expression for true or false
other languages have a special Boolean or logical type (true or false result)
C yields 0 (false) or 1 (true)

### relational operators
C's relational operators:
- <, less than
- >, greater than
- <=, less than or equal to
- >=, greater than or equal to

relational operators can be used to compare integers, floating-point numbers,
and mixed types. (i. e. 1 < 2.5 evalutes to 1 and 5.6 < 4 to 0)

precedence, lower tahn arithmetic operators
>   i + j < k - 1
>   // same as
>   (i + j) < (k - 1)

| the expression 
| >     i < j < k
| is legal but equal to 
| >    (i < j) < k
| it does not test that j is less than k but greater than i as expected

### equality operators
equality operators have unique appearance:
- ==, equal to
- !=, not equal to

precendence, lower than relational operators
>   i < j == j < k
>   // same as
>   (i < j) == (j < k)
>   // true if i < j and j < k are both true or both false

can be used in clever ways
>   (i >= j) + (i == j)
>   // results in 0, 1, or 2 depending on values

tricks like this make things difficult to understand, not recommended

### logical operators
logical operators can make more complicated logical expressions:
- !, logical negation
- &&, logical and
- ||, logical or

logical operators produce either 0 or 1
operands usually have value of 0 or 1 but not necessary
- nonzero operand is true, zero operand is false

!expr has value 1 if expr has value 0
expr1 && expr2 has value 1 if values of expr1 and expr2 are nonzero
expr1 || expr2 has value 1 if at expr1, expr2, or both are nonzero

all other cases produces 0

both && and || perform "short-circuit" evaluation
- tests left operand, then right
- if only left operand is needed to deduce value, right isn't evaluated

| be careful of relying on side effects on right side of expression
| they may not occur if the left side short circuits evaluation
| >     i > 0 && ++j > 0
| if i > 0 is false, j will not be incremented

! operator has same precedence as unary plus and minus operators
&& and || precedence lower than relational or equality operators
>   i < j && k == m
>   // same as
>   (i < j) && (k == m)

! is right associative, && and || are left associative

# the if statement
if statement allows program to choose between two alternatives by testing
value of an expression. of the form:
>   if ( expression ) statement

parenthesis around expression are mandatory as part of if statement (not expression)

if value of expression is nonzero (in C, == true), statement part is executed

>   if (line_num == MAX_LINES)
>       line_num = 0;

| don't confuse equality (==) with assignment (=)
| this is a very common mistake

notice statement is singluar, not plural. to perform more than one statement, use {}
>   { statements }

braces force compiler to treat it as a single statement
>   {line_num = 0; page_num++;}

above is a legal compound statement, but expanding it to several lines is recommended
>   {
>       line_num = 0;
>       page_num++;
>   }

inner statements end with semicolon but overall compound statement does not

>   if (line_num == MAX_LINES) {
>       line_num = 0;
>       page_num++;
>   }

### the else clause
an if statement may have an else clause:
>   if ( expression ) statement else statement

statement after else is executed if expression in parenthesis has value 0

>   if (i > j)
>       max = i;
>   else
>       max = j;

both inner statements end with a semicolon
usually best to have else align with if and statements on separate lines
but if the statements are short, they can be combined
>   if (i > j) max = i;
>   else max = j;

no restrictions on statements inside if, can even be more if statements

>   if (i > j)
>       if (i > k)
>           max = i;
>       else
>           max = k;
>   else
>       if (j > k)
>           max = j;
>       else 
>           max = k;

if nesting as above is confusing, add braces
>   if (i > j) {
>       if (i > k) 
>           max = i;
>       else
>           max = k;
>   } else {
>       if (j > k) 
>           max = j;
>       else
>           max = k;
>   }

or you can add even more to be even clearer
>   if (i > j) {
>       if (i > k) {
>           max = i;
>       } else {
>           max = k;
>       }
>   } else {
>       if (j > k) {
>           max = j;
>       } else {
>           max = k;
>       }
>   }

more braces can help ensure future additions don't cause problems or bugs
and can make the boundaries of statements clearer

### cascaded if statements
very common to have a series of test conditions
>   if (n < 0)
>       printf("n is less than 0\n");
>   else
>       if (n == 0)
>           printf("n is equal to 0\n");
>       else
>           printf("n is greater than 0\n");

this can be simplified by aligning first else and second if
>   if (n < 0)
>       printf("n is less than 0\n");
>   else if (n == 0)
>       printf("n is equal to 0\n");
>   else
>       printf("n is greater than 0\n");

this has a distinctive appearance
>   if ( expression )
>       statement
>   else if ( expression )
>       statement
>   ...
>   else if ( expression )
>       statement
>   else
>       statement

the last 'else' and statement are optional

>   /* broker.c */
>   /* see broker.c in examples directory */
>   /* Calculates a broker's compensation */
>
>   #include <stdio.h>
>
>   int main(void) {
>
>   float commission, value;
>
>   printf("Enter value of trade: ");
>   scanf("%f", &value);
>
>   if (value < 2500.00f)
>       commission = 30.00f + 0.17f * value;
>   else if (value < 6250.00f)
>       commission = 56.00f + 0.0066f * value;
>   else if (value < 20000.00f)
>       commission - 76.00f + 0.0034f * value;
>   else if (value < 50000.00f) 
>       commisssion = 100.00f + 0.0022f * value;
>   else if (value < 500000.00f)
>       commission = 155.00f + 0.0011f * value;
>   else
>       commission = 255.00f + 0.0009f * value;
>
>   if (commission < 39.00f)
>       commission = 39.00f;
>
>   printf("Commission: $%.2f\n", commisssion);
>
>   return 0;
>   }

expressions could have been written as
>   else if (value >= 2500.00f && value < 6250.00f)

but it was unnecessary since it tests clauses in order. it cannot reach
the second if if the first if was true

### the "dangling else" problem
when if statements are nested, be careful of the dangling else problem

>   if (y != 0)
>       if (x != 0)
>           result = x / y;
>   else 
>       printf("Error: y is equal to 0\n");

which looks ok, but may not be the desired result. the else statement 
actually belongs to the second if, not the first as the indents appear 

to fix this issue, use braces

>   if (y != 0) {
>       if (x != 0)
>           result = x / y;
>   } else
>       printf("Error: y is equal to 0\n");

## conditional expressions
C provides an operator that allows an expression to produce one of two values
dependingon the value of a condition

the conditional operator must be of the form:
>   expr1 ? expr2 : expr3

where expr1, expr2, and expr3 can be expressions of any type
ternary operator - requries three operands

should be read: if expr1 then expr2 else expr3
if expr1 isn't zero, expr2 is evaluated
if expr1 is zero, expr3 is evaluated

>   int i, j, k;
>
>   i = 1;
>   j = 2;
>   k = i > j ? i : j;          /* k is now 2 */
>   k = (i >= 0 ? i : 0) + j;   /* k is now 3 */

in the first assignment of k, k returns to either i or j. i = 1, j = 2, so 
the comparison fails and thus k = j which = 2.f=

in the second assignement of k, i >= 0 comparison succeeds so the conditional
expression has the value of i which is 1. that value is added to j (=2) so 
the result is 1 + 2 = 3. the parenthesis are necessary due to precedence (+ higher than ?)

usually makes programs difficult to understand, so they should be avoided.
good example is with the return statement.
>   if (i > j)
>       return i;
>   else
>       return j;

can be written as
>   return i > j ? i : j;

or use in printf can also be beneficial
>   printf("%d\n", i > j ? i : j);

also used in macro definitions

### boolean values in C89
C did not have a boolean type for many years and C89 does not define one. can
simply use an int such as:
>   int flag;
>
>   flag = 0;
>   flag = 1;

but isn't clear that flag can only be 0 or 1. some programers define macros
>   #define TRUE 1
>   #define FALSE 0
>
>   flag = TRUE;
>   flag = FALSE;

then flag can be used as a boolean as in:
>   if (flag == TRUE)
>   // or 
>   if (flag)

the latter if (flag) is preferred. similarly, can test for false:
>   if (flag == FALSE)
>   // or
>   if (!flag)

can also define macro that defines bool type 
>   #define BOOL int
>
>   BOOL flag;
>
>   flag = 0;
>   flag = 1;

### boolean values in C99
C finally got a boolean type named _Bool. 
>   _Bool flag;

_Bool is an unsigned integer type in disguise but can only be assigned
0 or 1. trying to store anything else will cause it to be 1
>   flag = 5;   /* flag is assigned 1 */

in addition, C99 provides new header <stdbool.h> to work with bool values
provides macro where bool == _Bool. using <stdbool.h>, can write
>   bool flag;  /* same as _Bool flag */

header file also provides macro for true and false (1 and 0 respectively)
>   flag = false;
>   flag = true;

examples in this book will use boolean values where needed

## the switch statement
when lots of comparisions are needed, can use cascading ifs as before
>   if (grade == 4)
>       printf("Excellent");
>   else if (grade == 3)
>       printf("Good"); 
>   else if (grade == 2)
>       printf("Average"); 
>   else if (grade == 1)
>       printf("Poor"); 
>   else if (grade == 0)
>       printf("Failing"); 
>   else
>       printf("Illegal grade");

alternatively, C provides the switch statement
>   switch(grade) {
>       case 4:     printf("Excellent");
>                   break;
>       case 3:     printf("Good");
>                   break;
>       case 2:     printf("Average");
>                   break;
>       case 1:     printf("Poor");
>                   break;
>       case 0:     printf("Failing");
>                   break;
>       default:    printf("Illegal grade");
>                   break;
>   }

most common form:
>   switch ( expression ) {
>       case constant-expression : statements
>       ...
>       case constant-expression : statements
>       default : statements
>   }

- controlling expression: the word switch followed by an integer expression
in parenthesis
- case labels: a constant-expression cannot contain variables or function calls
5 and 5 + 10 are constant expressions but n + 10 is not.
- statements: no braces are required for multiple statements. last statement
is usually "break"

cannot duplicate case labels. order of case labels, including default, do
not matter. several case labels may precede the same group of statements.

>   switch (grade) {
>       case 4:
>       case 3:
>       case 2:
>       case 1:     printf("Passing");
>                   break;
>       case 0:     printf("Failing");
>                   break;
>       default:    printf("Illegal grade");
>                   break;
>   }

the above is commonly written with case labels on the same line
>   switch (grade) {
>       case 4: case 3: case 2: case 1:
>           printf("Passing");
>           break;
>       case 0:
>           printf("Failing");
>           break;
>       default:
>           printf("Illegal grade);
>           break;
>   }

case labels cannot specify range of values.

default case is not required; if default is missing and case is not described,
control passes the switch statement altogether

### the role of the break statement
break is needed because switch is a form of "computed jump"
- expression is evaluated, control jumps to matching case label. label is just
a marker for the position

when the last statement in the case has been executed, control "falls through"
to the first statement in the following case (ignoring next case label).

without the break, control will flow from one case into the next.
>   switch (grade) {
>       case 4:     printf("Excellent");
>       case 3:     printf("Good");
>       case 2:     printf("Average");
>       case 1:     printf("Poor);
>       case 0:     printf("Failing)"
>       default:    printf("Illegal grade");
>   }

if the value of grade is 3, above would print:
>   GoodAveragePoorFailingIllegal grade

| forgetting to use break is a common error but omitting it
| is sometimes done to allow several cases to share code

since it is a common mistake but can be used intentionally, best to 
comment deliberate omission
>   switch (grade) {
>       case 4: case 3: case 2: case 1:
>               num_passing++;
>               /* FALL THROUGH */
>       case 0: total_grades++;
>               break;
>   }

without the comment, someone may later add a break thinking it was
mistakenly missing. the final break isn't necessary but common in case
a future case is added and the break will be necessary

Program: Printing a Date in Legal Form
see date.c in examples dir


