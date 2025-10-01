# 📝 Filter – Assignment

**Expected file:** `filter.c`  
**Allowed functions:** `read, malloc, free, realloc, write, printf, strlen`

---

## 🔹 Objetivo

Criar um programa que:

- Lê texto da entrada padrão (`stdin`).
- Substitui **todas as ocorrências exatas** de uma palavra `<word_to_filter>` por asteriscos (`*`) da mesma quantidade de caracteres.
- Mantém o restante do texto **inalterado**.
- Processa cada linha **imediatamente** após ler.
- Substituição **case-sensitive** (ex.: `"abc"` ≠ `"ABC"`).
- Substitui palavras mesmo se embutidas em outras palavras.
- Preserva `\n` no final de cada linha.

---

## 🔹 Uso

```bash
./filter <word_to_filter>
