#!/bin/python3

# answer is yourgrammarisverygoodthesolutionisnoamchomsky

grammar = {
    'A' : 'is',
    'B' : 'mm',
    'C' : 'oo',
    'D' : 'rgr',
    'E' : 'ryg',
    'F' : 'dth',
    'G' : 'you',
    'H' : 'esol',
    'I' : 'ionA',
    'J' : 'GDaBarA',
    'K' : 'veECFHutI',
    'L' : 'PQ',
    'M' : 'n',
    'N' : 'm',
    'O' : 'oaNcho',
    'P' : 'MO',
    'Q' : 'NR',
    'R' :'sky',
    'S' : 'JKL'
}

def solve(start):
    text = start

    while not text.islower():
        text = "".join(list(map(lambda x: x if x.islower() else grammar[x], text)))

    print (text)

if __name__ == '__main__':
    solve("S")
