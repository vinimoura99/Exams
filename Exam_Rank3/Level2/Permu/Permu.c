#include <stdio.h>

/* ---------------------------------------------------
   Troca dois caracteres na string
--------------------------------------------------- */
void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

/* ---------------------------------------------------
   Ordena a substring str[start..end-1] em ordem crescente
--------------------------------------------------- */
void sort(char *str, int start, int end)
{
    int i = start;
    while (i < end - 1)
    {
        int j = i + 1;
        while (j < end)
        {
            if (str[i] > str[j])
                swap(&str[i], &str[j]);
            j++;
        }
        i++;
    }
}

/* ---------------------------------------------------
   Gera a próxima permutação lexicográfica
   Retorna 1 se conseguiu gerar, 0 se já estava na última
--------------------------------------------------- */
int next_perm(char *str, int len)
{
    int i = len - 2;

    // procura o primeiro caractere da direita que pode aumentar
    while (i >= 0 && str[i] >= str[i + 1])
        i--;

    if (i < 0)
        return 0; // última permutação

    // procura o menor caractere à direita maior que str[i]
    int j = len - 1;
    while (str[j] <= str[i])
        j--;

    swap(&str[i], &str[j]);        // troca
    sort(str, i + 1, len);         // ordena a direita

    return 1;
}

/* ---------------------------------------------------
   MAIN → prepara a string e imprime todas as permutações
--------------------------------------------------- */
int main(int ac, char **av)
{
    if (ac != 2)
        return 1;

    char str[100];
    int len = 0;

    // copia argumento para array
    while (av[1][len])
    {
        str[len] = av[1][len];
        len++;
    }
    str[len] = '\0';

    sort(str, 0, len);          // primeira permutação em ordem crescente
    printf("%s\n", str);

    while (next_perm(str, len)) // gera todas as próximas permutações
    {
        printf("%s\n", str);
    }

    return 0;
}
