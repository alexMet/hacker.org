#!/bin/python

# answer is random seed

def main():
    cipher = "3d2e212b20226f3c2a2a2b"
    key = 79
    ans = ""

    for i in range(0, len(cipher), 2):
        ans += chr(int(cipher[i] + cipher[i + 1], base=16) ^ key)

    print (ans)

if __name__ == '__main__':
    main()
