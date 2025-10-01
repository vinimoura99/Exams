# 📚 Exercícios de Prática – 42

---

## ☑️ Exercício 1 – Imprimir uma string
**Objetivo:** Imprimir `"Hello, 42!"` no stdout usando apenas `write`.

---

## ☑️ Exercício 2 – Imprimir argumento
**Objetivo:** Imprimir o primeiro argumento passado (`argv[1]`), seguido de `\n`.

---

## ☑️ Exercício 3 – Comparar strings
**Objetivo:** Implementar `ft_strcmp` que retorna `0` se duas strings forem iguais, diferente de `0` caso contrário.

---

## ☑️ Exercício 4 – Ler do stdin
**Objetivo:** Ler até 1024 caracteres do stdin e imprimir o que foi lido.

---

## ☑️ Exercício 5 – Ler linha por linha
**Objetivo:** Modificar o programa anterior para ler linha por linha e imprimir cada linha assim que lida.

> 💡 **Atenção às diferenças entre os exercícios 4 e 5**

| Caso | Como lê | O que `idx/n` guarda | Como processa | Uso típico |
|------|---------|--------------------|---------------|------------|
| **Buffer grande** (`read(0, buffer, 1024)`) | Até 1024 bytes de uma vez | Quantos bytes foram realmente lidos (0 a 1024) | Precisa percorrer `buffer` se quiser tratar caractere por caractere | Eficiente para blocos grandes, arquivos, streams |
| **Byte a byte** (`read(0, &line_letter, 1)`) | 1 byte por vez | 1 se leu, 0 se EOF, -1 se erro | Pode reagir imediatamente a cada caractere (ex: parar no `\n`) | Útil para ler linha por linha ou processar input interativo |

---

## ☑️ Exercício 6 – Procurar substring
**Objetivo:** Implementar `ft_strstr` que retorna `1` se `to_find` estiver presente em `str`, e `0` caso contrário.

---

## ☑️ Exercício 7 – Filtrar por palavra fixa
**Objetivo:** Ler do stdin e imprimir apenas as linhas que contêm a palavra `"42"`.

---

## ☑️ Exercício 8 – Palavra-chave como argumento
**Objetivo:** Modificar o exercício anterior para receber a palavra-chave como `argv[1]` em vez de `"42"` fixa.

---

## ☑️ Exercício 9 – Filtrar múltiplas linhas
**Objetivo:** Testar com várias linhas no stdin e imprimir apenas as linhas que contêm a palavra-chave.  
**Dica:** use loop + sua função `ft_strstr`.

---

## ☑️ Exercício 10 – Filter completo
**Objetivo:** Criar o programa `filter.c` final:
- Recebe a palavra-chave como `argv[1]`
- Lê do stdin linha por linha
- Imprime apenas as linhas que contêm a palavra-chave
- Usa apenas funções permitidas na 42 (`write`, `read`, funções próprias como `ft_strstr`)

---

## 📝 O que cada exercício ensina

- **Exercício 1** – Entender `write` para output.  
- **Exercício 2** – Entender `argc/argv` (importante para palavra-chave).  
- **Exercício 3** – Base para implementar `ft_strstr`.  
- **Exercício 4** – Saber ler dados da entrada padrão (`read`).  
- **Exercício 5** – Processar cada linha separadamente.  
- **Exercício 6** – Criar função de busca de substring.  
- **Exercício 7** – Teste inicial de filtragem com palavra fixa.  
- **Exercício 8** – Filtragem dinâmica via argumento do usuário.  
- **Exercício 9** – Simular comportamento real do stdin com múltiplas linhas.  
- **Exercício 10** – Juntar tudo: leitura, filtragem e escrita, como no projeto final.

---

