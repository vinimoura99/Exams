# 📚 Exercícios de Prática – permutations (Permutação de Strings)

---

## ☑️ Exercício 1 – Medir String
**Nome:** `ft_strlen.c`  
**Objetivo:** Implementar a função `int ft_strlen(char *s)` que retorna o comprimento da string `s` (sem contar o `\0`).

---

## ☑️ Exercício 2 – Impressão Final
**Nome:** `ft_putstr_nl.c`  
**Objetivo:** Implementar a função `void ft_putstr_nl(char *s)` que imprime a string `s` seguida de um `\n` usando apenas `write`.

---

## ☑️ Exercício 3 – Alocação e Cópia
**Nome:** `ft_strdup.c`  
**Objetivo:** Implementar `char *ft_strdup(char *s1)` que aloca memória com `malloc` e copia `s1` para essa nova área. Retorna o ponteiro.

---

## ☑️ Exercício 4 – Troca de Caracteres
**Nome:** `ft_swap_char.c`  
**Objetivo:** Implementar a função `void ft_swap_char(char *a, char *b)` que troca os valores apontados por `a` e `b`.

---

## ☑️ Exercício 5 – Estrutura Principal e free
**Nome:** `main_setup.c`  
**Objetivo:** Criar a função `main` que:
- Valida se recebeu exatamente **um argumento** (`argc == 2`).
- Usa `ft_strdup` para alocar uma cópia de `argv[1]`.
- Libera a memória com `free` antes de sair.

---

## ☑️ Exercício 6 – Ordenação Alfabética
**Nome:** `ft_sort_string.c`  
**Objetivo:** Implementar `void ft_sort_string(char *s)` que ordena os caracteres da string `s` em ordem alfabética crescente (utilizando `ft_swap_char`).

---

## ☑️ Exercício 7 – Estrutura de Recursão
**Nome:** `ft_recursive_base.c`  
**Objetivo:** Implementar uma função recursiva simples (ex: imprimir números) para praticar **caso base** e **passo recursivo**.

---

## ☑️ Exercício 8 – Esqueleto do Permutador
**Nome:** `ft_permute_skeleton.c`  
**Objetivo:** Criar o esqueleto da função `void ft_permute(char *str, int index, int len)`; no caso base (`index == len`) imprimir a string.

---

## ☑️ Exercício 9 – O Backtracking
**Nome:** `ft_permute_backtrack.c`  
**Objetivo:** Completar a função `ft_permute` com a lógica de **troca → chamada recursiva → restauração** (swap, recursão, swap de volta) para gerar todas as permutações.

---

## ☑️ Exercício 10 – O Programa Final
**Nome:** `permutations.c`  
**Objetivo:** Criar o programa final que:
- Valida `argc`.
- Usa `malloc` e `ft_sort_string`.
- Chama `ft_permute` a partir do índice `0`.
- Dá `free` antes de sair.

---

## 📝 O que cada exercício ensina

- **Exercícios 1–4** – Ferramentas essenciais: comprimento da string, saída com `write`, `malloc` e a operação de troca.  
- **Exercícios 5–6** – Gestão de memória (`free`) e ordenação para garantir saída alfabética.  
- **Exercícios 7–9** – Estrutura recursiva e o algoritmo de **backtracking** (coração do projeto).  
- **Exercício 10** – Integração final e conformidade do programa.

---