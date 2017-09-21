#!/bin/bash

# sudo apt install gnat
# answer is 0.119355 0.254839

gnat make testran.adb
./testran
rm -f *.ali *.o testran
