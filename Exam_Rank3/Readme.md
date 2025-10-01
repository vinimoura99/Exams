# 🏆 42 Exam Rank 3 – C Programming Fundamentals

This repository contains the solutions and exercises for **Exam Rank 3** at **42 School**. This exam focuses on intermediate C programming concepts, divided into two main levels: **Level 1 (I/O and Parsing)** and **Level 2 (Recursion, Combinatorics & Algorithms)**.

Part of the larger `vinimoura99/42core` repository, this collection demonstrates proficiency in core C data structures, efficient input/output handling, and classic algorithmic problem-solving.

---

## 🚀 Key Concepts & Focus Areas

The exercises are designed to test a candidate's understanding of the following essential C programming techniques:

### **Level 1: I/O and Parsing Fundamentals**
* **Efficient I/O:** Reading from `stdin` and writing to `stdout` using low-level functions (`read`/`write`).
* **String Manipulation:** Line-by-line processing, word filtering, and dynamic string handling.
* **Debugging:** Identifying and fixing issues in complex library functions (e.g., `get_next_line`).

### **Level 2: Recursion, Combinatorics & Algorithms**
* **Recursion & Backtracking:** Solving complex search problems (e.g., N-Queens).
* **Combinatorics:** Generating all subsets (Power Set) and permutations of a given set.
* **Algorithm Optimization:** Implementing efficient logic for exam-specific tasks.
* **System-Level Logic:** Exercises requiring basic system programming knowledge (`Rip`).

---

## 🛠️ Project Structure and Exercises

The exam is broken down into specific tasks across two difficulty levels.

### **Level 1 – I/O and Parsing Fundamentals**

| Exercise | Description | Focus |
| :--- | :--- | :--- |
| **Broken GNL** | Debug and fix a broken implementation of `get_next_line`. | File Descriptor I/O, Debugging |
| **Filter** | Read a stream from `stdin` and dynamically filter words based on given criteria. | Stdin/Stdout Handling, Filtering |
| **Scanf** | Implement a function that mimics the input parsing behavior of `scanf`. | Input Parsing, String Tokenization |

### **Level 2 – Recursion, Combinatorics & Algorithms**

| Exercise | Description | Focus |
| :--- | :--- | :--- |
| **Nqueens** | Solve the classic N-Queens problem using a **backtracking** algorithm. | Recursion, Backtracking |
| **Powerset** | Generate all possible **subsets** of a given set of elements. | Combinatorics, Recursion |
| **Permutations** | Generate all possible **permutations** of elements in a set. | Combinatorics, Recursion |
| **Tsq** | A **Task-Specific Algorithm** exercise defined by the exam. | Algorithmic Problem Solving |
| **Rip** | A **System-Level Programming** exercise defined by the exam. | System Calls, Low-Level Logic |

---

## 📂 Recommended File Structure

To maintain clarity and adherence to the 42 standards, the repository is organized as follows:

```

.
├── Level1/
│   ├── broken\_gnl.c
│   ├── filter.c
│   └── scanf\_like.c
├── Level2/
│   ├── nqueens.c
│   ├── powerset.c
│   ├── permutations.c
│   ├── tsq.c
│   └── rip.c
└── README.md

```
```
