import string

# answer is cornishpasty 

def isPrintable(txt):
    return (all(c in string.printable for c in txt))

def decipher(cipher):
    for x in range(256):
        for b in range(256):
            ans = ""
            k = b

            for l in bytes.fromhex(cipher):
                ans += chr(l ^ k)
                k = (l + x) % 0x100

            if isPrintable(ans):
                print (ans)


if __name__ == "__main__":
    cipher = "310a7718781f734c31425e775a314f3b40132c5122720599b2dfb790fd8ff894add2a4bdc5d1a6e987a0ed8eee94adcfbb94ee88f382127819623a404d3f"
    decipher(cipher)
