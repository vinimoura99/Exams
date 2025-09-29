Assignment name: string_replace
Expected files: string_replace.c
Allowed functions: write, strlen, malloc, free
--------------------------------------------------------------------------------

Write a program that replaces all occurrences of a substring in a string.

Your program will take two arguments: the original string and the substring to replace.
Print the string with all occurrences of the substring replaced by asterisks.

For example:
$> ./string_replace "hello world hello" "hello"
***** world *****

NOTES:
- Handle the case when the substring is not found
- Handle empty strings
- Handle overlapping occurrences
- Return 0 on success, 1 on error