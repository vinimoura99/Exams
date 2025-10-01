📝 42 Exams – Rank 3 Cheatsheet

🏆 Levels:
Level 1 – I/O & Parsing Fundamentals

🔧 Broken GNL – Debug and fix get_next_line

🔍 Filter – Read from stdin and replace a word dynamically

📥 Scanf – Implement input parsing similar to scanf

Level 2 – Recursion, Combinatorics & Algorithms

♟️ Nqueens – Solve the N queens problem using backtracking

🔢 Powerset – Generate all subsets of a set

🔄 Permutations – Generate all permutations of elements

🧩 Tsq – Task-specific algorithm exercise (TBD)

⚙️ Rip – System-level programming exercise (TBD)

🎯 Learning Objectives

Level 1:

Read from stdin using read()

Process lines byte by byte or in blocks

Debug get_next_line efficiently

Implement word filtering (filter.c)

Manipulate strings without external functions

Level 2:

Solve problems recursively

Implement backtracking (Nqueens)

Generate combinations and permutations

Optimize algorithms and logic

📂 File Structure

Exams/
├── includes/
│ └── exam_utils.h – Utility functions
├── src/
│ ├── level1_broken_gnl.c
│ ├── level1_filter.c
│ ├── level1_scanf.c
│ ├── level2_nqueens.c
│ ├── level2_powerset.c
│ ├── level2_permutations.c
│ ├── level2_tsq.c
│ ├── level2_rip.c
├── Makefile – Compile all Rank 3 exercises
└── .gitignore

🚀 Compile & Run

1️⃣ Clone repo:
git clone https://github.com/vinimoura99/42core.git
cd 42core/Exams

2️⃣ Compile all exercises:
make

3️⃣ Run example (Filter):
./level1_filter "word"

Replace "word" with your target word from stdin.

🛠️ Implementation Tips

Level 1 – Filter / GNL / Scanf

Use read() for efficient input

Replace words line by line with *

Preserve \n at the end of each line

Test get_next_line with multiple buffer sizes

Always check read() return values

Level 2 – Nqueens / Powerset / Permutations

Recursively generate all combinations/permutations

Backtracking to validate Nqueens positions

Avoid memory leaks: use malloc & free carefully

Swap elements for permutations

📌 Examples

Filter

echo "hello world, hello again" | ./level1_filter hello
Output: ***** world, ***** again

Powerset

int arr[] = {1,2,3};
powerset(arr, 3)
Output: [], [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3]

Nqueens

nqueens(4)
Output:
..Q.
Q...
...Q
.Q..

🧠 Key Concepts

Efficient I/O (read/write)

Buffer management & memory handling

Recursion & backtracking

Debugging and fixing programs

Combinatorics & permutations

✅ Completion Checklist