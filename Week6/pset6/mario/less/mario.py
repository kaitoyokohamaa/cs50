from cs50 import get_int


def main():
    t = get_positive_int()
    for i in range(t):
        for f in range(t-i-1):
            print(" ", end="")
        for j in range(i+1):
            print("#", end="")
        print("")


def get_positive_int():
    while True:
        n = get_int("Positive Integer: ")
        if (n > 0) and (n < 9):
            break
    return n


main()