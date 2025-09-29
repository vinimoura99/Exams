Assignment name: buffer_stdin
Expected files: buffer_stdin.c
Allowed functions: read, write, malloc, free
--------------------------------------------------------------------------------

Write a program that reads from stdin using a buffer and prints to stdout.

Your program will read from stdin using a buffer of size BUFFER_SIZE.
Handle partial reads and print the content to stdout.

For example:
$> echo "Hello World" | ./buffer_stdin
Hello World

NOTES:
- Use BUFFER_SIZE = 10
- Handle partial reads (when read() returns less than BUFFER_SIZE)
- Handle the case when input is larger than buffer
- Return 0 on success, 1 on error

HINT: This prepares you for buffered reading in filter

******************************************************************************************************
                            Diferenca do Stdin_Read e Buffer_Read
******************************************************************************************************

| **stdin_read**                                                   | **buffer_stdin**                                                                                     |
| ---------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------- |
| Lê 1 caractere por vez (`read(0, &buf, 1)`)                      | Lê vários caracteres por vez (`read(0, buf, BUFFER_SIZE)`)                                           |
| Não precisa de buffer alocado dinamicamente (ou malloc opcional) | Precisa de **buffer de tamanho BUFFER_SIZE**                                                         |
| Simples loop até EOF                                             | Loop até EOF, mas precisa lidar com **retornos menores que BUFFER_SIZE**                             |
| Ideal para começar, mas lento para textos grandes                | Mais eficiente para textos grandes porque lê em blocos                                               |
| Cada `read` geralmente lê 1 byte                                 | Cada `read` tenta ler **até BUFFER_SIZE bytes**, mas pode ler menos → precisa verificar `bytes_read` |
