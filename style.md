# Style
Coding style refers to the *literary aspects* of software.
For example, it answers the questions:
*What vocabulary is used? How are functions and variables named?* 
*What are the spelling and punctuation conventions?*
*What [orthography](https://en.wikipedia.org/wiki/Orthography)?*

Everyone has their own speaking style, 
their own prose style, 
and their own coding style. 
This is great, but *some coding styles are worse than others*. 
Code should not only be correct and performant; 
it should also be **readable** and easily **understandable** 
by other human beings, such as your future self. 
Anyone can read the code they wrote earlier that day. 
The real test comes a couple days later during *debugging*! 
Since humans often need to understand or modify code, 
coding styles that confuse human readers cause problems. 
In the conflict between [descriptive](https://en.wikipedia.org/wiki/Linguistic_description#Descriptive_vs._prescriptive_linguistics) 
and [prescriptive](https://en.wikipedia.org/wiki/Linguistic_prescription) linguistics, 
coding style must be a little **prescriptive**.

The best way to make code readable is to 
pick a **consistent** style and stick with it. 
*The best styles to pick are those with precedent in others’ code.*

This guide isn't about mandatory rules; 
treat it instead as a set of suggestions. 
Alternatively, you can follow the [K&R style](http://www.cas.mcmaster.ca/~carette/SE3M04/2004/slides/CCodingStyle.html), 
named after its authors, Brian Kernighan and Dennis Ritchie, 
who created the C programming language;
or perhaps [GNU's style guidelines on C](https://www.gnu.org/prep/standards/standards.html#Writing-C).

## Example: The Three Bears
What does this code do?
```c
int srev(char*x, char*y) { int l;for(l=0; y[0];l++)
  y++;while(l){*x++ =*--y;--l;
      }*x = NULL
      ;}
```
How about this code?
```c
int reverse_string(char* the_input_string, char* the_string)
{
   // Function: The characters in "the_input_string" are reversed and stored into "the_string".
   // For instance, if "the_input_string" equals "abcde", then after the function returns,
   // "the_string" will equal "ebcda". The function returns 0 on success and -1 on failure.

   int length_of_string = strlen(the_input_string);
   int position = 0;      // tracks our position in the OUTPUT string
   int reverse_position = 0; // tracks our position in the input string
   char *the_output_string;        // the destination of the copy

   the_output_string = the_string;


   // We want to copy the_input_string IN REVERSE!!! So we need to move reverse_position to the 
   // END of the_input_string first.

   for (reverse_position = 0; ; reverse_position += 1)
   {

       // When we reach a null character we are at the end of the string!
       if (the_input_string[reverse_position] == NULL)
       {

            // So we should exit the loop
            break;
       } // end if

   } // end for

   // That loop left reverse_position pointing ONE BEYOND the last character in the string. That's no good!
   reverse_position -= 1;

   // Now run backwards!!
   while (reverse_position >= 0)
   {

       // Make sure we really have a character!!
       assert(the_input_string[reverse_position] != '\0');

       // OK, we have a character.
       // Better copy it to the output string!
       memcpy  (&the_output_string[position],
               &the_input_string[reverse_position],
               1);

       // Great, we did the copy!! Advance to the next position in the output string.
       position += 1;
       // And back up to the PREVIOUS position in the INPUT string!
       reverse_position -= 1;

    } // end while

    // OK, we've copied all the characters into the output string. But we're not done yet!!!
    // We did not copy the last character in the string. Better do that now.
    memset(&the_output_string[position], '\0', 1);

    // Now we're really done!!
    return position;


} // end reverse_string function!
```
And finally, what does this code do?
```c
/** @brief Reverse the characters of @a src into @a dst, returning the length of @a src. */
size_t strreverse(char* dst, const char* src) {
    assert(dst && src);  // neither parameter should be NULL
    assert(dst != src);  // we can’t reverse a string into itself
    size_t len = strlen(src);
    for (size_t pos = 0; pos != len; ++pos) {
         dst[pos] = src[len - pos - 1];
    }
    dst[len] = 0;
    return len;
}
```
They all do the *same* thing: they reverse the input string. 
But we feel the style of the third example is much better 
than the styles of the first two. 
The first example is **too terse**, 
the second **too verbose**, 
and the third pretty good. 
Here are some of the problems with the first two examples, 
and how the third example avoids them.

### Example 1
- **Inscrutable variable and function names** don't give good hints 
about the function’s behavior. What does `x` represent? How about `y`? And `srev`?
- **Horrible, inconsistent indentation** makes the program look like random noise.
- No explanatory comments.
- **No parameter checking**.
- **Incorrect code**: the function claims to return an `int`, 
but the function body doesn't even have a `return` statement.

### Example 2
Beginning students often err in this direction: making code *too verbose*.
- **Verbose variable names** (`the_string`, `the_input_string`) 
take up space and mental energy *without adding descriptiveness*.
- Even though the variable names are verbose, 
they're **inconsistent**. 
`length_of_string` is actually `length_of_input_string`. 
Why have both `the_string` and `the_output_string`?
Why not call the parameter `the_string` `the_output_string` instead, 
to contrast with `the_input_string`?
- **Chatty comments** that repeat information obvious from the code 
(e.g., `// end if.`).
- **Comments that lie**.
The comment above `memset`, near the end of the function, 
claims that the line copies the last character in the input string. 
*No, it doesn't*: 
the line terminates the output string with a null character. 
The header comment claims the function returns 0 or -1. 
*No, it doesn't*: 
it returns the length of the input string.
- **Unused variables** (`length_of_string`). 
Did the programmer make them redundant and then just forget to remove them, 
or does the programmer really need them
but hasn't gotten around to using them yet? 
If you really intend to leave a variable unused, 
tell the reader explicitly, 
with a statement like "`(void) length_of_string;`".
- **Type mixups**. 
An if statement in the first loop 
compares a character against `NULL`,
but `NULL` is a pointer, not a character. 
Use the right types to show you understand what's going on.
- **Redundant assertions**. 
Consider `assert(the_input_string[reverse_position] != '\0')`. 
The code above the loop ensures that this assertion is true. 
The assertion indicates that the programmer didn't understand their own code.
- **Not using standard library functions**. 
The first loop could be written much shorter 
as `reverse_position = strlen(the_input_string);`. 
The standard library, particularly the simple functions like `strlen`, 
forms a basic vocabulary all C programmers share. Use it!
- **Not following standard library conventions**. 
Most C standard library string functions have names that start with `str`. Furthermore, those standard functions modify their *first* argument. 
For example, `strcpy(a, b)` copies the string `b` into the string `a`. 
This function modifies its *second* argument.
- **Overusing standard library functions**. 
Note the use of `memcpy` inside the second loop to copy a single character.

> :bangbang: In CSC 250, you are expected to *gradually* but *surely* develop
> a good, consistent coding style that avoids all the issues discussed above
> and continue with your professional coding style to CSC 251
> and your future programming-related career.

### Example 3
- Short, yet evocative, variable names (e.g., `dst` and `src`).
- Use of C types to provide more information about arguments 
(the `const` in `const char* src` promises that 
the function will not modify the characters in `src`).
- Standard library functions used when appropriate (`strlen`).
- Types match standard library types (`strlen` returns `size_t`, 
so does this function).
- Following standard library conventions for function names and argument order.
- Correct, yet brief, description of the function's job.
- Assertions that check for error conditions, including the one you might not have thought of on first reading.

You may find Example 3 harder to follow 
than Example 2 at first. 
Learning to read code like Example 3 quickly is a skill, 
and talented programmers will disagree on 
whether Example 3 is really "just right", or too terse. 
Feel free to write code to your taste, but do think about your style, 
and think about the points above,
and *you'll become a better programmer naturally*.

## Rule of Thumb
**Be consistent…**

- If a construct appears more than once, 
you should format it *the same way* each time. 
So, format function calls the same way each time; 
name variables in similar ways; and so forth.
- Develop a set of conventions and stick to them.

**…within reason.**

No conventions will fit all situations. 
The end goal is **readability**; 
don’t lose sight of it.

## Style Guidelines
While it doesn't really matter how you format your program,
as long as you do so **consistently** and apply the same style rules uniformly to your program,
here are some guidelines we would like you to *strictly follow*
to help you develop a good coding style.
**We enforce these guidelines** when we grade your assignments.
A significant deviation from these guidelines
will result in penalties.

### Formatting
* Choose an indentation depth and stick with it. 
*4 spaces is a common indentation depth*, and the code we hand out indents by 4 spaces.
* Use line breaks to separate logical sections in your program.
* Separate larger programs into files. 
Each file (except for the one containing `main`) 
should have a corresponding header file 
that declares all functions, constants, and global variables meant to be visible outside the file.
* Separate longer files into sections. 
For example, group all the macros together, all the data structure definitions together, all the global variables together, etc.
    > We recommend that you structure your program similar to the example below.
    > ```c
    > /**
    >   * start of file comments
    >   **/
    >
    > #include <stdio.h>
    > #include <stdlib.h>
    >
    >
    > /* global type and constant definitions */
    > #define MAX_STRING 20
    >
    >
    > /* struct definitions */
    > struct WordStats {
    >   char* str;  /* word C-string */
    >   int   num;  /* frequency */
    > };
    >
    >
    > /* function prototypes */
    > void push(int item);
    > int pop();
    >
    >
    > /* start function definitions, main() should be first */
    > int main(const int argc, char *argv[])
    > {
    >     /* body of the main() function */
    > }
    >
    >
    > /**
    >   *  function header comment
    >   **/
    > void push(int item)
    > {
    >     /* body of the push() function */
    > }
    >
    >
    > /**
    >   *  function header comment
    >   **/
    > int pop()
    > {
    >     /* body of the pop() function */
    > }
    >
    > ```
* Avoid super long lines. 80 characters is a common limit, 
but it's not a hard limit in this course.
* Be *consistent* with curly brackets.
    > We recommend placing the opening brace 
    > at the end of the line, e.g., in `if` and `for` statements,
    > except for functions, in which case we recommend
    > placing the opening brace at the beginning of the *next line*.
* Be *consistent* with white space between operators.
    > We recommend using white space around binary operators, 
    > except for struct and pointer references,
    > and *not* using white space between a unary operator and its operand. 
* A variable or function name should be **clear** and **concise**, 
such that the name is sufficient to understand the purpose of the variable/function/struct. Use **consistent** naming styles.

### Comments
Commenting is good, 
but commenting too much can be bad. 
Even worse, 
comments need to be updated when code is changed, 
so having more comments requires more maintenance.

Ideally, you should try to create code 
that is itself readable 
and does not require comments. 
This isn't always possible though, 
so comments may be necessary 
to explain especially tricky or complicated sections 
in your program. 
If another student cannot read your code 
(or worse, you cannot understand your own code), 
*consider changing the code to be more readable*, 
or *add a comment if all else fails*. 
That said, here are some tips for commenting:
* Make the code itself readable.
* Comment the tricky sections or hacks.
* Avoid comments that simply repeat what the code does, 
or state the obvious.
* Write a brief comment at the top of each file 
explaining the purpose of the file.
The comment should also include the name(s) of programmer(s), 
the date the file was written.
    > We recommend that you follow the format below in this course:
    > ```c
    > /**
    >   * @author Your Name Here (jane.doe@wfu.edu)
    >   * @date Sept. 1, 2023
    >   * @course CSC 250
    >   * @assignment Lab 1
    >   *
    >   * This program ...
    >   **/   
    > ```
* Comment each function on what it does, 
what its arguments are, 
and what the return value is.
List *all error conditions* 
and what the function does with them. 
List any *side effects*.
If you borrow the algorithm from another source, 
credit the source and author(s).
See also the part about *Doxygen* below.

Although not required, 
one good practice is to use automatic documentation generators. 
[Doxygen](https://www.doxygen.nl/index.html) 
will scan through your source files 
and automatically generate documentation 
(as html, pdf, etc.), 
provided that your comments are formatted 
in a certain way. 
For Java programmers, this is very similar to *Javadoc*.

### Miscellaneous
* Check every return value for errors.
* Avoid creating global variables, unless it's really necessary.
* Avoid using `goto` unless it's absolutely necessary.
* Use macros instead of "magic numbers."
* Use prototypes (also called "signatures"), 
and put them either at the top of the source code file 
or in a corresponding header file (`foo.h`). 
`foo.c` will include `foo.h` and provide the actual implementations.
* When printing, 
it is good practice to append a newline `\n` 
to whatever string is being printed. 
This avoids anything printed afterward 
(expected or unexpected, like an error message) 
from messily joining to your intended message.
* Avoid calling `exit()` from anywhere other than `main()`. 
Unwind back to `main()` using error-return values and exit cleanly.
* Always initialize variables, 
either when they are created, 
or soon thereafter. 
Initialize pointers to `NULL` if target not yet known.
* **Make all functions small, coherent, and specific.** 
Every function should do exactly one thing. 
A good rule of thumb is that you should be able to describe 
what a function does in a single sentence. 
Generally, C functions occupy less than a page, 
with most functions occupying 10-30 lines.
* **Use small parameter lists**.
Avoid extremely long parameter lists. 
If you find the parameters to a function growing, 
ask yourself if the function is trying to do too much, 
or if the function is too vague in its intent.
* **Avoid deeply nested blocks.** 
Structures such as `if`, `for`, and `while` define blocks of code; 
blocks can contain other blocks. 
Try not to nest blocks too deeply. 
Any function with more than a couple levels of nesting can be confusing. 
If you find yourself with deeply nested structures, 
consider either simplifying the structure 
or defining functions to handle some of the nested parts.
* **Use the simplest algorithm that meets your needs.** 
Einstein once said: "Things should be as simple as possible, but no simpler." This is good advice for selecting an algorithm. 
There are a great many extremely clever, 
complex algorithms in computer science. 
Make an effort to know them 
and use the algorithm that meets your needs 
for efficiency. 
Do not shun complex algorithms, 
but do not choose them without reason.
* **Be consistent in numbers and types of function parameters.** 
If two functions perform a similar function, 
give them similar sets of parameters.

## :european_castle: Defensive Programming
It is important you write C programs **defensively**. 
That is, you need to check the input the program receives, 
make sure it is as expected (in range, correct datatype, length of strings, etc.), 
and, if it is not acceptable, 
provide appropriate message(s) back to the user 
in terms of the program usage. 
The user should never be able to cause your program 
to adversely impact any aspect of the system 
it's running on, 
including system files, 
other users' files or processes, 
or network access.

* Make sure command-line arguments and function parameters have legal values.
* Check the results of all calls to standard libraries or the operating system. For example, check all memory allocations (`malloc`) to detect out-of-memory conditions.
* Check all data obtained from users or other programs.
* Check limit conditions on loops and arrays. 
For example, what happens if you try to access a value that is out of bounds?
* When you detect an error condition, 
first consider ways to modify the code 
to prevent the error from happening 
in the first place. 
If that is not possible, 
ask if there is a way the code can recover from the error. 
If there is no reasonable way of recovering, 
print an error message and exit the program.

> :copyright: We thank **Eddie Kohler** for publicly sharing his wisdom
> of coding. We also express our appreciation to **Pete Santago**
> for some of the style guidelines. 