from cs50 import get_float


def calcCash():
    while True:
        n = get_float("Change owed:")
        if (n > 0):
            break
    cents = n * 100
    coin = 0
    while True:
        if cents >= 25:
            coin += 1
            cents -= 25

        elif (cents >= 10) and (cents < 25):
            coin += 1
            cents -= 10
        elif (cents >= 5) and (cents < 10):
            coin += 1
            cents -= 5

        elif (cents >= 1) and (cents < 5):
            coin += 1
            cents -= 1

        if cents == 0:
            return coin


print(calcCash())
