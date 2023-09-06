/* conditional statements that are evaluated during preprocessing.
 * The #if line evaluates a constant integer expression 
 * (which may not include sizeof, casts, or enum constants). 
 * If the expression is non-zero, subsequent lines until an #endif or #elif or
 * #else are included. (The preprocessor statement #elif is like else-if.) 
 * The expression "defined(name)"" in a #if is 1 if the name has been defined, 
 * and 0 otherwise.
 * 
 * The first inclusion of calc.h defines the name CALC; subsequent inclusions 
 * will find the name defined and skip down to the #endif. 
 * A similar style can be used to avoid including files multiple times. 
 * If this style is used consistently, then each header can itself include any other
 * headers on which it depends, without the user of the header 
 * having to deal with the interdependence.
 * 
 * Alternatively, we could also do:
 * #ifndef CALC
 * #define CALC
 * ...
 * #endif
 */
#if !defined(CALC)
#define CALC

#define NUMBER '0' /* signal that a number was found */
int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

#endif
