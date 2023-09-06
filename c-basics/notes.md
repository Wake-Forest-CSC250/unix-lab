# Basics of C

## Table of Contents
1. [Goals](#goals)
2. [Hello World, Again](#hello-world-again)
3. [A More Complicated Example](#a-more-complicated-example)
    1. [Comments](#comments)
    2. [Variables and Data Types](#variables-and-data-types)
        1. [Variables and Scope](#variables-and-scope)
        2. [Data Types](#data-types)
        3. [Constants](#constants)
        4. [Control Flow](#control-flow)
        5. [Arithmetic, Relational, and Logical Operators](#arithmetic-relational-and-logical-operators)
4. [Standard IO](#standard-io)
    1. [Characters and Character Arrays](#characters-and-character-arrays)
    2. [Strings](#strings)
    3. [Formatted Output](#formatted-output)
    4. [Formatted Input](#formatted-input)

## Goals <a name="goals"></a>
This course requires programming in C.
In this module,
you will learn the basics of coding in C,
but ideally you already have some C programming experience. 
If you have not previously programmed in C 
but know another *procedural language*, 
such as Java (e.g., from CSC 111), 
you will likely be able to quickly learn 
what you need for this course.

> **Credits**: 
> * Kernighan and Ritchie, The C Programming Language, Second Edition 
> * CS61, Harvard University
> * 15-213/14-513/15-513, Carnegie Mellon

## Hello World, Again <a name="hello-world-again"></a>
Do you remember how you can write a "Hello World" program in Java from CSC 111?
<details>
<summary>Answer</summary>

```java
class HelloWorld {
    public static void main(String[] args) {
        System.out.println("Hello, World!"); 
    }
}
```
</details>

Your first ~~Java~~ **C** program (see [code](code/hello.c)):
```c
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}
```
What do you think is perhaps the biggest difference 
between the Java version of the "Hello World" program and the C version?
<details>
<summary>Answer</summary>

In Java, everything is an object.
However, C is ***not an object-oriented program language***[^objects]!
> By the way, C++ is somewhere in the middle
> (you can create Java-like objects if you want to 
> but it is not a strict requirement).
</details>

[^objects]: Note that I still often refer to a C data/value as an **object**, even though C is *not* object-oriented. 
In the context of C, we consider *a region of memory that contains a value (or even more technically, "a region of data storage in the execution environment, the contents of which can represent values")* to be an object. We will take a closer look in a later [module](../c-pointers/notes.md#c-objects).

Other important characteristics of C:
* Every C program consists of *one or more functions*. 
You must at least have a `main()` function in your C program to run.
    > Do we need to have a `main()` function in a Java class?
    >
    > <details>
    > <summary>Answer</summary>
    >
    > No, we do not! But to run a Java class, it must have a
    > `main()` method, because the execution starts from `main()`.
    > C also shares this property: your C program also
    > begins executing at the beginning of `main()`.
    > `main()` will usually call other functions 
    > to help perform its job, 
    > some that you wrote, 
    > and others from *libraries* that are provided for you
    > (we use a function in the example already!).
    > Notice that in C, we usually call a method a **function**.
    > </details>
* Like in Java (and C++), a C function consists of:
    * A **return type** (`int` in the "Hello World" example above)
        > Notice anything inconsistent between the return type 
        > and the body of the function?
        > 
        > <details>
        > <summary>Answer</summary>
        >
        > There is *no return statement* in the body of the function,
        > but the return type indicates an `int` return value!
        > Normally it is **not allowed** for the control flow 
        > to reach the end of a non-`void` function without returning anything. 
        > The `main()` function, however, is handled differently, 
        > as specified in the C standard, which specifies:
        >
        >> If control reaches the end of main without encountering a return statement
        >> ("falling off the end"),
        >> the effect is that of executing return 0.
        >
        > I deliberately exclude the return statement in the example
        > to discuss this exception, 
        but for consistency, **always return properly**.
        > In this case, you should add the following return statement
        > at the end of the function body:
        >
        > ```c
        > return 0;
        > ```
        >
        > A `0` indicates a normal termination, 
        > while a non-zero value indicates that something went wrong
        > (unusual or erroneous termination conditions). 
        > It's up to you to return the appropriate value in your program!
        >
        > </details>
    * A **function name** (`main` is the name of the function in the example)
    * **Statements** that specify the operations to be done (we have one statement in the example). 
    The statements of a function are enclosed in *braces* `{` `}`.
        > A simple statement always ends with a semicolon (`;`).
        > *A common error in C programming is the omission of a semicolon.*
        > **However, I do not expect you to make this mistake
        > (:o: <u>harsh penalty</u>), 
        > since you have already programmed in Java and Java has the same rule.**
        >
        > A *compound* statement consists of braces (`{` `}`) and other statements.
    * **[Variables](#variables-and-data-types)** that store values used during the computation
    (which we don't have in the example)
    * The parentheses after the function name surround the **argument list**.
        > One method of *communicating data between functions* is 
        > for the calling function to provide a list of values (which are called **arguments**), to the function it calls.
        > Note that we will generally use **parameter** for a variable 
        > named in the parenthesized list in a function declaration and definition
        > and **argument** in a function call.
        > The terms **formal argument** and **actual argument** are sometimes used 
        > for the same distinction (I personally prefer using *parameters*
        > and *arguments*, but it is up to you).
        >
        > :bangbang: Functions that accept no parameters should explicitly declare a 
        > `void` parameter in their parameter list. 
        > This holds true in both the *declaration* and *definition* sections 
        > (which should match). We will learn the difference between a *function declaration*
        > and a *function definition* in [a more complicated example](#a-more-complicated-example) below.

        :bangbang: **In C, all function arguments are passed "by value."**
        > This means that the called function 
        > is given the values of its arguments in temporary variables
        > rather than the originals. Therefore,
        > *parameters can be treated as conveniently initialized
        > local variables in the called routine*!
        > **It is possible to arrange for a function 
        > to modify a variable in a calling routine, but
        > _the caller must provide the address of the variable to be set (technically a pointer to the variable) and the called function
        > must declare the parameter to be a pointer and access the
        > variable indirectly through it_**.
        >
        > :bangbang: This is absolutely crucial for you to understand.
        > Go through this block of text as many times as you need to internalize the concept.
        > We will go into detail in a future [module](../c-pointers/notes.md#function-arguments).

    * A function is called by *naming* it, followed by a *parenthesized list of arguments*. In our example:
        ```c
        printf("hello, world\n");
        ```

        This calls the function `printf` with the argument `"hello, world\n"`. `printf` is a library function that prints output;
        in this case the *string of characters between the quotes*.
        The sequence `\n` in the string is C notation for the *newline* character. `printf` (like `print` in Java)
        does not supply a newline character automatically.
        > You should have learned about *strings*, *characters*,
        and *the newline character* (`\n`) already in Java.
        > We will see some nuances in C [later](#standard-io).
        >
        > <details>
        > <summary>Common Escape Sequences</summary>
        >
        > * `\n`: newline
        > * `\\`: backslash
        > * `\t`: horizontal tab
        > * `\'`: single quote
        > * `\"`: double quote
        >
        > This list is incomplete.
        > </details>

The first line of the program:
```c
#include <stdio.h>
```
tells the *compiler* to include information about the [standard input/output library](#standard-io).
This allows you, among many other things, to use the `printf` function.

## A More Complicated Example <a name="a-more-complicated-example"></a>
Consider the following classic example (see [code](code/converter.c)):
```c
#include <stdio.h>

int main(void)
{
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature scale */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr-32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}
```
What does this program do? Is there any problem with this program?
<details>
<summary>Answer</summary>

The program uses the formula `C=(5/9)(F-32)` 
to print a table of Fahrenheit temperatures (between 0F and 300F)
and their centigrade or Celsius equivalents.

In this program,
we use *integer arithmetic*, so the Celsius temperatures are not very accurate; 
for instance, 0F is actually about -17.8C, not -17C. 
To get more accurate answers, 
we should use floating-point arithmetic instead of integer.
</details>

Let's use this example program
to discuss several concepts in C,
including *comments*, *declarations*, *variables*, 
*arithmetic expressions*, *loops*, and
*formatted output*.
Many aspects of these concepts share some similarities with Java.

### Comments <a name="comments"></a>
Any characters between `/*` and `*/` are ignored by the compiler
(*multi-line comments*); 
these characters are comments that may be used freely 
to make a program easier to understand.
Alternatively, 
you can use `//` to create a *single-line comment*.
> Older versions of C (before C99) support only multi-line style 
> (`/*` and `*/`) comments. For portability, 
> we recommend that you use multi-line style comments only,
> but this is not a strict requirement in this course.

:bangbang: Go through [the Style guide](../style.md#comments) carefully
to understand the commenting requirement in this course.

### Variables and Data Types <a name="variables-and-data-types"></a>
In C, 
all variables *must be declared before they are used*, 
usually at the beginning of the function 
before any executable statements. 
A declaration announces the properties of variables; 
it consists of a list of **variable names**, 
such as in our example:
```c
int fahr, celsius;
int lower, upper, step;
```
The **type** `int` means that the variables are integers.

#### Variables and Scope <a name="variables-and-scope"></a>
A variable may also be **initialized** in its declaration.
There are some restrictions on the names of variables
and symbolic [constants](#constants). 
* Names are made up of letters and digits.
* The first character must be a letter. 
The underscore (`_`) counts as a letter.
It is useful for improving the *readability* of long variable names. 
* Don't begin variable names with underscore, since *library routines* often use such names. 
* **Case-sensitive**: Upper and lower case letters are distinct, 
so `x` and `X` are two different names. 
Traditional C practice is to use lower case for variable names, and
all upper case for symbolic constants.
* Keywords like `if`, `else`, `int`, `float`, etc., are reserved: 
you can't use them as variable names.
* Choose variable names that are related to the purpose of the variable
(see [the Style guide](../style.md) for naming recommendations).

The variables in `main()`, for example, are **private** or **local** to main. 
Because they are declared within `main()`, no other function can have direct access to them. The same is true of the variables in other functions.
Each local variable in a function comes into existence only when the function is
called, and disappears when the function is exited.
This is why such variables are usually
known as **automatic variables** (:new: this might be a new terminology to you,
but just remember that *automatic* variables are *local* variables).
> Because automatic variables come and go with function invocation, 
> they do not retain their values from one call to the next, 
> and **must be explicitly set upon each entry**. 
> If they are not set, they will contain **undefined values** or otherwise known as *garbage values*.

The qualifier `const` can be applied to the declaration 
of any variable to specify that *its value will not be changed*.
For example,
```c
const double e = 2.71828182845905;
```

Does Java have `const` qualifier?
<details>
<summary>Answer</summary>

No, it does not.
The Java `final` keyword does a similar (but not identical) job, however.
</details>

> The `const` declaration can also be used with array parameters
> to indicate that the function does not change that array:
> ```c
> int strlen(const char[]);
> ```
>
> The example above is a function declaration (you will see an example of that
> next when we look at some code to learn about external variables).
> You should already know the basics about arrays when you study Java;
> if you need a quick reminder, navigate to [here](#characters-and-character-arrays).

:bangbang: It is possible to define variables that are **external** to
all functions, i.e., variables that *can be accessed by name by any function*.
* **External variables** are globally accessible (thus we can also call them **global variables**), they can be used instead of argument lists to communicate data between functions.
Thus, if two functions must share some data, *yet neither calls the other*, 
it is often most convenient if the shared data is kept in external variables 
rather than being passed in and out via arguments.
* External variables **remain in existence permanently**, 
rather than appearing and disappearing as functions are called and exited, 
so they *retain their values even after the functions that set them have returned*.
* An external variable must be **defined, exactly once, outside of any function**.
This sets aside storage for it.
* The variable must also be **declared in each function that wants to access it**; this
states the type of the variable.
* The declaration may be an **explicit extern statement** or **may be implicit from context**.
* Note that we are using the words *definition* and *declaration* carefully 
when we refer to external variables in this section. 
**Definition** refers to the place where the variable 
is created or assigned storage; **declaration** refers to places 
where the nature of the variable is stated but no storage is allocated.

**Learn more about external variables through [code](code/external.c).**
The example code will also show you a good *program layout*.

> Note that use of external variables is **highly discouraged**.
> Oftentimes, there is no real need for such variables.
> Worse, relying too heavily on external variables 
> is fraught with peril since it leads to programs
> whose data connections are not all obvious:
> variables can be changed in unexpected and even
> inadvertent ways (e.g., due to [*concurrency*](https://en.wikipedia.org/wiki/Concurrency_(computer_science));
> you can find a good example [here](https://www.classes.cs.uchicago.edu/archive/2018/spring/12300-1/lab6.html) 
> and you will likely deal with concurrency in CSC 251), 
> and the program is hard to modify.
> While I do not ban the use of external variables
> (they could still be useful, if used correctly - 
> in fact, the Linux kernel uses them;
> they exist for a reason, after all), 
> extensive use of such variables in this course
> will result in :o: harsh penalty.

We will learn more about external variables and scope in a different [module](../c-functions/notes.md#external-variables).

#### Data Types <a name="data-types"></a>
There are only a few basic/fundamental data types in C.
They are almost the same as the ones you have encountered in Java;
however, for many of these types, the exact size is *machine-dependent*.
> Is it also the case in Java?
> <details>
> <summary>Answer</summary>
>
> No.
> </details>

| Data Types | Description |
-------------|--------------
`char`       | a single byte, capable of holding one character
`int`        | an integer, typically 4 bytes (32 bits) but at least 16 bits
`short`      | an integer, short for `short int`, typically 2 bytes (16 bits) and at least 16 bits, `short` must be *no longer* than `int`
`long`       | an integer, short for `long int`, typically 8 bytes (64 bits) but at least 32 bits, `int` must be *no longer* than `long`
`long long`  | an integer, short for `long long int`, typically 8 bytes (64 bits) but at least 64 bits,`long` must be *no longer* than `long long` (older C versions do *not* support this data type)
`float`      | single-precision floating point
`double`     | double-precision floating point
`long double`| extended-precision floating point

* You can add the *qualifier* `signed` or `unsigned` to `char` or any integer type. `unsigned` numbers are always positive or zero.
For example, if `char`s are 8 bits, `unsigned char` variables have values
between 0 and 255, while `signed char`s have values between -128 and 127 in a *two's complement* machine. 
The C language does not specify whether variables of type `char` are signed or unsigned quantities. **Learn more about `char`s and integers through [code](code/integers.c)**.
* As with integers, the sizes of floating-point objects are implementation-defined. Floating-point numbers are often approximations.
**Learn more about floating-point numbers through [code](code/floats.c)**.
    > In general, mathematical functions like those in `<math.h>`
    > will use *double precision*. 
    > The main reason for using `float` is to save storage in large arrays,
    > or, less often, to save time on machines 
    > where double-precision arithmetic is particularly expensive.
    > I recommend using `double` whenever possible.
* In C, boolean is *not* a fundamental type. In fact,
you can simply use integers to represent boolean `true` and `false`.
Zero is `false`, and *any* non-zero integer is `true`.
However, you can `#include <stdbool.h>` to declare a `bool` data type
and use `true` and `false`. Here is a simple [code example](code/bools.c).

<details>
<summary>Additional Notes on Type Conversions</summary>

Conversions take place across *assignments*; 
the value of the right side is converted to the type of the left, 
which is the type of the result.
Some of the conversion rules are implementation dependent.
However, it is *always* true that, for example:
*  `float` to `int` causes **truncation** of any fractional part.
* Longer integers are converted to shorter ones or to `char`s 
by dropping the excess high-order bits.

Type conversion also takes place when arguments are passed to functions.
If arguments are declared by a function prototype, as the normally should be, 
the declaration causes *automatic coercion* of any arguments when the function is called.
> **I do not expect you to remember all the rules,
> except for the ones that are intuitive,
> but _when in doubt, code_.**

**Explicit type conversions** can be forced ("coerced") in any expression, 
with a unary operator called a `cast`. You should have seen it in Java.
Note that the cast produces the
*value* of a casted variable in the proper type; 
the variable itself is not altered.
</details>

#### Constants <a name="constants"></a>
You see some examples and explanations of integer and floating-point constants
from [this](code/integers.c) and [this](code/floats.c) source code files, respectively.

The character constant `'\0'` represents the character with value zero, 
the **null character**. 
`'\0'` is often written instead of the number 0 
to emphasize the character nature of some expression, 
but the numeric value is just 0.

A **constant expression** is an expression 
that involves *only* constants. Such expressions may be
evaluated at during *compilation* rather than run-time, 
and accordingly may be used in any place that a constant can occur.
For example:
```c
#define LEAP 1 /* in leap years */
int days[31+28+LEAP+31+30+31+30+31+31+30+31+30+31];
```

A **string constant**, or **string literal**, 
is a sequence of *zero or more characters* surrounded by
**double quotes**. For example:
```c
#define STRING_CONST "I am a string"
#define EMPTY_STRING ""
```
The quotes are not part of the string, but serve only to delimit it.
The same escape sequences used in character constants apply in strings.
String constants can be concatenated *at compile time*.
> Be careful to distinguish between a character constant and a string
> that contains a single character: `'x'` is not the same as `"x"`. 
> The former is an integer, used to produce the numeric value 
> of the letter x in the machine's character set. 
> The latter is an array of characters that contains one character 
> (the letter x) and a `'\0'` 
> (see why it contains a terminal `'\0'` in the [Strings](#strings) section).

We will learn more about strings in the [Strings](#strings) section.

Notice in the example above, we use a `#define` line,
which defines a **symbolic name** or **symbolic constant**
to be a particular string of characters.
Thereafter, any occurrence of, e.g., `STRING_CONST` will be replaced
by the corresponding string (i.e., `"I am a string"`).
In our temperature conversion example,
instead of using **magic numbers** like 300 and 20,
which convey little information 
to someone who might have to read the program later
and therefore make it hard to change these values in a systematic way,
we can do the following:
```c
#define LOWER 0     /* lower limit of table */
#define UPPER 300   /* upper limit */
#define STEP 20     /* step size */
```
The quantities `LOWER`, `UPPER`, and `STEP` are symbolic constants, 
not variables, so they do not appear in variable declarations.
* Symbolic constant names are conventionally written in upper case so
they can ber readily distinguished from lower case variable names.
* There is **no semicolon** at the end of a `#define` line

<details>
<summary>:heavy_plus_sign: Good To Know</summary>

There is one other kind of constant, the **enumeration constant**. 
An enumeration is a list of constant integer values. For example,

```c
enum months { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
```
The first name in an `enum` by default has value 0, the next 1, and so on, unless explicit values are specified (like in the example above). 
If not all values are specified, 
unspecified values continue the progression from the last specified value
(so in the example above, `FEB` has value 2, `MAR` has value 3, and so on).
* Names in different enumerations must be distinct. 
* Values need not be distinct in the same enumeration. 

</details>

#### Control Flow <a name="control-flow"></a>
The control flow of a language specify the order in which computations are performed.
You should already be familiar with conditionals and loops.
We will do a quick review here.

In the example, we see a `while` loop:
```c
while (fahr <= upper) {
    ...
}
```
The condition in parentheses is tested. If it is true 
(`fahr` is less than or equal to `upper`, so the value in parentheses is *non-zero*), 
the body of the loop is executed. 
Then the condition is re-tested, and if true, the body is executed again. 
When the test becomes false (`fahr` exceeds `upper`, and the value becomes zero), the loop ends, 
and execution continues at the statement that follows the loop.
Make sure you always properly indent the statements in the body of the loop.

We can rewrite the `while` loop above into a `for` loop:
```c
for (fahr = 0; fahr <= 300; fahr = fahr + 20)
    printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
```
As you should already know,
within the parentheses, there are three parts, separated
by semicolons:
* The first part, the **initialization**, is done once, before the loop proper is entered.
* The second part is the test or **condition** that controls the loop.
This condition is evaluated; if it is true, the body of the loop is executed.
* The **increment** step is executed after the body of the loop, and the condition re-evaluated. The loop terminates if the condition has become false.

*Any of the three parts can be omitted, although the semicolons must remain.* Therefore:
```c
for (;;) {
    ...
}
```
is an **infinite** loop, 
presumably to be broken by other ways, like a `break` or `return` statement.
While the components of the `for` within the parentheses can be arbitrary expressions,
it is *bad style* to force unrelated computations into the initialization and increment of a `for`.

> We will skip the discussion of `if`/`else`/`else if`/`switch` or `do-while` loops,
> because they are the same in Java.
>
> Come back here after you have learned about [character arrays](#characters-and-character-arrays) and
> seen [this](code/array.c) code example.
> Could you rewrite the code using `switch`?
> <details>
> <summary>Answer</summary>
>
> Check out the solution [here](code/array_switch.c) after you have tried yourself!
> </details>
>
> In C, just like in Java, we can use **conditional expression**,
> written with the **ternary operator** `?:` to provide a more succinct way
> of writing a simple `if/else` block. See if you can tell what the following
> code snippet does:
> ```c
> for (i = 0; i < n; i++)
>     printf("%6d%c", a[i], (i%10==9 || i==n-1) ? '\n' : ' ');
> ```
>
> <details>
> <summary>Answer</summary>
>
> This loop prints n elements of an array, 10 per line, 
> with each column separated by one blank, and with each line
> (including the last) terminated by a newline.
> </details>
>
> How about this code snippet?
> ```c
> printf("You have %d item%s.\n", n, n==1 ? "" : "s");
> ```
> <details>
> <summary>Answer</summary>
>
> Whether the letter "s" is printed or not depends on the number of items.
> </details>
>

A `break` causes the *innermost* enclosing loop or `switch` to be exited immediately.
The `continue` statement causes the next iteration of the enclosing `for`, `while`, or `do-while` loop to begin.

:bangbang: C provides the infinitely-abusable `goto` statement (:new:), and labels to branch to.
You want to use `goto` rarely, if at all, because the `goto` statement is never necessary!
Code that relies on `goto` statements is generally harder to understand and to maintain 
than code without `goto`s.
The most common usage is to abandon processing in some deeply nested structure, 
such as breaking out of two or more loops at once. 
The `break` statement cannot be used directly 
since it only exits from the innermost loop:
```c
for ( ... )
    for ( ... ) {
        ...
        if (disaster)
            goto error;
    }
...
error:
    /* clean up the mess here */
```
The scope of a label (like `error` in the example above) is the entire function.

#### Arithmetic, Relational, and Logical Operators <a name="arithmetic-relational-and-logical-operators"></a>
C operators are similar to the ones you have encountered in Java.
Keep in mind that:
* **Integer division truncates**: any fractional part is discarded.
* If an arithmetic operator has *only* integer operands, 
an integer operation is performed. 
If an arithmetic operator has *one* floating-point operand 
and one integer operand, 
however, the integer will be converted to floating point 
before the operation is done.
* The *binary arithmetic operators* are `+`, `-`, `*`, `/`, 
and the *modulus operator* `%`.
* The `%` operator cannot be applied to a `float` or `double`.
    > What about negative operands? Let's find out by [coding](code/negatives.c).
* Arithmetic operators associate left to right.
The binary `+` and `-` operators have the same precedence, 
which is lower than the precedence of `*`, `/` and `%`, 
which is in turn lower than **unary** `+` and `-`.
    > *Implicit arithmetic conversions* work like in Java.
    > The general rule of thumb is that, if a binary operator has operands
    > of different types, *the "lower" type is **promoted** to the "higher" type*
    > before the operation proceeds.
* Most binary operators (e.g., `+`, `-`, `%`, `<<`, `&`[^operators])
have a corresponding **assignment operator**, `+=`, `-=`, `%=`, etc..
Using assignment operators whenever you can, because the resulting code (1) is more concise,
(2) is less error-prone, (3) is easier to understand, and more importantly,
(4) helps a compiler to produce efficient code.
* The *relational operators* are `<`, `>`, `<=`, `>=`, and
they all have the same precedence. They have lower precedence than arithmetic operators.
* The *equality operators*, `==` and `!=`, have lower precedence than
the relational operators above.
* The *logical operators* `&&` and `||` are evaluated left to right, 
and *evaluation stops as soon as the truth or falsehood of the result is known*.
    > This is also known as "lazy evaluation;" you should have seen it in Java.
    > Lazy evaluation is sometimes important to the correctness of a C program.

    The precedence of `&&` is higher than that of `||`, 
    and both are lower than relational and equality operators.
* *The numeric value of a relational or logical expression is 1 if the relation is true,
and 0 if the relation is false*.
* The *unary negation operator* `!` converts a non-zero operand into 0, 
and a zero operand into 1.
* The **increment operator** `++` adds 1 to its operand, 
while the **decrement operator** `--` subtracts 1.
They may be used either as *prefix* operators 
(before the variable, as in `++n`), 
or *postfix* operators (after the variable, `n++`).
Like in Java, the expression `++n` increments `n` before its value is used, 
while `n++` increments `n` after its value has been used.
The increment and decrement operators can only be
applied to variables; an expression like `(i+j)++` is illegal.

> :bangbang: C does not specify the *order* in which the operands of an operator 
> are evaluated, with the exceptions of `&&`, `||`, `?:`, and `,`. This means,
> for example,
> ```c
> x = f() + g();
> ```
> `f` may be evaluated before `g` or vice versa; thus if either `f` or `g` alters a variable 
> on which the other depends, `x` can depend on the order of evaluation.
> Similarly, *the order in which function arguments are evaluated is not specified*, so:
> ```c
> printf("%d %d\n", ++n, power(2, n)); /* this is bad */
> ```
> can produce different results with different compilers, 
> depending on whether `n` is incremented before `power` is called.
> The moral is that **writing code that depends on order of evaluation is a bad programming practice** 
> in any language.
> 
> <details>
> <summary>:heavy_plus_sign: Good To Know</summary>
>
> *Function calls, nested assignment statements, and increment and decrement operators* cause
> "**side effects**" - some variable is changed as a by-product of the evaluation of an expression.
> In any expression involving side effects, 
> there can be subtle *dependencies on the order* in which variables taking part 
> in the expression are updated. For example:
> ```c
> a[i] = i++;
> ```
> The question is whether the subscript is the old value of `i` or the new. 
> Compilers can interpret this in different ways and generate different answers depending on their interpretation. 
> The standard intentionally leaves most such matters unspecified.
> However, the standard does specify that all side effects on *arguments*
> take effect *before a function is called*, but that would not help in the call to `printf` example above.
> </details>
>

[^operators]: We will learn **bitwise operators** (which are also binary operators) in a future [module](../data-representation/notes.md#bitwise-operators). 

## Standard IO <a name="standard-io"></a>

> :information_source: Standard IO in C deviates significantly from Java! It is important 
> that you have a good mental picture of how characters and strings are represented in C.

We will start our discussion of IO (input/output)
with text input and output.
Processing character data introduces us
to the fundamentals of more complex data processing in C.
Note that IO is not part of the C language itself 
but defined in a useful **standard library**,
and it is a lot more involved than in Java.

> You will likely need to include the following libraries:
> `<stdio.h>`, `<string.h>`, and perhaps `<ctype.h>`.

### Characters and Character Arrays <a name="characters-and-character-arrays"></a>
Text input or output, 
regardless of where it originates or where it goes to, 
is dealt with as **streams of characters**. 
A *text stream* is **a sequence of characters** divided into lines; 
each line consists of zero or more characters *followed by a newline character*.

The standard library (which we use when we put `#include <stdio.h>` in our program)
provides several functions for reading or writing one character at a time.
For example:
* `int getchar(void)`: reads the next input character 
from a text stream and returns that as its value,
or `EOF` when it encounters end of file.
    > The symbolic constant `EOF` is defined in `<stdio.h>`.
    > Did you notice that the return type is `int`, rather than `char`? Why is that?
    > <details>
    > <summary>Answer</summary>
    >
    > Because `getchar` needs to be able to return
    > *all* possible characters, as well as
    > `EOF` (whose value is typically `-1`)!
    > </details>
    >
    > `getchar` can take input directly from
    > the keyboard, or *a file may be substituted for the keyboard*
    > through **input redirection** 
    > (using `<` in the command line)
    > or via a **pipe** (`|`) mechanism[^linux].
    > 
* `int putchar(int)`: for output. It prints a character each time it is called 
(here, an `int` variable being printed as a character)
on the **standard output**, which is by
default the screen.
`putchar` returns the character written, 
or `EOF` if an error occurs.
Like in `getchar`, you can use redirection
(`>` in the command line)
to write the standard output to a file
or via **pipes** (`|`)
to puts the standard output into 
the standard input of another program.

[^linux]: We may or may not cover
I/O redirection and/or piping
in this course. 
If we do,
we will talk about them 
when we discuss Linux; 
otherwise, you can safely ignore them,
for example,
when you prepare for your exam 
(but you will encounter them
sooner or later in your programming career).

**Check out a code example of using `getchar()` [here](code/external.c)
and [here](code/chars.c).**

> Before we talk about character arrays, let's briefly review the basics of arrays in C
> by looking at a [code example](code/array.c).
> At a high level, arrays in C look just like arrays in Java.
> We will learn about arrays in more detail later in a different module.

One of the most common type of arrays in C is the array of characters.
Let's learn more about character arrays through [code](code/chararray.c).
This code performs the same function as the [code](code/external.c)
we introduced when we were discussing [external variables](#variables-and-scope).
Recall that **in C, all function arguments are passed by value**,
so the original arguments do not change.
So, what happened to the character array arguments there?

At the end of the day,
a `char` is just a small integer, 
so `char`s may be freely used in arithmetic expressions.
Take a look at this example:
```c
int atoi(char s[])
{
    int i, n;
    
    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}
```
What does it do?
<details>
<summary>Answer</summary>

The function converts a string of digits into its numeric equivalent.
Do you recall the way we compute the numeric value of a `char` digit
in a previous [code example](code/array.c)? We do the same here in `atoi`.
The standard library `#include <stdlib.h>` 
provides a more elaborate function `strtol`
for conversion of strings to long integers.
</details>

The standard header `<ctype.h>` defines a family of functions that
provide tests and conversions that are independent of character set.
For example, it defines a function
```c
isdigit(c)
```
to check if `c` is a digit or not.
> Functions like `isdigit` may return *any non-zero value* for true.
> This is unlike relational or logical expressions, which always have
> value 1 if true and 0 if false (see the discussion [above](#arithmetic-relational-and-logical-operators)).
> However, in C, "true" really just means "non-zero".

:bangbang: **You should use functions defined in `<ctype.h>` (or any other standard libraries) 
whenever possible, 
instead of defining your own functions that perform the
same functionality, unless you are told otherwise.**

> The definition of C guarantees that any character in the machine's standard printing character set will *never be negative*, 
> so these characters will always be positive quantities in expressions. 
> But arbitrary bit patterns stored in character variables may appear to be negative
> on some machines, yet positive on others (recall that the C language does
> not specify whether variables of type `char` are signed or unsigned quantities).
> For portability, **specify signed or unsigned if non-character
> data is to be stored in `char` variables**.

### Strings <a name="strings"></a>
A *string constant* is **an array of characters**. 
The internal representation of a string *has a null character* `'\0'` *at the end*, 
so the *physical storage* required is one more than 
the number of characters written between the quotes.
* No limit to how long a string can be.
* You must scan a string completely to determine its length.
    > The stopping condition is when you scan the terminal `\0` character.
    > For example, here is one way to get the length of a string:
    > ```c
    > /* strlen: return length of s */
    > int strlen(char s[])
    > {
    >     int i;
    >     while (s[i] != '\0')
    >         ++i;
    >     return i;
    > }
    > ```
    > The standard library (`#include <string.h>`) has a better implementation 
    > of the `strlen(s)` function.
    > It also returns the length of its character string argument `s`, 
    > excluding the terminal `'\0'`.

### Formatted Output <a name="formatted-output"></a>
`printf` converts, formats, and prints 
its arguments on the *standard output* 
under control of the `format`. 
It returns *the number of characters printed*[^string].

[^string]: The type `char *` of the first
format argument might look strange to you.
For now, think of it to be the same as
a character array type `char []`.
We will learn about `*` in a later [module](../c-pointers/notes.md).

```c
int printf(char *format, arg1, arg2, ...);
```
* The `format` string contains two types of objects: **ordinary characters**, which are copied to the output stream, 
and **conversion specifications**, 
each of which causes conversion and printing of
the next successive *argument* to `printf`.
    > You should notice the similarity between
    > C's `printf` and Java's.
* Each conversion specification 
begins with a `%` and
ends with a **conversion character**.
    > Basic `printf` Conversion Characters:
    > | Conversion Character | Argument Type (Printed As) |
    > -----------------------|-----------------------------
    > `d`, `i` | `int`(decimal number)
    > `o` | `int` (unsigned octal number without a leading zero)
    > `x`, `X` | `int` (unsigned hexadecimal number, without a leading `0x` or `0X`; using abcdef or ABCDEF for 10, ...,15)
    > `u` | `int` (unsigned decimal number)
    > `c` | `int` (single character)
    > `s` | `char *` (print characters from the string until a `\0` or the number of characters given by the precision)
    > `f` | `double` (`[-]m.dddddd`, where the number of `d`'s is given by the precision, default 6)
    > `e`, `E` | `double` (`[-]m.dddddde+/-xx` or `[-]m.ddddddE+/-xx`, where the number of `d`'s is given by the precision, default 6)
    > `p` | `void *` (pointer)
    > `%` | print a `%` character
* Between the `%` and the conversion character there may be, in order:
    1. **A minus sign**, which specifies left adjustment of the converted argument.
    2. **A number that specifies the minimum field width.** 
    The converted argument will be printed 
    in a field at least this wide. 
    If necessary it will be padded on the left 
    (or right, if left adjustment is called for) 
    to make up the field width.
    3. **A period**, which separates the field width from the *precision*.
    4. **A number, the precision**, that specifies the maximum number of characters to be printed 
    from a string, 
    or the number of digits 
    after the decimal point of a floating-point value,
    or the minimum number of digits for an integer.
    5. An `h` if the integer is to be printed 
    as a `short`, 
    or `l` (letter ell) if as a `long`.

**Let's take a look at some [code examples](code/prints.c).**

<details>
<summary>:heavy_plus_sign: Good To Know</summary>

Did you notice I used `...` in `printf`?
This is because it is a 
function that processes a **variable-length argument list**
(i.e., the *number* and *types* of these arguments may vary).
The declaration `...` is a C syntax
that can *only appear at the end of an argument list*.

Implementing a function that processes a variable-length argument list
is an advanced topic in C that will not be covered in this course.

</details>

### Formatted Input <a name="formatted-input"></a>
The function `scanf` is the input analog of `printf`, 
providing many of the same conversion facilities 
in the opposite direction.
```c
int scanf(char *format, ...)
```
`scanf` reads characters from the standard input, 
interprets them according to the specification
in `format`, 
and stores the results through the remaining arguments.
The table below shows valid conversion characters[^pointers].
| Character | Input Data (Argument Type) |
------------|-----------------------------
`d` | decimal integer (`int *`)
`i` | integer (`int *`; the integer may be in octal - leading 0 - or hexadecimal - leading 0x or 0X)
`o` | octal integer, with or without leading zero (`int *`)
`u` | unsigned decimal integer (`unsigned int *`)
`x` | hexadecimal integer, with or without leading `0x` or `0X` (`int *`)
`c` | characters (`char *`; the next input characters, default 1, are placed at the indicated spot. The normal skip-over white space is suppressed; to read the next non-white space character, use `%1s`)
`s` | character string, not quoted (`char *`, pointing to an array of characters long enough for the string and a terminating `'\0'` that will be added)
`e`, `f`, `g` | floating-point number with optional sign, optional decimal point and optional exponent (`float *`)
`%` | literal `%`; no assignment is made

The conversion characters `d`, `i`, `o`, `u`, and `x` 
may be preceded by `h` to indicate that a pointer to
`short` rather than `int` appears 
in the argument list, 
or by `l` (letter ell) to indicate that a pointer
to `long` appears in the argument list.

* The other arguments in `scanf`, 
**each of which must be a pointer**[^pointers], 
indicate where the corresponding converted input should be stored.
* `scanf` stops when *it exhausts its `format` string, 
or when some input fails to match the control specification*.
* `scanf` returns as its value 
the number of successfully matched and assigned input items. 
This can be used to decide 
how many items were found. 
On the end of file, `EOF` is returned.
    > Note that this is different from 0, 
    > which means that the next input character 
    > does not match the first specification in the format string.
* The next call to `scanf` resumes searching
immediately after the last character already converted.
* Like in `printf`, the `format` string usually contains 
conversion specifications,
which direct the conversion of the input fields.
An input field is defined as **a string of non-white space characters**; it extends either to the next white space character 
or until the field width, if specified, is exhausted. 
(note that newlines are white space).
* `scanf` *ignores blanks and tabs in its format string*. 
Furthermore, it *skips over white space (blanks, tabs, newlines, etc.) 
as it looks for input values*.
* **To read input whose `format` is not fixed, 
it is often best to read a line at a time, 
then pick it apart with `scanf`.** See the example code below.
* Calls to `scanf` can be mixed with calls to other input functions. 
The next call to any input function will begin 
by reading the first character **not** read by `scanf`.

**Let's take a look at some [code examples](code/scans.c).**

[^pointers]: We see more `*`s following some
types that we are familiar with, like `int *`.
`*` in this case means a **pointer**.
We will learn about pointers in a later [module](../c-pointers/notes.md#pointers-and-addresses).

<!-- Things to cover in a different module: -->
<!-- pipe (?) and input redirection (?) in command line -->
<!-- * Add links to different modules -->