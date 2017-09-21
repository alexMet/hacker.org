#!/bin/python3

from PIL import Image

# answer is 10245318

def get8bit(c):
    cbin = str(bin(c))[2:]
    return "0" * (8 - len(cbin)) + cbin

def solver():
    im = Image.open("didactrgb.png")
    im.getpixel((0, 0))
    r, g, b = im.getpixel((0, 0))

    print (int("0b" + get8bit(r) + get8bit(g) + get8bit(b), 2))

    im.close()

if __name__ == "__main__":
    solver()
