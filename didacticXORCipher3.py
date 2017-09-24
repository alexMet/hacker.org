import string

# answer is fiendster

def isPrintable(txt):
    return (all(c in string.printable for c in txt))

def decipher(cipher):
    for b in range(256):
        for x in range(256):
            key = b
            ans = ""

            for i in range(0, len(cipher), 2):
                ans += chr(int(cipher[i] + cipher[i + 1], base=16) ^ key)
                key = (key + x) % 256

            if isPrintable(ans):
                print (ans)


if __name__ == "__main__":
    cipher = "31cf55aa0c91fb6fcb33f34793fe00c72ebc4c88fd57dc6ba71e71b759d83588"
    decipher(cipher)
