#!/bin/bash

# Corrector for 2d_array
# Tests if the program cria e manipula arrays 2D

echo "=== CORRECTOR: 2d_array ==="
echo

# Compile the program
if ! gcc -Wall -Wextra -Werror -o 2d_array 2d_array.c 2>/dev/null; then
    echo "❌ ERROR: Compilation failed"
    exit 1
fi

echo "✅ Compilation successful"
echo

# Test [0-9]: Array 3x3
echo "Test [0-9]: Array 3x3"
if ./2d_array 3 > output1.txt 2>/dev/null; then
    expected="0 1 2
1 2 3
2 3 4"
    if [ "$(cat output1.txt)" = "$expected" ]; then
        echo "✅ Test [0-9] PASSED"
    else
        echo "❌ Test [0-9] FAILED: Incorrect output"
        echo "Esperado:"
        echo "$expected"
        echo "Obtido:"
        cat output1.txt
    fi
else
    echo "❌ Test [0-9] FAILED: Execution error"
fi

# Test [0-9]: Array 2x2
echo "Test [0-9]: Array 2x2"
if ./2d_array 2 > output2.txt 2>/dev/null; then
    expected="0 1
1 2"
    if [ "$(cat output2.txt)" = "$expected" ]; then
        echo "✅ Test [0-9] PASSED"
    else
        echo "❌ Test [0-9] FAILED: Incorrect output"
    fi
else
    echo "❌ Test [0-9] FAILED: Execution error"
fi

# Test [0-9]: Tamanho zero
echo "Test [0-9]: Tamanho zero"
if ./2d_array 0 >/dev/null 2>/dev/null; then
    echo "❌ Test [0-9] FAILED: Should return error"
else
    echo "✅ Test [0-9] PASSED"
fi

# Cleanup
rm -f output1.txt output2.txt 2d_array

echo
echo "=== END OF TESTS ==="