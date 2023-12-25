import sys

total = 0
for line in sys.stdin:
    line = line.replace("one", "o1e")
    line = line.replace("two", "t2o")
    line = line.replace("three", "th3ee")
    line = line.replace("four", "fo4r")
    line = line.replace("five", "fi5e")
    line = line.replace("six", "s6x")
    line = line.replace("seven", "se7en")
    line = line.replace("eight", "ei8ht")
    line = line.replace("nine", "n9ne")
    d = []
    for c in line:
        if c.isdigit():
            d.append(int(c))
    print(d[0] * 10 + d[-1])
    total += d[0] * 10 + d[-1]
print(total)
