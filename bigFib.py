#!/bin/python

# answer is 1161269686625383

def main():
    f = 1
    s = 1

    for i in range(2, 1500000):
        tmp = f + s
        f = s
        s = tmp

    print (str(s)[::20000])


if __name__ == '__main__':
    main()
