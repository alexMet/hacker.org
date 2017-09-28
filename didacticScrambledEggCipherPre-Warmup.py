import string

# [51, 75, 236, 171] i'm gonna start off with a nice piece of text. 'A guy told me he liked cherries...but... 
# I waited to see if he was gonna say tomato...before I realized he likes cherries just...alright, that joke is
# ridiculous. That's like a carbon copy of the previous joke but with different ingredients. I don't know what 
# I was trying to pull off there.' okay, the answer would be the last name of the author of that quote. yes, you may need to Google it.

def cipherthis(plain):
    keys = [100, 90, 80, 70]
    mask = (1 << 24) - 1
    charMask = 0b1111111100000000
    eggs = ord(plain[0]) * 256 * 256 + ord(plain[1]) * 256 + ord(plain[2])

    print ("plain", plain)
    print ("int",   eggs)
    print ("hex",   hex(eggs))

    for j in range(3):
        k     = eggs & 0x3
        eggs ^= (keys[k] << 8)
        eggs  = (eggs << 7) | (eggs >> 17)
        eggs &= mask

    print ("\ncipher")
    print ("int", eggs)
    print ("hex", hex(eggs))
    
    eggs = str(hex(eggs))[2:]
    cipher = bytes.fromhex(eggs)
    eggs = cipher[0] * 256 * 256 + cipher[1] * 256 + cipher[2]

    for j in range(3):
        eggs  = (eggs >> 7) | (eggs << 17)
        k     = eggs & 0x3
        eggs ^= (keys[k] << 8)
        eggs &= mask

    print ("\nplain")
    print ("int", eggs)
    print ("hex", hex(eggs))

def decipher(cipher):
    # cipher   = "382d817119a1884486"
    cipher   = bytes.fromhex(cipher)
    keys     = [0, 0, 0, 0]
    mask     = (1 << 24) - 1
    charMask = 0b1111111100000000

    while True:
        ans = ""
        flag = False

        for i in range(0, len(cipher), 3):
            eggs = cipher[i] * 256 * 256 + cipher[i + 1] * 256 + cipher[i + 2]

            for j in range(3):
                eggs  = (eggs >> 7) | (eggs << 17)
                k     = eggs & 0x3
                eggs ^= (keys[k] << 8)
                eggs &= mask

            m = 0b111111110000000000000000           
            for j in range(3):
                l = chr((eggs & m) >> ((2 - j) * 8))
                m = m >> 8

                if l not in string.printable:
                    flag = True
                    break    
                
                ans += l

            if flag:
                keys[3] += 1
                break
        
        if not flag:
            keys[3] += 1
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
    cipher = """382d817119a18844865d880255a8221d90601ad164e8a8e1dd8a48f45846152255f839e09ab176154244faa95513d16e5e314078a97fdb8bb6da8d5615225695225674a4001a9177fb112277c45e17f85753c504d7187ed3cd43b107803827e09502559bf164292affe8aaa8e88ac898f9447119a188448692070056a2628864e6d7105edc5866b9b9b6ebcad6dc3982952a7674a62015025695225674a400d8715efb112277c45edb799f9728355c586f95b002e8aa815b83df3704571b99b6346426bd9862920721751857cb38f69bb3dee18ce1793bc857e27f74a400dd8a48d971bc15d07f521921b80948a86a8eb70457d1138279a796b8fbc43d9801e8ead669c8dcb10781788b5fe91097bad104d9ab952190a15ae706b50477b8dbe4d3cd437119c12842a42190e1a868aeb76446588d52b1078057e27cf7c65fa84aae5b8bbf6b88c19b9176a94a8eb7045778513712f1679b655d9c0255e88ac889b882b8f104711ba1dbabd7120520e188e195225655a802c184a0282affa86a8eb70457120542f7187658515f154244548a4212074278e7c6d3cd4595283e3d9a61d8ad56ba294878c5e69502551bf162487886280aff7b3309"""
    decipher(cipher)
    #cipherthis("abc")
