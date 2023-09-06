# C Functions and Program Structure

## Table of Contents
1. [Goals](#goals)
2. [Basics](#basics)
3. [External Variables](#external-variables)
4. [Static Variables](#static-variables)
5. [Initialization](#initialization)

## Goals <a name="goals"></a>
Functions *break large computing tasks into smaller ones*, 
and enable people to build on what others have done.
C programs generally consist of many small functions.
A program may reside in one or more **source files**. 
Source files may be compiled separately and loaded together, 
along with previously compiled functions from *libraries*.
We will learn more about functions and the C program structure
in this module.

## Basics <a name="basics"></a>
Each function definition has the form:
```
return-type function-name(argument declarations)
{
    declarations and statements
}
```
Communication between functions is 
by **arguments** and *values returned by the functions*, 
and through **external variables**
(we discussed external variables briefly [here](../c-basics/notes.md#variables-and-scope),
and we will discuss more [later](#external-variables)).
The `return` statement is the mechanism for returning a value from the called function 
to its *caller*. Any expression can follow `return`: 
```
return expression;
```
The expression will be converted to the return type of the function if necessary.
There could be *no* expression after return; in that case, no value is returned to the caller.
The calling function is free to ignore the returned value.
> :bangbang: Take a careful look at this [example](code/calculator.c),
> in which a C program resides on multiple source files (`calculator.c`, `atof.c`, and `csc250_getline.c`).

## External Variables <a name="external-variables"></a>
A C program consists of a set of external objects, which are either variables or functions. 
"External" is used in contrast to "internal", 
which describes the arguments and variables defined inside functions. 
External variables are defined *outside of any function*, and
are thus potentionally available to many functions.
* Functions themselves are *always external*, because C does not allow functions 
to be defined inside other functions. 
* All references to external variables and functions by the same name, even
from functions compiled separately, are *references to the same thing*
(we will see how we can define external variables and functions 
that are visible only within a single source file).

> The functions and external variables that make up a C program 
> need *not* all be compiled at the same time; 
> the source text of the program may be kept in *several files*, 
> and previously compiled routines may be loaded from libraries.

The **scope** of a name is the part of the program within which the name can be used.
* For an *automatic (local) variable* declared at the beginning of a function, 
the scope is *the function in which the name is declared*.
    > The same is true of the *parameters* of a function, which are in effect local variables.
* Variables can be defined in a *block-structured fashion* within a function. 
Declarations of variables (including initializations) may 
follow the left brace that introduces any *compound statement*, 
not just the one that begins a function. 
Variables declared in this way *hide* any identically named variables in outer blocks, 
and remain in existence until the matching right brace. 
This is similar to Java. For example,
    ```c
        if (n > 0) {
            int i;          /* declare a new i */
            for (i = 0; i < n; i++)
                ...
        }
    ```
    The scope of the variable `i` is the "true" branch of the `if`; 
    this `i` is unrelated to any `i` outside the block.

* The scope of an external variable or a function *lasts from the point at which it is declared to
the end of the file being compiled*.
    > For example, given the following layout of a program in the *same* file:
    > ```c
    > int main(void) 
    > { 
    >     ...
    > }
    >
    > int sp = 0;           /* external variable */
    > double val[MAXVAL];   /* external variable */
    >
    > void push(double f) 
    > {
    >      ...
    > }
    >
    > double pop(void)
    > {
    >      ...
    > }
    > ```
    > The variables `sp` and `val` may be used in `push` and `pop` 
    > *simply by naming them*; no further declarations are needed. 
    > But these names are **not visible** in `main`, 
    > nor are `push` and `pop` themselves visible in `main`.

* If an external variable is to be referred to **before it is defined**, 
or if it is **defined in a different source file** from the one where it is being used, 
then an `extern` declaration is **mandatory**.
* It is important to distinguish between the **declaration** of an external variable and its **definition**.
A declaration announces the properties of a variable (primarily its type); 
a definition also *causes storage to be set aside*.
There must be **only one definition** of an external variable among all the files that make up the
source program; other files may contain extern declarations to access it. 
*Array sizes must be specified with the definition*, but are optional with an extern declaration.
    > If the lines below appear *outside* of any function, 
    > they define the external variables `sp` and `val`, 
    > cause storage to be set aside, 
    > and also *serve as the declarations for the rest of that source file*.
    > ```c
    > int sp;
    > double val[MAXVAL];
    > ```
    > However, the lines below:
    > ```c
    > extern int sp;
    > extern double val[];
    > ```
    > only **declare** for the rest of the source file 
    > that `sp` is an `int` and that `val` is a `double` array 
    > (whose size is determined elsewhere), 
    > but they do not create the variables or reserve storage for them.
* **Initialization** of an external variable *goes only with the definition*.
* Automatic variables, including formal parameters, *hide external variables and functions of the same name*. For example,
    > ```c
    > int x;
    > int y;
    >
    > int f(double x)
    > {
    >     double y;
    > }
    > ```
    > Within the function `f`, occurrences of `x` refer to the parameter, 
    > which is a `double`; outside `f`, they refer to the external `int`. 
    > The same is true of the variable `y`.
    > 
    > As a matter of style, it is best to avoid variable names that conceal names in an outer scope.

Typically,
we put the definitions (e.g., `#define ...`) and declarations (e.g., function declarations)
shared among files in a centralized location,
so that there is only one copy to get and keep right as the program evolves.
Accordingly, we will place this common material 
in a **header file**, e.g., `calc.h` (in our code example above), 
which will be included as necessary (`#include "calc.h"` at the beginning of e.g., `calculator.c` file).
For larger programs, more than one header would likely be needed.

## Static Variables <a name="static-variables"></a>
Consider [this](code/main.c) C program spanning multiple files (including a header file).
The variables `sp` and `val` in `stack.c`, 
and `buf` and `bufp` in `getch.c`, are for the private use of the functions 
in their respective source files, 
and are not meant to be accessed by anything else.
The `static` declaration, 
applied to an external variable or function, 
**limits the scope of that object to the rest of the source file being compiled**. 
External static provides a way to hide names like `buf` and `bufp` 
in the getch-ungetch combination, 
which must be external so they can be shared, 
yet which should not be visible to users of `getch` and `ungetch`.

Static storage is specified by prefixing the normal declaration with the word `static`, e.g.:
```c
static char buf[BUFSIZE];
static int bufp = 0;
```
as you can also see in [`getch.c`](code/getch.c).
*Those names will not conflict with the same names in other files of the same program*.

> The external static declaration is most often used for variables, 
> but it can be applied to functions as well.
> Normally, function names are global, visible to any part of the entire program. 
> If a function is declared `static`, however, its name is invisible
> outside of the file in which it is declared.
>
> <details>
> <summary>:heavy_plus_sign: Good To Know</summary>
> 
> The static declaration can also be applied to *internal variables*. 
> Internal static variables are local to a particular function,
> just as automatic variables are, but unlike automatics, 
> **they remain in existence rather than coming and going each time the function is activated**. 
> This means that internal static variables provide *private*, **permanent** storage 
> within a single function.
>
> </details>

## Initialization <a name="initialization"></a>
In the absence of *explicit initialization*, 
**external and static variables are guaranteed to be initialized to zero**; 
automatic variables have **undefined (i.e., garbage) initial values**.
* For external and static variables, the initializer must be a **constant expression**; the
initialization is done once, conceptionally before the program begins execution.
* In effect, initialization of automatic variables are just shorthand for *assignment statements*.
* An array may be initialized by following its declaration with *a list of initializers enclosed in
braces and separated by commas*. For example:
    ```c
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    ```
    When the size of the array is omitted, 
    the compiler will compute the length by counting the initializers.
    If there are fewer initializers for an array than the *specified size*, 
    the others will be *zero for external, static, and automatic variables*.
    There is no way to specify repetition of an initializer, 
    nor to initialize an element in the middle of an array without supplying all the preceding values.
