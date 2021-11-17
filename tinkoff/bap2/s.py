import sys

count = 0
text = ""

for line in sys.stdin:
    line = line.strip().lower()
    text += line + " "

if text.count(" the ") > 5:
    print("Petya")
else:
    print("Program")

