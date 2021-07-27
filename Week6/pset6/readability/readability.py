from cs50 import get_string


def main():
    text = get_string("Text: ")
    check(text)


def check(texts):
    letters = 0
    text = 1
    sentence = 0
    for i in (texts):
        if(i == " "):
            text += 1
        elif(i == "!" or i == "." or i == "?"):
            sentence += 1
        elif((i != " ") and (i != ",") and (i != ":") and (i != "?") and (i != '"') and (i != "'")):
            letters += 1
    L = (letters / text) * 100
    S = (sentence / text) * 100
    redability = 0.0588 * L - 0.296 * S - 15.8
    if(redability < 0):
        print("Before Grade 1")
    elif(redability > 16):
        print("Grade 16+")
    else:
        print("Grade ", round(redability))


main()