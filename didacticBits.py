#!/bin/python3

# the answer is adumbrate

def decipher(c, a, b):
    c = c.replace("b", b).replace("a", a)
    ans = ""

    for i in range(0, len(c), 8):
        ans += chr(int(c[i:(i + 8)], 2))

    print (ans)

def main():
    cipher = "abbbabaaabbabaaaabbaababaabaaaaaabbaaaababbab" + \
        "bbaabbbaabbabbbabbbabbaabababbbaabaaabaaaaaab" + \
        "babaababbbaabbaabaaaaaabbaaaababbaabaaabbbaba" + \
        "babbabbababbaaabaabbbaabaabbaaaababbbabaaabbaabab"
    decipher(cipher, "0", "1")
    #decipher(cipher, "1", "0")

if __name__ == "__main__":
    main()
