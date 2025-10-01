*************************************************************************************************
                                Exercicios para testar o Conhecimento
*************************************************************************************************

*************************************************************************************************

☑️ Exercício 1 – Imprimir uma string

Escreva um programa que imprime "Hello, 42!" no stdout usando apenas write.

*************************************************************************************************

☑️ Exercício 2 – Imprimir argumento

Escreva um programa que imprime o primeiro argumento passado (argv[1]), seguido de \n.

*************************************************************************************************

☑️ Exercício 3 – Comparar strings

Escreva uma função ft_strcmp que compara duas strings e retorna 0 se forem iguais, diferente de 0 caso contrário.

*************************************************************************************************

Exercício 4 – Ler do stdin

Escreva um programa que lê até 1024 caracteres do stdin e imprime o que foi lido.

*************************************************************************************************

Exercício 5 – Ler linha por linha

Modifique o programa anterior para ler linha por linha do stdin, e imprimir cada linha assim que lida.

*************************************************************************************************

Exercício 6 – Procurar substring

Escreva uma função ft_strstr que retorna 1 se uma string to_find estiver presente em outra string str, e 0 caso contrário.

*************************************************************************************************

Exercício 7 – Filtrar por palavra fixa

Leia do stdin e imprima apenas as linhas que contêm a palavra "42".

*************************************************************************************************

Exercício 8 – Palavra-chave como argumento

Modifique o exercício anterior para receber a palavra-chave como argumento argv[1] em vez de usar "42" fixa.

*************************************************************************************************

Exercício 9 – Filtrar múltiplas linhas

Teste com várias linhas no stdin. Imprima apenas as linhas que contêm a palavra-chave.

Dica: use loop + sua função ft_strstr.

*************************************************************************************************

Exercício 10 – Filter completo

Crie o programa filter.c final:

Recebe a palavra-chave como argv[1].

Lê do stdin linha por linha.

Imprime apenas as linhas que contêm a palavra-chave.

Usa apenas funções permitidas na 42 (write, read, funções que você mesmo implementou como ft_strstr).

*************************************************************************************************
                               O que cada um faz
*************************************************************************************************


O que cada exercício te ensina e como ajuda no filter

Imprimir uma string → Entender write, que é a função que você vai usar para output.

Imprimir argumento → Entender argc/argv, importante porque a palavra-chave vem de argv[1].

Comparar strings → Base para implementar ft_strstr depois.

Ler do stdin → Saber pegar dados da entrada padrão (read).

Ler linha por linha → Essencial, porque você precisa processar cada linha separadamente.

Procurar substring → Criação da função que vai filtrar linhas.

Filtrar por palavra fixa → Primeiro teste de filtragem real, só com uma palavra hardcoded.

Palavra-chave como argumento → Torna o filtro dinâmico, recebendo a palavra do usuário.

Filtrar múltiplas linhas → Simula como o programa final vai se comportar com stdin real.

Filter completo → Junta tudo: leitura, filtragem e escrita, exatamente o que o projeto pede.