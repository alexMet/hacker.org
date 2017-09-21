# answer is 13061578

ints = [199, 77, 202]
bins = list(map(lambda x: str(bin(x))[2:], ints))
bins[1] = "0" + bins[1]

print (int("0b" + "".join(bins), 2))
