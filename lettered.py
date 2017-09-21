#!/bin/python3
from html import *

# with the first unescape we get
# '&weierp;&Otilde;&Ugrave;&real;&copy;&Theta;&fnof;&fnof;&isin;&isin;'
# and with the second one
# '℘ÕÙℜ©Θƒƒ∈∈'
# so the answer is 'pourcoffe'

def solve():
    text = "&#38&#119&#101&#105&#101&#114&#112&#59&#38&#79&#116&#105&#108&#100&#101&#59&#38&#85&#103&#114&#97&#118&#101&#59&#38&#114&#101&#97&#108&#59&#38&#99&#111&#112&#121&#59&#38&#84&#104&#101&#116&#97&#59&#38&#102&#110&#111&#102&#59&#38&#102&#110&#111&#102&#59&#38&#105&#115&#105&#110&#59&#38&#105&#115&#105&#110&#59"

    print (unescape(unescape(text)))

if __name__ == "__main__":
    solve()
