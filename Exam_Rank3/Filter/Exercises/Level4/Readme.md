Assignment name: simple_filter
Expected files: simple_filter.c
Allowed functions: read, write, strlen, malloc, free
--------------------------------------------------------------------------------

Write a program that reads from stdin and replaces a substring with asterisks.

Your program will take one argument: the substring to replace.
Read from stdin and replace all occurrences of the substring with asterisks.

For example:
$> echo "hello world hello" | ./simple_filter "hello"
***** world *****

NOTES:
- Read the entire input into memory first
- Use strlen to get the length of the substring
- Replace with the same number of asterisks
- Handle the case when substring is not found
- Return 0 on success, 1 on error

HINT: This is a simplified version of filter