Assignment name   : next_permutation
Expected files    : next_permutation.c
Allowed functions : write, printf

--------------------------------------------------------------------------------

Write a program that receives a string as an argument and prints all possible 
permutations of its characters in lexicographical order.

Your program must be executed as follows:

    ./next_permutation <string>

The first output must be the permutation in ascending (sorted) order. Each 
subsequent line must print the next lexicographical permutation until all 
permutations have been printed.

If the number of arguments is different from 1, your program must return 1 
and do nothing.

Memory leaks are not allowed.

Examples:

Input:          | Command:                    | Output:
----------------|----------------------------|---------------------
abc             | ./next_permutation abc      | abc
                |                            | acb
                |                            | bac
                |                            | bca
                |                            | cab
                |                            | cba

abcd            | ./next_permutation abcd     | abcd
                |                            | abdc
                |                            | acbd
                |                            | acdb
                |                            | adbc
                |                            | adcb
                |                            | ... (and so on)

Make sure your program handles strings of various lengths correctly and 
prints each permutation exactly once in lexicographical order.
