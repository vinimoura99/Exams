# 🏆 42 Exams – Rank 3: Level1 & Level2

**Exam Rank 3** at 42 School is divided into **Level 1** and **Level 2**, focusing on **stdin/stdout handling**, **recursion**, **combinatorics**, **filtering**, and **debugging programs in C**.

> Part of the [vinimoura99/42core](https://github.com/vinimoura99/42core) repository

---

## 📚 Rank 3 Structure

### **Level 1 – I/O and Parsing Fundamentals**
- **Broken GNL** – Debug and fix `get_next_line`.
- **Filter** – Read from stdin and dynamically filter words.
- **Scanf** – Implement input parsing similar to `scanf`.

### **Level 2 – Recursion, Combinatorics, and Algorithms**
- **Nqueens** – Solve the N queens problem using backtracking.
- **Powerset** – Generate all subsets of a given set.
- **Permutations** – Generate all permutations of elements.
- **Tsq** – Task-specific algorithm exercise (TBD).
- **Rip** – System-level programming exercise (TBD).

---

## 🎯 Learning Objectives

**Level 1:**
- Understand reading from stdin using `read()`.
- Process lines **byte by byte** or in blocks.
- Debug `get_next_line` and handle buffers correctly.
- Implement word filters (`filter.c`).
- Manipulate strings without relying on external functions.

**Level 2:**
- Solve problems using **recursion**.
- Understand **backtracking** and generate combinations.
- Implement efficient algorithms for sets and permutations.
- Improve logical problem-solving and code optimization skills.

---

## 📂 Recommended File Structure

Exams/
├── includes/
│ └── exam_utils.h # Utility functions used across exercises
├── src/
│ ├── level1_broken_gnl.c # Level 1 - Broken GNL
│ ├── level1_filter.c # Level 1 - Filter
│ ├── level1_scanf.c # Level 1 - Scanf
│ ├── level2_nqueens.c # Level 2 - Nqueens
│ ├── level2_powerset.c # Level 2 - Powerset
│ ├── level2_permutations.c # Level 2 - Permutations
│ ├── level2_tsq.c # Level 2 - Tsq
│ ├── level2_rip.c # Level 2 - Rip
├── Makefile # Compile all Rank 3 exercises
└── .gitignore # Ignore unnecessary files


---

## 🚀 How to Compile and Run

1. Clone the repository:

```bash
git clone https://github.com/vinimoura99/42core.git
cd 42core/Exams

    Compile all exercises:

make

    Run a sample program:

./level1_filter "word"

    Replace "word" with the word you want to filter from stdin.

🛠️ Implementation Tips

Level 1 – Filter / GNL / Scanf:

    Use read() to handle stdin efficiently.

    For filter, iterate through each line and replace occurrences of the word with *.

    Preserve the newline \n at the end of each line.

    For get_next_line, test with different buffer sizes.

    Debugging tip: always check read() return value and buffer sizes.

Level 2 – Nqueens / Powerset / Permutations:

    Use recursion to generate all combinations.

    For Nqueens, use backtracking to validate positions.

    Powerset: include or exclude each element recursively.

    Permutations: swap elements at each recursion level.

    Avoid memory leaks using malloc and free properly.

📌 Examples

Filter

echo "hello world, hello again" | ./level1_filter hello
# Output: ***** world, ***** again

Powerset

int arr[] = {1,2,3};
powerset(arr, 3);
# Output (all possible subsets):
# [], [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3]

Nqueens

nqueens(4);
# Output:
# ..Q.
# Q...
# ...Q
# .Q..

🧠 Key Concepts

    Efficient I/O: read and write bytes correctly.

    Buffers & Memory: handle malloc/free and dynamic arrays carefully.

    Recursion & Backtracking: essential for Level 2 exercises.

    Debugging: find and fix bugs in GNL, Filter, or Scanf.

    Combinatorics: generate subsets, permutations, and valid solutions.

✅ Completion Checklist

All Level 1 exercises implemented and working.

All Level 2 exercises implemented and working.

Tested with various inputs, buffers, and lines.

No memory leaks.

    Clean, modular, and commented code.

📜 License

This project is part of the 42 School curriculum and is for educational purposes only.
Feel free to explore, study, and contribute!
