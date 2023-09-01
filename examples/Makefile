PROGRAMS = hello ints floats asm bugs
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

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

hello ints floats bugs: \
%: %.o
	$(CC) $(CFLAGS) -o $@ $^

asm:
	$(CC) -O2 -S hello.c

clean:
	rm -rf $(PROGRAMS) *.o *.s

.PHONY: all clean
