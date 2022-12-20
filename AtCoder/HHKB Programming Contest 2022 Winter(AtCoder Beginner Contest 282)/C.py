''' C - String Delimiter '''
# https://atcoder.jp/contests/abc282/tasks/abc282_c
# Date: 2022-12-17 15:06:48
# Run time: 60 ms
# Memory: 10720 KB
# Verdict: AC

_ = input()
s = list(input())

enclosed = False
for i, c in enumerate(s):
    if c == '"':
        enclosed = not enclosed
    elif c == ',' and not enclosed:
        s[i] = '.'

print(''.join(s))
