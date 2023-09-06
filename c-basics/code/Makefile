PROGRAMS = hello converter integers floats external chars array chararray negatives prints scans bools array_switch
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

hello converter integers floats external chars array chararray negatives prints scans bools array_switch: \
%: %.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(PROGRAMS) *.o

.PHONY: all clean
