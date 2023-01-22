#!/bin/bash

# Create an empty array to store all the .c files in the current directory
files=()

# Find all the .c files in the current directory and add them to the array
for file in $(ls *.c); do
    files+=("$file")
done

# Compile all the .c files into a dynamic library called liball.so
gcc -shared -o liball.so ${files[@]}

echo "Dynamic library liball.so created successfully."
