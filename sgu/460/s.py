n = int(input())
for i in range(n):
    s = input()
    if s[-2:] == "ch" or s[-1] in { "x", "s", "o" }:
        s += "es"
    elif s[-2:] == "fe":
        s = s[:-2] + "ves"
    elif s[-1] == "f":
        s = s[:-1] + "ves"
    elif s[-1] == "y":
        s = s[:-1] + "ies"
    else:
        s += "s"
    print(s)
