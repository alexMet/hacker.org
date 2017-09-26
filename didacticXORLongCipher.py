import string

# [211, 30, 44, 240] This cipher has a key of four bytes. For this one your answer is Papua. Congratulations on your discovery! 

def decipher(cipher):
    cipher = bytes.fromhex(cipher)
    keys = [0, 0, 0, 0]

    while True:
        ans = ""
        flag = False

        for i in range(len(cipher)):
            k = i % 4
            c = chr(cipher[i] ^ keys[k])

            if c not in string.printable:
                keys[k] += 1
                flag = True
                break

            ans += c

        if not flag:
            keys[3] += 1

            if "answer" in ans:
                print (keys, ans)

        if keys[3] > 255:
            keys[3] = 0
            keys[2] += 1
        if keys[2] > 255:
            keys[3] = 0
            keys[2] = 0
            keys[1] += 1
        if keys[1] > 255:
            keys[3] = 0
            keys[2] = 0
            keys[1] = 0
            keys[0] += 1
        if keys[0] > 255:
            break


if __name__ == "__main__":
    cipher = "8776459cf37d459fbb7b5ecfbb7f5fcfb23e478aaa3e4389f378439aa13e4e96a77b5fc1f358439df36a4486a03e4381b63e5580a66c0c8ebd6d5b8aa13e459cf34e4d9fa67f02cf90714288a17f589abf7f5886bc705fcfbc700c96bc6b5ecfb7775f8cbc68499daa3f"
    decipher(cipher)
