#!/bin/python3

# we compare (https://text-compare.com/) the given text with 
# the original text (http://creepypasta.wikia.com/wiki/Bram_Stoker%27s_%27Dracula%27/Chapter_3)
# and we see a difference with the upper case letters, so we only pick them
# and the answer is sunshine

def solve():
    f = open("vampire.txt", "r")
    t = f.read()

    print ("".join([x for x in t if x.isupper()]))

if __name__ == "__main__":
    solve()
