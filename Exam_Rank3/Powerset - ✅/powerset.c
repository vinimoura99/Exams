/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_solution(int *path, int path_len)
{
    int i = 0;
    while(i < path_len)
    {
        if(i > 0)
            printf(" ");
        printf("%i",path[i]);
        i++;
    }
    printf("\n");
}

// A função recursiva de Powerset/Subset Sum
void powerset(int *array, int array_len, int target, int idx, int sum, int *path, int path_len)
{
    // Caso base: Se processamos todos os elementos (idx == array_len)
    if(idx == array_len)
    {
        // Se a soma atual é igual ao alvo, imprimimos a solução
        if(sum == target)
        {
            print_solution(path, path_len);
        }        
        return; // IMPORTANTE: Sair da recursão
    }
        
    // 1. Não incluir o elemento atual (array[idx]):
    // Avançamos para o próximo índice (idx + 1) sem mudar a soma ou o caminho
    powerset(array, array_len, target, idx + 1, sum, path, path_len);

    // 2. Incluir o elemento atual (array[idx]):
    // Adicionamos o elemento ao caminho temporário
    path[path_len] = array[idx];
    
    // Avançamos para o próximo índice (idx + 1), atualizamos a soma e o tamanho do caminho
    powerset(array, array_len, target, idx + 1, sum + array[idx], path, path_len + 1);
}

int main(int ac, char **av)
{
    if (ac >= 3) // Pelo menos ./powerset TARGET NUM1
    {
        // Variáveis: target é av[1], array começa em av[2]
        int target = atoi(av[1]);
        int array_len = ac - 2;
        
        // Alocações
        int *array = (int*)malloc(sizeof(int) * array_len);
        int *path = (int*)malloc(sizeof(int) * array_len);

        if(!path || !array)
        {
            free(array); // Free seguro
            free(path);
            return(1);
        }
        
        // Preenche o array com os números a partir de av[2]
        for(int i = 0; i < array_len; i++)
            array[i] = atoi(av[i + 2]);
        
        // Inicia a busca pelo Powerset/Subset Sum
        powerset(array, array_len, target, 0, 0, path, 0);

        free(array);
        free(path);
        return(0);
    }
    // Caso de uso: ./powerset (ac=1) ou ./powerset 3 (ac=2)
    else 
    {
        // Se o número de argumentos não for suficiente para rodar o teste
        return(1);
    }
} */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_list(int *path, int path_len)
{
    int i = 0;
    while(i < path_len)
    {
        if(i > 0)
            printf(" ");
        printf("%i",path[i]);
        i++;
    }
    printf("\n");
}

void powerset(int *array, int len, int target, int idx, int sum , int *path, int path_len)
{
    if(len == idx)
    {
        if(sum == target)
        {
            print_list(path,path_len);
        }
        return;
    }

    powerset(array,len,target,idx + 1,sum ,path,path_len);
    path[path_len] = array[idx];
    powerset(array,len,target,idx + 1,sum + array[idx],path,path_len + 1);

}

int main(int ac , char **av)
{
    if(ac >= 3)
    {
        int target = atoi(av[1]);
        int len = ac - 2;

        int *array = malloc(sizeof(int) * len);
        int *path = calloc(len,sizeof(int));

        if(!path || !array)
            return(1);
        
        int i = 0;
        while(i < len)
        {
            array[i] = atoi(av[i + 2]);
            i++;
        }

        powerset(array,len,target,0,0,path,0);
        free(array);
        free(path);
        return(0);
    }
    else
        return(1);
}