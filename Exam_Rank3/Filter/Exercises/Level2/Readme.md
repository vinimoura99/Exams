Assignment name: stdin_read
Expected files: stdin_read.c
Allowed functions: read, write, malloc, free
--------------------------------------------------------------------------------

Write a program that reads from stdin and prints to stdout.

Your program will read from stdin character by character and print to stdout.
Handle the case when stdin is empty or contains special characters.

For example:
$> echo "Hello World" | ./stdin_read
Hello World

NOTES:
- Use read() with fd 0 (stdin)
- Handle EOF properly
- Handle read errors
- Use a buffer of size 1 for simplicity
- Return 0 on success, 1 on error

HINT: This prepares you for reading from stdin in filter