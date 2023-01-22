#!/bin/bash
mkdir ..liball.so.d
cd ..liball.so.d
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -c -fPIC ../*.c
cd ..
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -shared ..liball.so.d/*.o -o liball.so
rm -R ..liball.so.d
