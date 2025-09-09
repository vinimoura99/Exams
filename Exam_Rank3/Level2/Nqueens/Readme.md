Assignment name : nqueens
Expected files : nqueens.c
Allowed functions: malloc, free, printf, atoi

Write a program that prints all the distinct solutions to the N-Queens problem for a given N.

Your program must be written in a single file named nqueens.c, and must be compiled using:

cc -Wall -Wextra -Werror nqueens.c -o nqueens

Your program must take a single command-line argument:
a positive integer N, representing the size of the chessboard and the number of queens.

For each valid solution, your program must print a single line containing N space-separated integers:
each integer represents the column index (starting from 0) of the queen in that row (from row 0 to row N-1).

Each solution must be printed on a separate line.

If the number of arguments is not 2, or if the provided argument is not a positive integer, the program must exit silently (return 1 and print nothing).

Your program must not leak memory.

Examples:

$ ./nqueens 4
1 3 0 2
2 0 3 1
$ ./nqueens
$ ./nqueens abc

Notes:

    No two queens must threaten each other:

        Only one queen per row and per column.

        No two queens may share the same diagonal.

    The order of the solutions does not matter.

    You must use a backtracking algorithm.

    Your program must be memory-safe and follow the allowed function rules.

