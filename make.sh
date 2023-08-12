#!/bin/bash
clear && betty *.c *.h && gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh && ./hsh
