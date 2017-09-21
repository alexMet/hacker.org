#!/bin/bash

# we get the size of the image after running the next command

identify redline.png 
# redline.png PNG 4x1 4x1+0+0 8-bit sRGB 141B 0.000u 0:00.000

convert redline.png -crop '4x1+0+0' txt:-
# 0,0: (222,0,0)  #DE0000  srgb(222,0,0)
# 1,0: (250,0,0)  #FA0000  srgb(250,0,0)
# 2,0: (206,0,0)  #CE0000  srgb(206,0,0)
# 3,0: (209,0,0)  #D10000  srgb(209,0,0)

# we get the colors of the pixels and the answer is DEFACED1
