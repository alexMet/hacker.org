#!/bin/bash

# First we run the program at http://www.hacker.org/hvm/
# and we get an !ERROR: illegal value after the first "0<" because there is nothing at cell-0
# we initialize that cell with a zero and we get !ERROR: too many cycles, so we download
# the hackvm.py and change the circles

echo "79+3>111++<9+3>0<1+0>999**0<:6?084*-g1111++*<p" > p
python hackvm.py p

# after that we get the following error
# !ERROR: exception while executing I=< PC=16 STACK_SIZE=1
# too many cycles
# so we add another 0 to the MAX_CYCLES and we run it again

python hackvm.py p

# and the answer is 6577
