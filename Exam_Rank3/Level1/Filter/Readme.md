Assignment name   : filter  
Expected files    : filter.c  
Allowed functions : read, malloc, free, realloc, write, printf, strlen  
--------------------------------------------------------------------------------

Write a program that reads text from the standard input (stdin) and filters out
a given word by replacing all its exact occurrences with a sequence of asterisks (*),
maintaining the rest of the text unchanged.

Your program must be executed as follows:

    ./filter <word_to_filter>

It should read from standard input and for each line, replace every occurrence of
<word_to_filter> with a sequence of '*' of the same length.

The replacement must be case-sensitive (e.g. "abc" is different from "ABC").

Words can appear anywhere in the text — including being embedded within other words —
and should still be replaced.

Each line from stdin must be processed and printed immediately after reading (you can assume
the input won't be too large for memory). Lines that end with '\n' should preserve the newline.

Your program will be compiled with the -D BUFFER_SIZE=xx flag, which must define the
buffer size used for your read() calls.

If the number of arguments is different from 1, your program must return 1 and do nothing.

Memory leaks are not allowed.

Examples:

Input:                          | Command:                 | Output:
------------------------------  |--------------------------|-------------------------
echo hello world, hello again   | ./filter hello           | ***** world, ***** again
echo abc123 abc abc             | ./filter abc             | ***123 *** ***
echo weabcabc                   | ./filter abc             | we******

Make sure your program behaves correctly with various buffer sizes
and handles stdin properly, including redirections and piped input.

--------------------------------------------------------------------------------
