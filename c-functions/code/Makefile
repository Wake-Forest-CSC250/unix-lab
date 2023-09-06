PROGRAMS = grep calculator main
# compiler flags
# Curious about what these flags do? 
# Check: https://gcc.gnu.org/onlinedocs/gcc/Option-Summary.html
ifeq ($(shell uname -s),Linux)
	STD := gnu1x
else
	STD := gnu2x
endif
CFLAGS := -std=$(STD) -Wall -Wpedantic -Wextra -Wshadow -ggdb -lm $(CFLAGS)

all: $(PROGRAMS)

grep:
	$(CC) $(CFLAGS) csc250_getline.c grep.c -o grep

calculator:
	$(CC) $(CFLAGS) csc250_getline.c atof.c calculator.c -o calculator

main:
	$(CC) $(CFLAGS) getch.c getop.c stack.c main.c -o main

clean:
	rm -rf $(PROGRAMS) *.o *.dSYM

.PHONY: all clean
