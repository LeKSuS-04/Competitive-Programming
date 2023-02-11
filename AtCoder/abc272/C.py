''' C - Max Even '''
# https://atcoder.jp/contests/abc272/tasks/abc272_c
# Date: 2022-10-08 15:16:48
# Run time: 110 ms
# Memory: 32104 KB
# Verdict: AC

input()
a = list(map(int, input().split()))

me1, me2, mo1, mo2 = (-1 for _ in range(4))
for c in a:
    if c % 2 == 0:
        if c > me1:
            me2 = me1
            me1 = c
        elif c > me2:
            me2 = c
    if c % 2 == 1:
        if c > mo1:
            mo2 = mo1
            mo1 = c
        elif c > mo2:
            mo2 = c

if all(-1 in t for t in [(me1, me2), (mo1, mo2)]):
    print(-1)
else:
    print(max(me1 + me2, mo1 + mo2, -1))