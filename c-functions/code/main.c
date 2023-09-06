#include <stdio.h>
#include <stdlib.h>
/* File inclusion makes it easy to handle collections of #defines and declarations 
 * (among other things). The #include line is replaced by the contents of the file. 
 * If the filename is quoted (like the case below), searching for the file typically 
 * begins where the source program was found; if it is not found there, or if the name is
 * enclosed in < and > (like the cases above), searching follows an implementation-defined 
 * rule to find the file.
 * An included file may itself contain #include lines.
 * 
 * #include is the preferred way to tie the declarations together for a large program. 
 * It guarantees that all the source files will be supplied with the same definitions 
 * and variable declarations.
 * When an included file is changed, all files that depend on it must be recompiled.
 */
#include "calc.h"

#define MAXOP 100 /* max size of operand or operator */

/* a calculator program that provides the operators +, -, * and /
 * because it is easier to implement, the calculator will use 
 * reverse Polish notation instead of infix.
 * In reverse Polish notation, each operator follows its operands; an infix expression like:
 * (1 - 2) * (4 + 5)
 * is entered as
 * 1 2 - 4 5 + *
 * Parentheses are not needed; the notation is unambiguous as long as
 * we know how many operands each operator expects.
 * 
 * The implementation is simple. 
 * Each operand is pushed onto a stack; 
 * when an operator arrives, the proper number of operands 
 * (two for binary operators) is popped, 
 * the operator is applied to them, 
 * and the result is pushed back onto the stack.
 * */
int main(void)
{
    int type;
    double op2;
    char s[MAXOP];
    
    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}
