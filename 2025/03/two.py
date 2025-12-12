import sys

s = 0
for l in sys.stdin:
    drop, st = len(l) - 12, []
    for c in l.rstrip():
        while drop and st and st[-1] < c:
            st.pop()
            drop -= 1
        st.append(c)
    s += int(''.join(st[:12]))
print(s)
