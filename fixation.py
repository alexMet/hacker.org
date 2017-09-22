from PIL import Image

# answer is snugglefish

def solve():
    frame = Image.open("swirl.gif")
    nframes = 0

    while True:
        nframes += 1

        try:
            frame.seek(nframes)
            frame.show()
        except EOFError:
            break

if __name__ == "__main__":
    solve()
